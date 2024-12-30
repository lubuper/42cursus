import { saveMatchHistory } from './components/pages/Dashboard.js';
import {
	getOtherPlayer,
	getSelectedGameID,
	getSenderPlayer,
} from "./components/pages/RemotePlay.js";
import {navigate} from "./helpers/App.js";

let thisUser = null;
let ballController = null;
let ballSpector = null;
let gameAbandoned = false;
let gameFinished = false;
let isWaiting = false;
let midGame = false;
let flagFirstUser = false;
let gameRejected = false;

let waitingModal = document.createElement('div');

function getCSRFToken() {
	const name = 'csrftoken';
	const cookies = document.cookie.split(';');
	for (let cookie of cookies) {
		const trimmedCookie = cookie.trim();
		if (trimmedCookie.startsWith(name + '=')) {
			return decodeURIComponent(trimmedCookie.substring(name.length + 1));
		}
	}
	return null;
}

export async function findReceiver(gameId) {
	const response = await fetch('/find-receiver/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'X-CSRFToken': getCSRFToken() // Ensure CSRF token is sent
		},
		body: JSON.stringify({
			'game_id': gameId
		}),
	})

	if (response.ok) {
		const resultGame = await response.json();
		return (resultGame);
	}
	else {
		return ('null');
	}
}

export async function finishInvitation(sender, receiver, gameId) {
	const response = await fetch('/finish-game-invitation/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'X-CSRFToken': getCSRFToken() // Ensure CSRF token is sent
		},
		body: JSON.stringify({
			'username': receiver,
			'game_id': gameId
		}),
	})

	if (response.ok) {
		const resultGame = await response.json();
		return (resultGame);
	}
}

export async function finishRank(sender, gameId) {
	const response = await fetch('/finish-game-rank/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'X-CSRFToken': getCSRFToken() // Ensure CSRF token is sent
		},
		body: JSON.stringify({
			'game_id': gameId
		}),
	})

	if (response.ok) {
		const resultGame = await response.json();
		return (resultGame);
	}
}

class Game {
	constructor() {
		this.isRunning = true;
		this.env = null;
		this.renderer = new THREE.WebGLRenderer({
			antialias: true,
			alpha: true,
			physicallyCorrectLights: true,
			toneMapping: THREE.ACESFilmicToneMapping,
			toneMappingExposure: 1.0,
			gammaFactor: 2.2,
			gammaOutput: true,
			outputEncoding: THREE.sRGBEncoding
		});
		this.listener = new THREE.AudioListener();
		this.audioLoader = new THREE.AudioLoader();
		this.scene = new THREE.Scene();
		this.loader = new THREE.TextureLoader();
		this.fbxloader = new THREE.FBXLoader();
		this.aspectRatio = window.innerWidth / window.innerHeight;
		this.boundaryX = 40 * this.aspectRatio;
		this.boundaryY = 40;
		this.camerap1 = new THREE.PerspectiveCamera(50, this.aspectRatio, 0.1, 1000);
		this.camerap2 = new THREE.PerspectiveCamera(50, this.aspectRatio, 0.1, 1000);
		this.cameratop3 = new THREE.PerspectiveCamera(50, this.aspectRatio, 0.1, 1000);
		this.cameratop3.add(this.listener);
		this.keysPressed = {};
		this.animationFrameID;
		this.cameratoggle = 2;
		this.initialpos = new THREE.Vector3(0, 0, 0);
		this.player1;
		this.player2;
		this.ship1;
		this.ship2;
		this.ship1Number = 1; // Player 1 ship - change here
		this.ship2Number = 4;  // Player 2 ship - change here
		this.geometry_player1;
		this.geometry_player2;
		this.playingSurface = null;
		this.geox = 5;
		this.geoy = 2.8;
		this.geoz = 0.1;
		this.maxY;
		this.minY;
		this.maxX;
		this.minX;
		this.moon;
		this.sun;
		this.sunLight;
		this.sunMaterial;
		this.ball;
		this.barrier
		this.ballLastPosition;
		this.hexagons;
		this.hexagoncolor = 0x00ff00; // color change here
		this.hexGroup = new THREE.Group();
		this.planetEarth;
		this.shake = 0;
		this.scorePlayer1 = 0;
		this.scorePlayer2 = 0;
		this.scoreboard = [];
		this.lastDirection = 0;
	}

	async fetchShipAndColorRemote() {
		let otherUser = ballSpector;
		if (flagFirstUser === false) {
			otherUser = ballController;
		}
		try {
			const response = await fetch('/api/get-ship-and-color-remote/', {
				method: 'POST',
				headers: {
					'Content-Type': 'application/json',
					'X-CSRFToken': getCSRFToken() // Ensure CSRF token is sent
				},
				body: JSON.stringify({
					'username_guest': otherUser // Send the username in the request body
				}),
			})
			if (!response.ok) {
				throw new Error('Failed to fetch ship and color');
			}
			const data = await response.json();
			this.ship1Number = data.ship_player_one;
			this.ship2Number = data.ship_player_two;
			this.hexagoncolor = data.color;
			thisUser = data.username;
			flagFirstUser = false;
		} catch (error) {
			// console.log('Error fetching ship and color:', error);
		}
	}

	init () {
		this.createEnvironment();
		this.createBall();
		this.createPlayers();
		this.createModels(this.ship1Number, this.ship2Number);
		this.camerap1.position.set(this.player1.position.x - 2, this.player1.position.y + 0.2, this.player1.position.z - 1);
		this.camerap1.lookAt(this.initialpos);
		this.camerap1.rotation.z = 4.891;
		this.camerap2.position.set(this.player2.position.x + 2, this.player2.position.y - 0.2, this.player2.position.z - 1);
		this.camerap2.lookAt(this.initialpos);
		this.camerap2.rotation.z = 1.75;
		this.cameratop3.position.set(0, 0, this.player1.position.z - 7);
		this.cameratop3.lookAt(this.initialpos);
		this.cameratop3.rotateZ(Math.PI);
		this.maxY = this.geoy / 2 - this.geometry_player1.parameters.height / 2;
		this.minY = -this.geoy / 2 + this.geometry_player1.parameters.height / 2;
		this.maxX = -this.geox / 10;
		this.minX = -this.geox / 2 + this.geometry_player1.parameters.width / 2;
		this.setupEventListeners();
		this.renderer.setSize(window.innerWidth, window.innerHeight);
		document.body.appendChild(this.renderer.domElement);
		this.createScoreboard();
		this.animate = this.animate.bind(this);
		setTimeout(() => {
			this.animate();
		}, 1000);
	}

	cleanUpHexagons() {
		this.hexGroup.children.forEach(hex => {
			if (hex instanceof THREE.LineSegments && hex.material) {
				hex.material.dispose();
				hex.geometry.dispose();
			}
		});
		this.hexGroup.children = []; // Remove all children
		this.playingSurface.children.forEach(hex => {
			if (hex instanceof THREE.LineSegments && hex.material) {
				hex.material.dispose();
				hex.geometry.dispose();
			}
		});
		this.playingSurface.children = [];
	}

	cleanUpScore() {
		this.scoreboard.player1.forEach(({ ball, ring }) => {
			this.playingSurface.remove(ball);
			ball.geometry.dispose();
			ball.material.dispose();
			ring.geometry.dispose();
			ring.material.dispose();
		});
		this.scoreboard.player2.forEach(({ ball, ring }) => {
			this.playingSurface.remove(ball);
			ball.geometry.dispose();
			ball.material.dispose();
			ring.geometry.dispose();
			ring.material.dispose();
		});
		this.scoreboard = { player1: [], player2: [] };
	}

	cleanup() {
		//this.sendDisconnect();
		if (gameFinished === false) {
			this.sendDisconnect();
		}
		if (isWaiting === true) {
			if (thisUser === ballController) {
				document.body.removeChild(waitingModal);
			}
			if (getOtherPlayer() === null && gameRejected === false) {
				const resultRank = finishRank(getSenderPlayer(), getSelectedGameID());
			} else if (gameRejected === false) {
				const resultInv = finishInvitation(getSenderPlayer(), getOtherPlayer(), getSelectedGameID());
			}
			isWaiting = false;
			flagFirstUser = false;
			gameRejected = false
			return;
		}
		thisUser = null;
		ballController = null;
		cancelAnimationFrame(this.animationFrameID);
		this.cleanUpScore();
		this.cleanUpHexagons();
		window.removeEventListener('keydown', this.handleKeyDown);
		window.removeEventListener('keyup', this.handleKeyUp);
		if (document.body.contains(this.renderer.domElement)) {
			document.body.removeChild(this.renderer.domElement);
		}
		this.renderer.dispose();
		this.scene.traverse((object) => {
			if (object.isMesh) {
				object.geometry.dispose();
				if (object.material) {
					if (Array.isArray(object.material)) {
						object.material.forEach((material) => {
							material.dispose();
							// Dispose of textures
							if (material.map) material.map.dispose();
							if (material.normalMap) material.normalMap.dispose();
							if (material.specularMap) material.specularMap.dispose();
							if (material.roughnessMap) material.roughnessMap.dispose();
							if (material.metalnessMap) material.metalnessMap.dispose();
							if (material.aoMap) material.aoMap.dispose();
							if (material.emissiveMap) material.emissiveMap.dispose();
							if (material.envMap) material.envMap.dispose();
							if (material.lightMap) material.lightMap.dispose();
							if (material.bumpMap) material.bumpMap.dispose();
						});
					} else {
						object.material.dispose();
						// Dispose of textures
						if (object.material.map) object.material.map.dispose();
						if (object.material.normalMap) object.material.normalMap.dispose();
						if (object.material.specularMap) object.material.specularMap.dispose();
						if (object.material.roughnessMap) object.material.roughnessMap.dispose();
						if (object.material.metalnessMap) object.material.metalnessMap.dispose();
						if (object.material.aoMap) object.material.aoMap.dispose();
						if (object.material.emissiveMap) object.material.emissiveMap.dispose();
						if (object.material.envMap) object.material.envMap.dispose();
						if (object.material.lightMap) object.material.lightMap.dispose();
						if (object.material.bumpMap) object.material.bumpMap.dispose();
					}
				}
			}
		});
		delete this.audioLoader;
		delete this.loader;
		this.scene.clear();
		THREE.Cache.clear();
	}

	createHexagon(size, opac) {
		const hexGeometry = new THREE.CircleGeometry(size, 6);
		const edges = new THREE.EdgesGeometry(hexGeometry);
		const material = new THREE.LineBasicMaterial({ color: this.hexagoncolor, opacity: opac, transparent: true });
		const hexagon = new THREE.LineSegments(edges, material);
		hexagon.originalColor = material.color.clone();
		return hexagon;
	}

	createHexagonGrid(hexSize, hexSpacing) {
		let cols = Math.ceil(this.geox / (hexSize * Math.sqrt(3) + hexSpacing));
		let rows = Math.floor((this.geoy - hexSize) / (hexSize * 2 + hexSpacing));

		// Calculate total width and height of the grid
		let totalWidth = (cols - 1) * (hexSize * Math.sqrt(3) + hexSpacing);
		let totalHeight = (rows - 1) * (hexSize * 2 + hexSpacing);

		let yOffset = -0.0805; // Adjust this value to move the grid up or down

		for (let i = 0; i < rows; i++) {
			for (let j = 0; j < cols; j++) {
				let hex = this.createHexagon(hexSize, 0.5); // ADJUST HERE
				hex.position.x = j * (hexSize * Math.sqrt(3) + hexSpacing) - totalWidth / 2;
				hex.position.y = i * (hexSize * 2 + hexSpacing) - totalHeight / 2 + yOffset;
				hex.position.z = 0.05;
				if (j % 2 === 0) {
					hex.position.y += hexSize + hexSpacing / 2; // Offset every other row
				}
				hex.renderOrder = -1; // Set renderOrder to a lower value
				this.hexGroup.add(hex);
			}
		}

		return this.hexGroup;
	}

	createHexagonWall(yPosition) {
		const size = 0.15;
		const spacing = 0.2;
		const width = this.geox;

		// To remove a hexagon from the start of the row, increase the starting value of x
		for (let x = -width / 2 + size + spacing; x < width / 2; x += size + spacing) {
			const hexagon = this.createHexagon(size, 0.7);
			hexagon.rotation.x = Math.PI / 2;
			hexagon.position.set(x, yPosition, 0);
			this.playingSurface.add(hexagon);
		}
	}

	createWalls() {
		const wallPositions = [ // y positions of the walls
			-this.geoy / 2, // bottom wall
			this.geoy / 2, // top wall
		];
		wallPositions.forEach(yPosition => this.createHexagonWall(yPosition));
	}

	createEnvironment() {
		const plane1Geometry = new THREE.PlaneGeometry(this.geox, this.geoy);
		const plane1Material = new THREE.MeshBasicMaterial({ visible: false });
		this.playingSurface = new THREE.Mesh(plane1Geometry, plane1Material);
		this.scene.add(this.playingSurface);

		let hexGrid = this.createHexagonGrid(0.15, 0.02); // values tested to work at school
		this.playingSurface.add(hexGrid);
		this.createWalls();

		// Environment
		const envGeometry = new THREE.SphereGeometry(400, 20, 10);
		const envMaterial = new THREE.MeshBasicMaterial({ side: THREE.DoubleSide });
		this.env = new THREE.Mesh(envGeometry, envMaterial);
		this.scene.add(this.env);
		this.loader.load('/static/media/assets/mway8.jpg', function(texture) {
			texture.wrapS = THREE.RepeatWrapping;
			texture.wrapT = THREE.RepeatWrapping;
			envMaterial.map = texture;
			envMaterial.needsUpdate = true;
		});

		// Planet 1
		const planetGeometry = new THREE.SphereGeometry(1, 20, 20); // radius, widthSegments, heightSegments
		let moonTexture = new THREE.MeshLambertMaterial({ map: this.loader.load('/static/media/assets/moon.jpg') });
		this.moon = new THREE.Mesh(planetGeometry, moonTexture);
		this.scene.add(this.moon);
		this.env.add(this.moon);
		//this.moon.position.set(7, 7, 7);
		this.moon.position.set(-20, -2, -20);


		// Planet 2
		const sphereGeometry = new THREE.SphereGeometry(3, 32, 32);
		let earthTexture = new THREE.MeshLambertMaterial({ map: this.loader.load('/static/media/assets/earthnight.jpg'), reflectivity: 1 });
		this.planetEarth = new THREE.Mesh(sphereGeometry, earthTexture);
		this.scene.add(this.planetEarth);
		this.env.add(this.planetEarth);
		this.planetEarth.position.set(5, 5, 5);
		this.planetEarth.rotateY(2.5);
		this.planetEarth.rotateZ(-1.5);

		const cloudsGeometry = new THREE.SphereGeometry(3.05, 32, 32);
		let cloudsMaterial = new THREE.MeshLambertMaterial({
			map: this.loader.load('/static/media/assets/clouds.jpg'), transparent: true, opacity: 0.2 });
		this.clouds = new THREE.Mesh(cloudsGeometry, cloudsMaterial);
		this.planetEarth.add(this.clouds);

		// Sun

		const sunGeometry = new THREE.SphereGeometry(1, 32, 32);
		let sunMaterial = new THREE.MeshBasicMaterial({ map: this.loader.load ('/static/media/assets/sun.jpg') })
		this.sun = new THREE.Mesh(sunGeometry, sunMaterial);
		this.sun.position.set(-40, -1, -1);
		this.scene.add(this.sun);
		this.env.add(this.sun);
		//testing
		const borderGeometry = new THREE.SphereGeometry(1.05, 32, 32); // Slightly larger sphere
		let borderMaterial = new THREE.MeshBasicMaterial({ color: 0xFFFFFF, side: THREE.BackSide }) // White material, render backside
		this.sunBorder = new THREE.Mesh(borderGeometry, borderMaterial);
		this.sunBorder.position.set(this.sun.position.x, this.sun.position.y, this.sun.position.z);
		this.scene.add(this.sunBorder);
		this.env.add(this.sunBorder);
		//end of testing
		const light = new THREE.PointLight(0xFFFFFF, 2, 400);
		light.position.set(this.sun.position.x, this.sun.position.y, this.sun.position.z);
		this.scene.add(light);
		this.env.add(light);
	}

	createBall() {
		const geometry_ball = new THREE.SphereGeometry(0.07, 32, 32);
		let ball_tex = new THREE.MeshLambertMaterial({ map: this.loader.load('/static/media/assets/ball.jpg') });
		this.ball = new THREE.Mesh(geometry_ball, ball_tex);
		this.scene.add(this.ball);
		this.ball.position.set(0, 0, -0.01);
		this.ball.velocity = new THREE.Vector3(-0.02, 0.02, 0);
		this.ballLastPosition = { x: this.ball.position.x, y: this.ball.position.y };
	}

	createPlayers() {
		this.geometry_player1 = new THREE.BoxGeometry(0.01, 0.5, 0.1);
		const material_player1 = new THREE.MeshStandardMaterial({ map: this.loader.load('/static/media/assets/metal.png'), side: THREE.DoubleSide, transparent: true, opacity: 0.3 });
		this.player1 = new THREE.Mesh(this.geometry_player1, material_player1);
		this.scene.add(this.player1);
		this.player1.position.set((-this.geox / 2) + 0.1, 0, 0);

		this.geometry_player2 = new THREE.BoxGeometry(0.01, 0.5, 0.1);
		const material_player2 = new THREE.MeshStandardMaterial({ map: this.loader.load('/static/media/assets/metal.png'), side: THREE.DoubleSide, transparent: true, opacity: 0.3 });
		this.player2 = new THREE.Mesh(this.geometry_player2, material_player2);
		this.scene.add(this.player2);
		this.player2.position.set((this.geox / 2) - 0.1, 0, 0);
	}

	createBarrier(player) {
		const barrierGeometry = new THREE.PlaneGeometry(this.geox, 0.1);
		const barrierMaterial = new THREE.MeshBasicMaterial({ color: 0x00ff00, transparent: true, opacity: 1 });
		const barrier = new THREE.Mesh(barrierGeometry, barrierMaterial);
		barrier.position.set(0, player.position.y + (player.scale.y / 2) + 0.1, 0);
		this.playingSurface.add(barrier);
		this.barrier = barrier;
		new TWEEN.Tween(this.barrier.material)
			.to({ opacity: 0 }, 1000)
			.onComplete(() => {
				this.playingSurface.remove(this.barrier);
				this.barrier.geometry.dispose();
				this.barrier.material.dispose();
				this.barrier = null;
			})
			.start();
	}

	getShipMesh(shipNumber) {
		let shipMesh;
		switch(shipNumber) {
			case 1:
				shipMesh = '/static/media/assets/ships/ship1.fbx';
				break;
			case 2:
				shipMesh = '/static/media/assets/ships/ship2.fbx';
				break;
			case 3:
				shipMesh = '/static/media/assets/ships/ship3.fbx';
				break;
			case 4:
				shipMesh = '/static/media/assets/ships/ship4.fbx';
				break;
			case 5:
				shipMesh = '/static/media/assets/ships/ship5.fbx';
				break;
			case 6:
				shipMesh = '/static/media/assets/ships/ship6.fbx';
				break;
			case 7:
				shipMesh = '/static/media/assets/ships/ship7.fbx';
				break;
			case 8:
				shipMesh = '/static/media/assets/ships/ship8.fbx';
				break;
			case 9:
				shipMesh = '/static/media/assets/ships/ship9.fbx';
				break;
			default:
				shipMesh = '/static/media/assets/ships/tie-fighter.fbx';
				break;
		}
		return shipMesh;
	}

	getShipTex(shipNumber) {
		let shipTex;
		switch(shipNumber) {
			case 1:
				shipTex = '/static/media/assets/ships/ship1.png';
				break;
			case 2:
				shipTex = '/static/media/assets/ships/ship22.png';
				break;
			case 3:
				shipTex = '/static/media/assets/ships/ship3.png';
				break;
			case 4:
				shipTex = '/static/media/assets/ships/ship4.png';
				break;
			case 5:
				shipTex = '/static/media/assets/ships/ship5.png';
				break;
			case 6:
				shipTex = '/static/media/assets/ships/ship6.png';
				break;
			case 7:
				shipTex = '/static/media/assets/ships/ship7.png';
				break;
			case 8:
				shipTex = '/static/media/assets/ships/ship8.png';
				break;
			case 9:
				shipTex = '/static/media/assets/ships/ship9.png';
				break;
			default:
				shipTex = '/static/media/assets/metal.png';
				break;
		}
		return shipTex;
	}

	adjustShipScale(shipNumber) {
		let scaleValue;
		switch(shipNumber) {
			case 1:
				scaleValue = 0.0018;
				break;
			case 2:
				scaleValue = 0.002;
				break;
			case 3:
				scaleValue = 0.0019;
				break;
			case 4:
				scaleValue = 0.0015;
				break;
			case 5:
				scaleValue = 0.0011;
				break;
			case 6:
				scaleValue = 0.0013;
				break;
			case 7:
				scaleValue = 0.002;
				break;
			case 8:
				scaleValue = 0.005;
				break;
			default:
				scaleValue = 0.0011;
				break;
		}
		return (scaleValue);
	}

	createModels(ship1Number, ship2Number) {
		let ship1Mesh, ship2Mesh, ship1Tex, ship2Tex;
		ship1Mesh = this.getShipMesh(ship1Number);
		ship2Mesh = this.getShipMesh(ship2Number);
		ship1Tex = this.getShipTex(ship1Number);
		ship2Tex = this.getShipTex(ship2Number);

		this.loader.load(ship2Tex, (texture) => {
			let trymesh = new THREE.MeshStandardMaterial({ map: texture });
			this.fbxloader.load(ship2Mesh, (ship) => {
				let scaleValue = this.adjustShipScale(ship2Number);
				ship.position.set(2.7, this.player2.position.y, this.player2.z);
				ship.scale.set(scaleValue, scaleValue, scaleValue);
				ship.rotation.x = -Math.PI / 2;
				ship.rotation.y = Math.PI / 2;
				ship.visible = true;
				this.scene.add(ship);
				ship.traverse((child) => {
					if (child.isMesh) {
						child.material = trymesh;
					}
				});
				this.ship2 = ship;
			});
		});

		this.loader.load(ship1Tex, (texture) => {
			let trymesh = new THREE.MeshStandardMaterial({ map: texture });
			this.fbxloader.load(ship1Mesh, (ship) => {
				let scaleValue = this.adjustShipScale(ship1Number);
				ship.position.set(-2.7, this.player1.position.y, this.player1.position.z);
				ship.scale.set(scaleValue, scaleValue, scaleValue);
				ship.rotation.x = -Math.PI / 2;
				ship.rotation.y = 3 * Math.PI / 2;
				ship.visible = true;
				this.scene.add(ship);
				ship.traverse((child) => {
					if (child.isMesh) {
						child.material = trymesh;
					}
				});
				this.ship1 = ship;
			});
		});
	}

	setupEventListeners() {
		window.addEventListener('keydown', (event) => {
			/* if (event.key === ' ') {
				event.preventDefault();
			} */
			this.keysPressed[event.key] = true;
		});
		window.addEventListener('keyup', (event) => {
			this.keysPressed[event.key] = false;
		});
	}

	gameOver() {
		gameFinished = true;
		midGame = false;
		this.sendDisconnect();
		this.isRunning = false;
		const match = {
			result: `Loss`,
			score: `${this.scorePlayer1}-${this.scorePlayer2}`,
			game: `Pong Remote`,
		};
		saveMatchHistory(match);
		gameFinished = true;
		this.cleanup();
		navigate('/gamelost');
	}

	gameWin() {
		gameFinished = true;
		midGame = false;
		this.sendDisconnect();
		this.isRunning = false;
		let match = null;
		if (gameAbandoned === true) {
			match = {
				result: `Win`,
				score: `Forfeit`,
				game: `Pong Remote`,
			};
		} else {
			match = {
				result: `Win`,
				score: `${this.scorePlayer1}-${this.scorePlayer2}`,
				game: `Pong Remote`,
			};
		}
		saveMatchHistory(match);
		this.cleanup();
		navigate('/gamewon');
	}

	HexagonColorChange(hexagon) {
		if (hexagon.tween) {
			hexagon.tween.stop();
		}
		const tweenToYellow = new TWEEN.Tween(hexagon.material.color)
			.to({ r: 1, g: 1, b: 0 }, 100)
			.start();
		const tweenBack = new TWEEN.Tween(hexagon.material.color)
			.to({ r: hexagon.originalColor.r, g: hexagon.originalColor.g, b: hexagon.originalColor.b }, 100);
		tweenToYellow.chain(tweenBack);
	}

	checkBallOverHexagon() {
		const colorChangeAOE = 0.4;
		this.hexagons = this.hexGroup.children; // Access hexagons from hexGroup
		this.hexagons.forEach(hexagon => {
			const distance = this.ball.position.distanceTo(hexagon.position);
			if (distance < colorChangeAOE) {
				this.HexagonColorChange(hexagon);
			}
		});
	}

	resetBall() {
		let currentPos = this.ball.position.x;
		let randomFloat = Math.random() * 2 - 1;
		this.ball.velocity.set(0, 0, 0);
		this.ball.position.set(0, randomFloat, -0.01);
		setTimeout(() => {
			if (currentPos > 0)
				this.ball.velocity.set(0.02, 0.02, 0);
			else if (currentPos < 0)
				this.ball.velocity.set(-0.02, 0.02, 0);
		}, 1000);
		this.sendBallMove({
			velocity: { x: -this.ball.velocity.x, y: this.ball.velocity.y},
			position: { x: -this.ball.position.x, y: this.ball.position.y },
		});
	}

	updatePlayer2Move(moveData) {
		if (moveData.direction === 'left') {
			this.env.rotation.x += 0.007;
			if (this.player2.position.y >= this.minY) {
				this.player2.position.y -= 0.03;
				this.ship2.position.y -= 0.03;
				const tweenLeft = new TWEEN.Tween(this.ship2.rotation)
					.to({ z: THREE.Math.degToRad(-30) }, 400) // Rotate 20 degrees to the left
					.easing(TWEEN.Easing.Quadratic.Out)
					.start();
			}
		} else if (moveData.direction === 'right') {
			this.env.rotation.x -= 0.007;
			if (this.player2.position.y <= this.maxY) {
				this.player2.position.y += 0.03;
				this.ship2.position.y += 0.03;
				const tweenRight = new TWEEN.Tween(this.ship2.rotation)
					.to({ z: THREE.Math.degToRad(30) }, 400) // Rotate 20 degrees to the right
					.easing(TWEEN.Easing.Quadratic.Out)
					.start();
			}
		}
		if (!moveData.direction === 'right' && !moveData.direction === 'left') {
			const tweenBack = new TWEEN.Tween(this.ship2.rotation)
				.to({ z: THREE.Math.degToRad(-0) }, 400)
				.easing(TWEEN.Easing.Quadratic.Out)
				.start();
		}
	}

	updateScoreOtherPlayer(scoreData) {
		if (scoreData.score === thisUser) {
			this.scorePlayer1++;
			this.shake = 0.05;
			this.updateScore(this.scorePlayer1, this.scorePlayer2);
		} else {
			this.scorePlayer2++;
			this.shake = 0.05;
			this.updateScore(this.scorePlayer1, this.scorePlayer2);
		}
	}

	playSound = (soundFilePath, volume) => {
		const sound = new THREE.Audio(this.listener);
		this.audioLoader.load(soundFilePath, (buffer) => {
			sound.setBuffer(buffer);
			sound.setVolume(volume); // Set volume; adjust as needed
			sound.play();
			sound.source.onended = () => {
				sound.stop();
				sound.disconnect();
			};
		});
	};

	createScoreboard() {
		if (this.scoreboard && this.scoreboard.player1 && this.scoreboard.player1.length > 0 && this.scoreboard.player2 && this.scoreboard.player2.length > 0) {
			return;
		}
		this.scoreboard = { player1: [], player2: [] };
		for (let i = 0; i < 4; i++) {
			let scoreBallPlayer1 = this.ball.clone();
			let scoreBallPlayer2 = this.ball.clone();
			let ringGeometry = new THREE.RingGeometry(0.08, 0.09, 32);
			let ringMaterial = new THREE.MeshBasicMaterial({ color: 0x00ffff, side: THREE.DoubleSide, transparent: true, opacity: 0.5 });
			let ringPlayer1 = new THREE.Mesh(ringGeometry, ringMaterial);
			let ringPlayer2 = new THREE.Mesh(ringGeometry, ringMaterial);
			scoreBallPlayer1.add(ringPlayer1);
			scoreBallPlayer2.add(ringPlayer2);
			this.scoreboard.player1.push({ ball: scoreBallPlayer1, ring: ringPlayer1 });
			this.scoreboard.player2.push({ ball: scoreBallPlayer2, ring: ringPlayer2 });
			this.playingSurface.add(scoreBallPlayer1);
			this.playingSurface.add(scoreBallPlayer2);
			scoreBallPlayer1.visible = false;
			scoreBallPlayer2.visible = false;
			ringPlayer1.visible = false;
			ringPlayer2.visible = false;
			scoreBallPlayer1.position.set(-3, - i * 0.2, -1); // Adjust as needed
			scoreBallPlayer2.position.set(3, + i * 0.2, -1); // Adjust as needed
		}
	}

	updateScore(scorePlayer1, scorePlayer2) {
		for (let i = 0; i < 4; i++) {
			this.scoreboard.player1[i].ball.visible = i < scorePlayer1;
			this.scoreboard.player1[i].ring.visible = i < scorePlayer1;
			this.scoreboard.player2[i].ball.visible = i < scorePlayer2;
			this.scoreboard.player2[i].ring.visible = i < scorePlayer2;
		}
		this.playSound('/static/media/assets/sounds/fireball.mp3', 0.2);
	}

	animateRings() {
		this.scoreboard.player1.forEach(({ ring }) => {
			if (ring.visible) {
				ring.rotation.y += 0.11;
				ring.rotation.x += 0.06;
			}
		});

		this.scoreboard.player2.forEach(({ ring }) => {
			if (ring.visible) {
				ring.rotation.y -= 0.11;
				ring.rotation.x += 0.06;
			}
		});
	}

	ballCollisions() {
		// Ball collision with walls
		if (this.ball.position.y + this.ball.geometry.parameters.radius > this.geoy / 2) {
			this.ball.position.y = this.geoy / 2 - this.ball.geometry.parameters.radius;
			this.ball.velocity.y *= -1;
			this.playSound('/static/media/assets/sounds/laser0.mp3', 0.4);
		}
		if (this.ball.position.y - this.ball.geometry.parameters.radius < -this.geoy / 2) {
			this.ball.position.y = -this.geoy / 2 + this.ball.geometry.parameters.radius;
			this.ball.velocity.y *= -1;
			this.playSound('/static/media/assets/sounds/laser0.mp3', 0.4);
		}

		// Ball collision with players
		// Player 1
		const player1Bounds = {
			left: this.player1.position.x - this.geometry_player1.parameters.width * this.player1.scale.x / 2,
			right: this.player1.position.x + this.geometry_player1.parameters.width * this.player1.scale.x / 2,
			top: this.player1.position.y + this.geometry_player1.parameters.height * this.player1.scale.y / 2,
			bottom: this.player1.position.y - this.geometry_player1.parameters.height * this.player1.scale.y / 2
		};

		if (this.ball.position.x - this.ball.geometry.parameters.radius < player1Bounds.right &&
			this.ball.position.x + this.ball.geometry.parameters.radius > player1Bounds.left &&
			this.ball.position.y + this.ball.geometry.parameters.radius > player1Bounds.bottom &&
			this.ball.position.y - this.ball.geometry.parameters.radius < player1Bounds.top) {
			// Reflect the ball's X velocity
			if (Math.abs(this.ball.velocity.x) < 0.1) {
				this.ball.velocity.x *= -1.04;
			}
			// Adjust the ball's position to avoid sticking
			this.ball.position.x = player1Bounds.right + this.ball.geometry.parameters.radius + 0.05;
		}
		// Player 2
		const player2Bounds = {
			left: this.player2.position.x - this.geometry_player2.parameters.width / 2,
			right: this.player2.position.x + this.geometry_player2.parameters.width / 2,
			top: this.player2.position.y + this.geometry_player2.parameters.height / 2,
			bottom: this.player2.position.y - this.geometry_player2.parameters.height / 2
		};

		if (this.ball.position.x - this.ball.geometry.parameters.radius < player2Bounds.right &&
			this.ball.position.x + this.ball.geometry.parameters.radius > player2Bounds.left &&
			this.ball.position.y + this.ball.geometry.parameters.radius > player2Bounds.bottom &&
			this.ball.position.y - this.ball.geometry.parameters.radius < player2Bounds.top) {
			// Reflect the ball's X velocity
			if (Math.abs(this.ball.velocity.x) < 0.1) {
				this.ball.velocity.x *= -1.04;
			}
			// Adjust the ball's position to avoid sticking
			this.ball.position.x = player2Bounds.left - this.ball.geometry.parameters.radius - 0.05;
		}
		this.sendBallMove({
			velocity: { x: -this.ball.velocity.x, y: this.ball.velocity.y},
			position: { x: -this.ball.position.x, y: this.ball.position.y },
		});
	}

	animate() {

		if (gameFinished === true) {
			return ;
		}
		this.animateRings();
		this.env.rotation.z += 0.0001;
		this.env.rotation.y += 0.0001;
		this.planetEarth.rotation.z += 0.0001;
		this.planetEarth.rotation.y -= 0.0001;
		this.planetEarth.rotation.x += 0.0001;
		this.clouds.rotation.z += 0.0001;
		this.clouds.rotation.y += 0.0001;
		this.moon.rotation.z -= 0.001;
		this.moon.rotation.y -= 0.001;
		this.sun.rotation.x += 0.001;
		this.checkBallOverHexagon();
		TWEEN.update();
		this.ball.rotation.x += 0.04;
		this.ball.rotation.y += 0.04;
		if (this.shake > 0) {
			let newPos = Math.random() * this.shake * 2 - this.shake;
			this.camerap1.position.x += newPos;
			this.camerap1.position.y += newPos;
			this.camerap1.position.z += newPos;
			this.camerap2.position.x += newPos;
			this.camerap2.position.y += newPos;
			this.shake -= 0.005;
		}
		if (this.keysPressed['a'] && this.ship1) {
			this.env.rotation.x += 0.007;
			if (this.player1.position.y >= this.minY) {
				this.player1.position.y -= 0.03;
				this.ship1.position.y -= 0.03;
				const tweenLeft = new TWEEN.Tween(this.ship1.rotation)
					.to({ z: THREE.Math.degToRad(30) }, 400) // Rotate 20 degrees to the left
					.easing(TWEEN.Easing.Quadratic.Out)
					.start();
			}
			this.sendPlayerMove({
				direction: 'left',
				player: 2,
				position: { x: this.player1.position.x, y: this.player1.position.y },
			});
		}
		if (this.keysPressed['d'] && this.ship1) {
			this.env.rotation.x -= 0.007;
			if (this.player1.position.y <= this.maxY) {
				this.player1.position.y += 0.03;
				this.ship1.position.y += 0.03;
				const tweenRight = new TWEEN.Tween(this.ship1.rotation)
					.to({ z: THREE.Math.degToRad(-30) }, 400) // Rotate 20 degrees to the right
					.easing(TWEEN.Easing.Quadratic.Out)
					.start();
			}
			this.sendPlayerMove({
				direction: 'right',
				player: 2,
				position: { x: this.player1.position.x, y: this.player1.position.y },
			});
		}
		if (!this.keysPressed['d'] && !this.keysPressed['a'] && this.ship1) {
			const tweeBack = new TWEEN.Tween(this.ship1.rotation)
				.to({ z: THREE.Math.degToRad(-0) }, 400)
				.easing(TWEEN.Easing.Quadratic.Out)
				.start();
		}
		if (this.keysPressed['c']) {
			this.cameratoggle = (this.cameratoggle + 1) % 3;
			this.keysPressed['c'] = false;
		}
		if (thisUser === ballController) {
			this.ball.position.add(this.ball.velocity);
			this.sendBallMove({
				velocity: { x: -this.ball.velocity.x, y: this.ball.velocity.y},
				position: { x: -this.ball.position.x, y: this.ball.position.y },
			});
		} else {
			this.ball.position.add(this.ball.velocity);
		}
		// Check for scoring
		if (this.scorePlayer2 >= 5)
			this.gameOver();
		if (this.scorePlayer1 >= 5)
			this.gameWin();
		if (thisUser === ballController) {
			if (this.ball.position.x + this.ball.geometry.parameters.radius > (this.geox / 2)/*  + 0.21 */) {
				this.scorePlayer1++;
				this.shake = 0.05;
				this.updateScore(this.scorePlayer1, this.scorePlayer2);
				this.resetBall();
				this.sendScore({
					score: thisUser,
				});
			}
			else if (this.ball.position.x - this.ball.geometry.parameters.radius < (-this.geox / 2 )) {
				this.scorePlayer2++;
				this.shake = 0.05;
				this.updateScore(this.scorePlayer1, this.scorePlayer2);
				this.resetBall();
				this.sendScore({
					score: ballSpector,
				});
			}
		}
		if (thisUser === ballController) {
			this.ballCollisions();
		}
		if (this.cameratoggle == 0)
			this.renderer.render(this.scene,this.camerap1);
		else if (this.cameratoggle == 1)
			this.renderer.render(this.scene, this.camerap2);
		else if (this.cameratoggle == 2)
			this.renderer.render(this.scene, this.cameratop3);
		this.animationFrameID = requestAnimationFrame(this.animate);
	}
}

export default function PongRemote() {
	const gameId = getSelectedGameID();
	const gameWebsocket = new WebSocket(`wss://${window.location.host}/ws/pong/${gameId}/?purpose=join`);
	waitingModal.innerHTML = `<div class="vh-100 d-flex flex-column align-items-center justify-content-center text-white">
		<h5>Waiting for the other opponent...</h5>
		</div>`;

	const game = new Game();
	gameWebsocket.onmessage = async function (event) {
		const data = JSON.parse(event.data);

		if (data.action === 'waiting') {
			isWaiting = true;
			midGame = false;
			flagFirstUser = true;
			document.body.appendChild(waitingModal);
		} else if (data.action === 'start_game') {
			isWaiting = false;
			midGame = true;
			thisUser = null;
			ballController = null;
			ballSpector = null;
			gameAbandoned = false;
			gameFinished = false;
			gameRejected = false;
			ballController = getSenderPlayer();
			ballSpector = getOtherPlayer();
			if (ballSpector === null) {
				const result = await findReceiver(getSelectedGameID());
				ballSpector = result.receiver;
			}
			game.fetchShipAndColorRemote().then(() => {
				if (thisUser === ballController) {
					document.body.removeChild(waitingModal);
				}
				game.init();
			});
		} else if (data.action === 'update_scores') {
			const scoreData = data.score;
			if (data.player === thisUser) {
				return;
			} else {
				game.updateScoreOtherPlayer(scoreData);
			}
		} else if (data.action === 'player_move') {
			const moveData = data.move_data;
			if (data.player === thisUser) {
				return;
			} else {
				game.updatePlayer2Move(moveData);
			}
		} else if (data.action === 'update_ball') {
			const ballData = data.ball_state;
			if (thisUser === ballController) {
				return;
			} else {
				game.ball.position.x = ballData.position.x;
				game.ball.position.y = ballData.position.y;
				game.ball.velocity.x = ballData.velocity.x;
				game.ball.velocity.y = ballData.velocity.y;
			}
		} else if (data.action === 'player_left') {
			alert(data.message);
			gameAbandoned = true;
			game.gameWin();
		} else if (data.action === 'player_reject') {
			gameRejected = true;
			alert(data.message);
			navigate('/');
		}

		game.sendPlayerMove = (moveData) => {
			gameWebsocket.send(JSON.stringify({
				action: 'player_move',
				player: thisUser,
				move_data: moveData,
			}));
		};

		game.sendScore = (scoreData) => {
			gameWebsocket.send(JSON.stringify({
				action: 'update_scores',
				player: ballController,
				score: scoreData,
			}));
		};

		game.sendBallMove = (moveBallData) => {
			if (gameFinished === true) {
				return;
			}
			gameWebsocket.send(JSON.stringify({
				action: 'update_ball',
				player: ballController,
				ball_state: moveBallData,
			}));
		};

		game.sendDisconnect = () => {
			if (gameFinished === true) {
				gameWebsocket.close();
				gameWebsocket.onclose = function () {
					delete gameWebsocket[gameId];
				};
			} else {
				gameWebsocket.close(1000, "Player left the page");
				gameWebsocket.onclose = function () {
					delete gameWebsocket[gameId];
				};
			}
		}

	}
	return game;
}

export function getGameFinished() {
	return gameFinished;
}

export function getMidGame() {
	return midGame;
}
