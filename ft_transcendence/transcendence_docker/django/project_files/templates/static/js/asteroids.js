import { saveMatchHistory } from './components/pages/Dashboard.js';
import { navigate } from './helpers/App.js';

let gameName = null;

function getTournamentData() {
	return JSON.parse(localStorage.getItem('tournamentData'));
}

class Level {
	constructor(number, asteroids, sAsteroids, AIShips, powerups) {
		this.number = number;
		this.asteroids = asteroids;
		this.sAsteroids = sAsteroids;
		this.AIShips = AIShips;
		this.powerups = powerups;
	}
}

class Game {
	constructor(gameMode, gameType) {
		this.gameMode = gameMode;
		this.gameType = gameType;
		this.tournamentNumberOfPlays = 1;
		if (this.gameMode === '8' || this.gameMode === '9') {
			if (this. gameMode === '7' || this.gameMode === '8') {
				this.tournamentNumberOfPlays = 3;
			}
			else if (this.gameMode === '9') {
				this.tournamentNumberOfPlays = 7;
			}
			this.gameMode = '6';
		}
		this.tournamentPlayersNames = [];
		this.currentTournamentPlay = 1;
		this.unpaused = true;
		this.pauseCube = null;
		this.levels = [
			new Level(0, 1, 0, 0, 0),
			new Level(1, 2, 0, 0, 0),
			new Level(2, 3, 1, 0, 0),
			new Level(3, 2, 1, 1, 0),
			new Level(4, 2, 2, 0, 1),
			new Level(5, 3, 2, 0, 0),
			new Level(6, 4, 2, 1, 0),
			new Level(7, 4, 2, 2, 1),
			new Level(8, 5, 3, 0, 0),
			new Level(9, 7, 4, 1, 2),
			new Level(10, 0, 0, 5, 0)
		];
		this.nextLevelTimer = 0;
		this.player1Lives = 5;
		this.player1Loser = true;
		this.playerHasLost = false;
		if (this.gameMode === '1' || this.gameMode === '6') {
			this.player2;
			this.player2Lives = 5;
			this.shield2 = null;
			this.shieldBar2 = null;
			this.shieldBarBox2 = null;
			this.player2VelocityX = 0;
			this.player2VelocityY = 0;
			this.player2IsActive = true;
			this.lives2 = [];
			this.ship2Number = 8;  // Player 2 ship - change here 
			this.winners = [];
			this.currentPlayerIndex = 1;
		}
		this.ship1Number = 7; // Player 1 ship - change here
		this.level = 0;
		this.GameIsRunning = false;
		this.env = null;
		this.scene = new THREE.Scene();
		this.loader = new THREE.TextureLoader();
		this.aspectRatio = window.innerWidth / window.innerHeight;
		this.boundaryX = 40 * this.aspectRatio;
		this.boundaryY = 40;
		const viewSize = 100;
		this.camera = new THREE.OrthographicCamera(
			this.aspectRatio * viewSize / -2, // left
			this.aspectRatio * viewSize / 2, // right
			viewSize / 2, // top
			viewSize / -2, // bottom
			-1000, // near
			1000 // far
		);
		this.listener = new THREE.AudioListener();
		this.audioLoader = new THREE.AudioLoader();
		this.camera.add(this.listener);
		this.renderer = new THREE.WebGLRenderer();
		this.asteroids = [];
		this.sAsteroids = [];
		this.AIShips = [];
		this.powerups = [];
		this.projectiles = [];
		this.lives1 = [];
		this.shield1;
		this.shieldBar1;
		this.shieldBarBox1;
		this.keysPressed = {};
		this.maxSpeed = 0.5;
		this.player1VelocityX = 0;
		this.player1VelocityY = 0;
		this.player1IsActive = true;
		this.player1;
		this.shotType = 1;
		this.shotType1Display;
		this.levelDisplay;
		this.lvlCompleteScreen = 0;
		this.fbxloader = new THREE.FBXLoader();
		this.explosionGroup = [];
		this.animationFrameID;
		this.animate = this.animate.bind(this);
	}
	async fetchShipAndColor() {
		try {
			const response = await fetch('/api/get-ship-and-color/');
			if (!response.ok) {
				throw new Error('Failed to fetch ship and color');
			}

			const data = await response.json();
			this.ship1Number = data.ship;
			if (this.ship1Number === 8)
				this.ship2Number = 9;
		} catch (error) {
			console.log('Error fetching ship and color:', error);
		}
	}

	init() {
		if (this.loader === null) {
			this.cleanup();
		}
		const light = new THREE.AmbientLight(0xFFFFFF);
		this.camera.position.set(0, 0, 60);
		this.camera.lookAt(this.scene.position);
		this.camera.add(this.listener);
		this.createEnvironment()
		if (this.gameMode === '1' || this.gameMode === '6') {
			this.createPlayer2(this.ship2Number);
			this.displayLives2();
			this.displayShieldBar2();
		}
		this.createPlayer1(this.ship1Number);
		this.displayLives1();
		this.displayShieldBar1();
		this.createShotDisplay();
		this.displayLevel();
		this.spawnAsteroids(this.levels[this.level].asteroids, 'asteroid');
		this.spawnAsteroids(this.levels[this.level].sAsteroids, 'sAsteroid');
		this.spawnAIships(this.levels[this.level].AIShips);
		if (this.gameType === "powered") {
			this.spawnpowerups(this.levels[this.level].powerups);
		}
		this.scene.add(light);
		this.setupEventListeners();
		this.renderer.setSize(window.innerWidth, window.innerHeight);
		document.body.appendChild(this.renderer.domElement);
		this.GameIsRunning = true;
		this.createPauseCube();
		setTimeout(() => {
			this.animate();
		}, 1000);
	}

	createPauseCube() {
		const geometry = new THREE.BoxGeometry(0.5, 0.5, 0.5);
		const material = new THREE.MeshBasicMaterial({ map: this.loader.load('/static/media/assets/pause.png'), visible: false });
		this.pauseCube = new THREE.Mesh(geometry, material);
		this.pauseCube.position.set(0, 0, 0);
		this.scene.add(this.pauseCube);
	}

	cleanup() {
		this.GameIsRunning = false;
		cancelAnimationFrame(this.animationFrameID);
		delete this.level;
		window.removeEventListener('keydown', this.handleKeyDown);
		window.removeEventListener('keyup', this.handleKeyUp);
		if (this.lives1) {
			this.lives1.forEach((life) => {
				this.scene.remove(life);
				life.geometry.dispose();
				life.material.dispose();
			});
		}
		if (this.gameMode === '1' || this.gameMode === '6') {
			this.lives2.forEach((life) => {
				this.scene.remove(life);
				life.geometry.dispose();
				life.material.dispose();
				});
			if (this.shieldBar2) {
				this.scene.remove(this.shieldBar2);
				this.shieldBar2.geometry.dispose();
				this.shieldBar2.material.dispose();
			}
			if (this.shieldBarBox2) {
				this.scene.remove(this.shieldBarBox2);
				this.shieldBarBox2.geometry.dispose();
				this.shieldBarBox2.material.dispose();
			}
		}
		if (this.shieldBar1) {
			this.scene.remove(this.shieldBar1);
			this.shieldBar1.geometry.dispose();
			this.shieldBar1.material.dispose();
		}
		if (this.shieldBarBox1) {
			this.scene.remove(this.shieldBarBox1);
			this.shieldBarBox1.geometry.dispose();
			this.shieldBarBox1.material.dispose();
		}
		if (this.shotType1Display) {
			this.shotType1Display.geometry.dispose();
			this.shotType1Display.material.dispose();
		}
		this.scene.traverse(object => {
			if (object.isMesh) {
			object.geometry.dispose();
			if (object.material) {
				if (Array.isArray(object.material)) {
				object.material.forEach(material => {
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
	
		if (document.body.contains(this.renderer.domElement)) {
		document.body.removeChild(this.renderer.domElement);
		}
	
		this.renderer.dispose();
		this.scene.clear();

		this.asteroids = [];
		this.sAsteroids = [];
		this.AIShips = [];
		this.powerups = [];
		this.projectiles = [];
		this.lives = [];

		delete this.audioLoader;
		delete this.loader;
		THREE.Cache.clear();
	}

	gameOver() {
		if (this.gameMode === '6') {
			this.tournamentHandler();
		}
		else {
			let match;
			this.GameIsRunning = false;
			for (let i = 0; i < 1000; i++) {}
			if (this.player1Loser === true) {
				match = {
					result: `Loss`,
					score: `Level ${this.level}`,
					game: `Asteroids ${gameName}`,
				};
			}
			else {
				match = {
					result: `Win`,
					score: `Level ${this.level}`,
					game: `Asteroids ${gameName}`,
				};
			}
			saveMatchHistory(match);
			navigate('/gamelost');
		}
	}

	gameWin() {
		if (this.gameMode === '6') {
			this.tournamentHandler();
		}
		else {
			this.GameIsRunning = false;
			for (let i = 0; i < 1000; i++) {}
			const match = {
				result: `Win`,
				score: `Level ${this.level}`,
				game: `Asteroids ${gameName}`,
			};
			saveMatchHistory(match);
			navigate('/gamewon');
		}
	}

	createEnvironment() {
		const envGeometry = new THREE.PlaneGeometry(this.boundaryX * 2, this.boundaryY * 2, 1, 1);
		const envMaterial = new THREE.MeshLambertMaterial({ side: THREE.DoubleSide });
		this.loader.load('/static/media/assets/mway.jpg', (texture) => {
			envMaterial.map = texture;
			envMaterial.needsUpdate = true;
			this.env = new THREE.Mesh(envGeometry, envMaterial);
			this.scene.add(this.env);	
		});
		const frameGeometry = new THREE.PlaneGeometry(this.boundaryX * 2 * 1.1, this.boundaryY * 2 * 1.2, 1, 1);
		this.loader.load('/static/media/assets/frame1.png', (frameTexture) => {
			const frameMaterial = new THREE.MeshBasicMaterial({ map: frameTexture, transparent: true, opacity: 1, depthTest: true, depthWrite: false });
			const frame = new THREE.Mesh(frameGeometry, frameMaterial);
			frame.position.set(0, 0, 15);
			this.scene.add(frame);
			frame.material.needsUpdate = true;
		});
		const levelCompleteDisp = new THREE.PlaneGeometry(170, 80, 1);
		this.loader.load('/static/media/assets/levelComplete.png', (frameTexture) => {
			const localMaterial = new THREE.MeshBasicMaterial({ map: frameTexture, transparent: true, opacity: 0, depthTest: true, depthWrite: false });
			this.lvlCompleteScreen = new THREE.Mesh(levelCompleteDisp, localMaterial);
			this.lvlCompleteScreen.position.set(0, 0, 13);
			this.scene.add(this.lvlCompleteScreen);
			this.lvlCompleteScreen.material.needsUpdate = true;
		});
	}

	createShields(player) {
		const geometry = new THREE.RingGeometry(3.1, 3.3, 20);
		const material = new THREE.MeshBasicMaterial({ color: 0x0000ff });
		const shield = new THREE.Mesh(geometry, material);
		shield.position.set(0, 0, 0);
		shield.lifetime = 100;
		shield.spawnTime = 100;
		player.add(shield);
		shield.visible = false;
		let colorIndex = 0;
		const colors = [0x0000ff, 0xff0000, 0x0000ff, 0xffffff, 0x0000ff];
		const cycleColor = () => {
			colorIndex = (colorIndex + 1) % colors.length;
			shield.material.color.setHex(colors[colorIndex]);
			setTimeout(cycleColor, 10);
		};
		cycleColor();
		return (shield);
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
				scaleValue = 0.015;
				break;
			case 2:
				scaleValue = 0.015;
				break;
			case 3:
				scaleValue = 0.018;
				break;
			case 4:
				scaleValue = 0.012;
				break;
			case 5:
				scaleValue = 0.011;
				break;
			case 6:
				scaleValue = 0.014;
				break;
			case 7:
				scaleValue = 0.018;
				break;
			case 8:
				scaleValue = 0.042;
				break;
			default:
				scaleValue = 0.011;
				break;
		}
		return (scaleValue);
	}

	createPlayer1(shipNumber) {
		let ship1Mesh = this.getShipMesh(shipNumber);
		let ship1Tex = this.getShipTex(shipNumber);
		const geometry = new THREE.BoxGeometry(3, 3, 3);
		geometry.parameters.radius = Math.sqrt(3) * 3/2;
		const material = new THREE.MeshBasicMaterial({ visible: false });
		this.player1 = new THREE.Mesh(geometry, material);
		if (this.gameMode === '2' || this.gameMode === '3' || this.gameMode === '4' || this.gameMode === '5') {
			this.player1.position.set(0, 0, 5);
		}
		else if (this.gameMode === '1' || this.gameMode === '6') {
			this.player1.position.set(-20, 0, 5);
		}
		this.player1.velocity = { x: 0, y: 0 };
		
		this.fbxloader.load(ship1Mesh, (ship) => {
			// Load the texture
			this.loader.load(ship1Tex, (texture) => {
				let trymesh = new THREE.MeshLambertMaterial({ 
					map: texture, // Apply the loaded texture
					visible: true 
				});
				let scaleValue = this.adjustShipScale(shipNumber);
				ship.scale.set(scaleValue, scaleValue, scaleValue);
				ship.rotation.x = -Math.PI / 2;
				ship.rotation.z = Math.PI;
				ship.visible = true;
				ship.castShadow = true;
				ship.receiveShadow = true;
				this.player1.add(ship);
				ship.traverse((child) => {
					if (child.isMesh) {
						child.material = trymesh;
					}
					if (child.isLight) {
						child.visible = false;
					}
				});
			});
		});
		this.scene.add(this.player1);
		this.shield1 = this.createShields(this.player1);
	}

	createPlayer2(shipNumber) {
		let ship2Mesh = this.getShipMesh(shipNumber);
		let ship2Tex = this.getShipTex(shipNumber);
		const geometry = new THREE.BoxGeometry(3, 3, 3);
		geometry.parameters.radius = Math.sqrt(3) * 3/2;
		const material = new THREE.MeshBasicMaterial({ visible: false });
		this.player2 = new THREE.Mesh(geometry, material);
		this.player2.position.set(20, 0, 5);
		this.player2.velocity = { x: 0, y: 0 };
		
		this.fbxloader.load(ship2Mesh, (ship) => {
			// Load the texture
			this.loader.load(ship2Tex, (texture) => {
				let trymesh = new THREE.MeshLambertMaterial({ 
					map: texture, // Apply the loaded texture
					visible: true 
				});
				let scaleValue = this.adjustShipScale(shipNumber);
				ship.scale.set(scaleValue, scaleValue, scaleValue);
				ship.rotation.x = -Math.PI / 2;
				ship.rotation.z = Math.PI;
				ship.visible = true;
				ship.castShadow = true;
				ship.receiveShadow = true;
				this.player2.add(ship);
				ship.traverse((child) => {
					if (child.isMesh) {
						child.material = trymesh;
					}
					if (child.isLight) {
						child.visible = false;
					}
				});
			});
		});
		this.scene.add(this.player2);
		this.shield2 = this.createShields(this.player2);
	}

	spawnAsteroid(type, position, size = 3) {
		let geometry;
		let material;
		let heightSegments;

		if (size >= 3) {
			heightSegments = 8;
		}
		else if (size == 2) {
			heightSegments = 4;
		}
		else {
			heightSegments = 3;
		}
		if (type === 'asteroid') {
			material = new THREE.MeshLambertMaterial({ map: this.loader.load('/static/media/assets/asteroid.jpg'), side: THREE.DoubleSide });
			geometry = new THREE.SphereGeometry(size, 7, heightSegments, 0, 6.283185307179586, 0, 6.283185307179586);
		}
		else if (type === 'sAsteroid') {
			geometry = new THREE.SphereGeometry(size + 0.5, 7, 8, 0, 6.28, 3.4, 6.28);
			material = new THREE.MeshLambertMaterial({ map: this.loader.load('/static/media/assets/clouds.jpg'), side: THREE.DoubleSide });
		}
		const asteroid = new THREE.Mesh(geometry, material);
		asteroid.size = size;
		if (position) {
			asteroid.position.copy(position);
		}
		else {
			const boundary = Math.floor(Math.random() * 4);
			switch (boundary) {
			case 0: // Top boundary
				asteroid.position.x = (Math.random() - 0.5) * this.boundaryX;
				asteroid.position.y = this.boundaryY;
				asteroid.position.z = 5;
				break;
			case 1: // Right boundary
				asteroid.position.x = this.boundaryX;
				asteroid.position.y = (Math.random() - 0.5) * this.boundaryY;
				asteroid.position.z = 5;
				break;
			case 2: // Bottom boundary
				asteroid.position.x = (Math.random() - 0.5) * this.boundaryX;
				asteroid.position.y = -this.boundaryY;
				asteroid.position.z = 5;
				break;
			case 3: // Left boundary
				asteroid.position.x = -this.boundaryX;
				asteroid.position.y = (Math.random() - 0.5) * this.boundaryY;
				asteroid.position.z = 5;
				break;
			}
		}
		const speed = 0.05 + Math.random() * 0.2;
		const angle = Math.random() * Math.PI * 2;
		asteroid.velocity = {
		x: Math.cos(angle) * speed,
		y: Math.sin(angle) * speed
		};
		asteroid.rotationSpeed = {
			x: Math.random() * 0.1 - 0.05,
			y: Math.random() * 0.1 - 0.05,
			z: Math.random() * 0.1 - 0.05
		};
		this.scene.add(asteroid);
		return asteroid;
	}

	spawnAsteroids(count, type) {
		for (let i = 0; i < count; i++) {
			if (type === 'asteroid') {
				this.asteroids.push(this.spawnAsteroid(type));
			} else if (type === 'sAsteroid') {
				this.sAsteroids.push(this.spawnAsteroid(type));
			}
		}
	}

	spawnAIships(count) {
		for (let n = 0; n < count; n++) {
			// Create the invisible box for collisions
			const collisionBoxGeometry = new THREE.BoxGeometry(2, 2, 2);
			collisionBoxGeometry.parameters.radius = Math.sqrt(3);
			const collisionBoxMaterial = new THREE.MeshBasicMaterial({ visible: false });
			const collisionBox = new THREE.Mesh(collisionBoxGeometry, collisionBoxMaterial);
	
			// Load the texture for the FBX model
			const texture = new THREE.TextureLoader().load('/static/media/assets/ships/ship8.png');
			const material = new THREE.MeshLambertMaterial({ map: texture });
			const loader = new THREE.FBXLoader();
			loader.load('/static/media/assets/ships/ship8.fbx', (modelAI) => {
				modelAI.scale.set(0.035, 0.035, 0.035);
				modelAI.rotation.x = -Math.PI / 2;
				modelAI.rotation.y = -Math.PI / 2;
				modelAI.rotation.z = Math.PI;
				modelAI.traverse((child) => {
					if (child.isMesh) {
						child.material = material; // Apply the texture to the model
					}
					if (child.isLight) {
						child.visible = false;
					}
				});
				collisionBox.add(modelAI);
				const speed = 0.05 + Math.random() * 0.2;
				const angle = Math.random() * Math.PI * 2;
				collisionBox.velocity = {
					x: Math.cos(angle) * speed,
					y: Math.sin(angle) * speed
				};
				collisionBox.position.set(-this.boundaryX, 0, 5);
				collisionBox.shootTimer = Math.floor(Math.random() * (200 - 60 + 1)) + 60;
				collisionBox.moveTimer = collisionBox.shootTimer;
				this.scene.add(collisionBox);
				this.AIShips.push(collisionBox);
			});
		}
	}

	spawnpowerups(count) {
		for (let n = 0; n < count; n++) {
			// Create the cylinder geometry
			const cylinderGeometry = new THREE.CylinderGeometry(0.5, 0.5, 2, 32);
			cylinderGeometry.parameters.radius = Math.sqrt(3) * 3/2;
			const cylinderMaterial = new THREE.MeshLambertMaterial({ color: 0xffffff });
			const cylinder = new THREE.Mesh(cylinderGeometry, cylinderMaterial);
			const speed = 0.05 + Math.random() * 0.2;
			const angle = Math.random() * Math.PI * 2;
			cylinder.castShadow = true;
			cylinder.receiveShadow = true;
			cylinder.velocity = {
				x: Math.cos(angle) * speed,
				y: Math.sin(angle) * speed
			};
			cylinder.position.set(
				(Math.random() - 0.5) * this.boundaryX * 2,
				(Math.random() - 0.5) * this.boundaryY * 2,
				5
			);
			cylinder.rotationSpeed = {
				x: Math.random() * 0.1 - 0.05,
				y: Math.random() * 0.1 - 0.05,
				z: Math.random() * 0.1 - 0.05
			};
			const powerupTypes = ['shield', 'tripleShot'];
			const type = powerupTypes[Math.floor(Math.random() * powerupTypes.length)];
			cylinder.type = type;
			this.scene.add(cylinder);
			this.powerups.push(cylinder);
		}
	}

	absorbPowerup(shield, powerup) {
		const type = powerup.type;
		if (type === 'shield') {
			if (shield.lifetime < 80) {
				shield.lifetime += 20;
				if (shield.lifetime > 80) {
					shield.lifetime = 80;
				}
			}
		} else if (type === 'tripleShot') {
			if (this.shotType != 2) {
				this.shotType = 2;
				this.shotType2Display.forEach(mesh => mesh.visible = true);
				this.shotType1Display.visible = false;
			}
		}
	}

	setupEventListeners() {
		this.actionStates = {
			shield1: { pressed: false },
			projectile1: { pressed: false },
			shield2: {pressed: false},
			projectile2: {pressed: false}
		};
		window.addEventListener('keydown', (event) => {
			if (event.key === ' ' && this.player1IsActive && this.unpaused) {
				if (!this.actionStates.projectile1.pressed && this.player1IsActive) {
					this.shoot(this.shotType, true, this.player1);
				}
				this.actionStates.projectile1.pressed = true;
			}
			if (event.key === 'e' && this.player1IsActive && this.shield1.lifetime > 0 && this.unpaused) {
				if (!this.actionStates.shield1.pressed) {
					this.playSound('/static/media/assets/sounds/shield.mp3', 0.4);
				}
				this.shield1.visible = true;
				this.actionStates.shield1.pressed = true;
			}
			if (this.gameMode === '1' || this.gameMode === '6') {
				if (event.key === 'o' && this.player2IsActive && this.shield2.lifetime > 0 && this.unpaused) {
					if (!this.actionStates.shield2.pressed) {
						this.playSound('/static/media/assets/sounds/shield.mp3', 0.4);
					}
					this.shield2.visible = true;
					this.actionStates.shield2.pressed = true;
				}
				if (event.key === 'p' && this.unpaused) {
					if (!this.actionStates.projectile2.pressed && this.player2IsActive) {
						this.shoot(this.shotType, true, this.player2);
					}
					this.actionStates.projectile2.pressed = true;
				}
			}
			this.keysPressed[event.key] = true;
		});
		window.addEventListener('keyup', (event) => {
			if (event.key === ' ') {
				this.actionStates.projectile1.pressed = false;
			}
			if (event.key === 'e') {
				this.actionStates.shield1.pressed = false;
				this.shield1.visible = false;
			}
			if (this.gameMode === '1' || this.gameMode === '6') {
				if (event.key === 'p') {
					this.actionStates.projectile2.pressed = false;
				}
				if (event.key === 'o') {
					this.actionStates.shield2.pressed = false;
					this.shield2.visible = false;
				}
			}
			this.keysPressed[event.key] = false;
		});
	}

	tournamentHandler() {
		if (this.tournamentOver) {
			return;	
		}
		const tournamentData = getTournamentData();
		if (!tournamentData) {
			return;
		}
		const { playerNames } = tournamentData;	
		let player1, player2;
		// Determine players for the match
		if (this.currentPlayerIndex < playerNames.length) {
			player1 = playerNames[this.currentPlayerIndex - 1];
			player2 = playerNames[this.currentPlayerIndex];
		}
		else if (this.winners.length > 1) {
			player1 = this.winners[0];
			player2 = this.winners[1];
		}
		// Determine the winner and loser
		let winner;
		let loser;
		if (this.player1Loser) {
			winner = player1;
			loser = player2;
		}
		else {
			winner = player2;
			loser = player1;
		}
		alert(`Congratulations ${winner}, you have won the match!`);
		// After player names are exhausted (moving to winners phase)
		if (this.currentPlayerIndex >= playerNames.length) {
			// Remove the loser from the winners array
			const loserIndex = this.winners.indexOf(loser);
			if (loserIndex !== -1) {
				this.winners.splice(loserIndex, 1); // Remove the loser
			}
			else {
				console.warn("Loser not found in winners array.");
			}
			// Rotate the winner to the end of the array
			if (this.winners[0] === winner) {
				// If the winner is already at the front, just move it to the end
				const rotatedWinner = this.winners.shift(); // Remove the winner from the start
				this.winners.push(rotatedWinner); // Push it to the end
			}
			else {
				// If the winner is not at the front, just push it to the end
				this.winners.push(winner);
			}
		}
		else {
			// During the initial phase, simply collect winners
			this.winners.push(winner);
		}
		// Advance tournament state
		this.currentPlayerIndex += 2;
		this.currentTournamentPlay++;
		if (this.currentTournamentPlay > this.tournamentNumberOfPlays) {
			if (this.winners.length === 1) {
				const match = {
					result: `Winner`,
					score: `${this.winners[0]}`,
					game: `Asteroids Tournament`,
				};
				saveMatchHistory(match);
				alert(`Tournament Winner: ${this.winners[0]}!`);
			}
			else {
				alert("Tournament Over. No clear winner.");
			}
			this.tournamentOver = true;
			navigate('/tournamentover');
			return;
		}
		// Reset scores and prepare for the next match
		this.clearObjects(this.asteroids);
		this.clearObjects(this.sAsteroids);
		this.clearObjects(this.AIShips);
		this.clearObjects(this.powerups);
		this.clearObjects(this.projectiles);
		this.level = 0;
		this.player1Lives = 5;
		this.player2Lives = 5;
		this.player1IsActive = true;
		this.player2IsActive = true;
		if (this.level < this.levels.length) {
			this.spawnAsteroids(this.levels[this.level].asteroids, 'asteroid');
			this.spawnAsteroids(this.levels[this.level].sAsteroids, 'sAsteroid');
			this.spawnAIships(this.levels[this.level].AIShips);
			if (this.gameType === "powered") {
				this.spawnpowerups(this.levels[this.level].powerups);
			}
			this.shield1.visible = false;
			this.shield1.spawnTime = 100;
			this.shield1.lifetime = 80;
			this.shield2.visible = false;
			this.shield2.spawnTime = 100;
			this.shield2.lifetime = 80;
			this.player1VelocityX = 0;
			this.player1VelocityY = 0;
			this.player2VelocityX = 0;
			this.player2VelocityY = 0;
			this.player1.position.set(-20, 0, 5);
			this.player2.position.set(20, 0, 5);
			this.scene.add(this.player1);
			this.scene.add(this.player2);
			this.displayLevel();
			this.displayLives1();
			this.displayLives2();
		}
		// Prepare the next match
		if (this.currentPlayerIndex < playerNames.length) {
			player1 = playerNames[this.currentPlayerIndex - 1];
			player2 = playerNames[this.currentPlayerIndex];
		} else if (this.winners.length > 1) {
			player1 = this.winners[0];
			player2 = this.winners[1];
		}
		if (player1 && player2) {
			alert(`Next Match: ${player1} vs ${player2}! Press 'T' to return to the game`);
		}
		else {
			console.log("Unable to determine next match players.");
		}
		this.unpaused = false;
	}

	playSound = (soundFilePath, volume) => {
		if (this.audioLoader) {
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
		}
	};

	shoot(method, isPlayer, player) {
		if (method === 1) {
			this.createProjectile(player, 0, isPlayer);
			this.playSound('/static/media/assets/sounds/laser7.mp3', 0.9);
		}
		else if (method === 2) {
			this.createProjectile(player, -15, isPlayer); // Left 
			this.createProjectile(player, 0, isPlayer);
			this.createProjectile(player, 15, isPlayer); // Right
			this.playSound('/static/media/assets/sounds/3shot.mp3', 1);
		}
	}

	createProjectile(origin, offsetAngle, isPlayer) {
		let proj_color = 0xff0000;
		if (!isPlayer) {
			proj_color = 0x00ff00;
		}
		const geometry = new THREE.SphereGeometry(0.3, 3, 3);
		const material = new THREE.MeshBasicMaterial({ color: proj_color });
		const laser = new THREE.Mesh(geometry, material);
		laser.scale.set(0.4, 1, 2);
		laser.position.x = origin.position.x;
		laser.position.y = origin.position.y;
		laser.position.z = origin.position.z;
		let playerAngle = origin.rotation.z + THREE.Math.degToRad(offsetAngle);
		laser.rotation.z = playerAngle;
		const speed = 2;
		laser.lifetime = 30;
		if (isPlayer === true) {
			laser.isPlayer = true;
			laser.velocity = {
				x: Math.sin(playerAngle) * speed,
				y: -Math.cos(playerAngle) * speed
			};
		}
		else {
			laser.isPlayer = false;
			let playerAngle = origin.rotation.z + THREE.Math.degToRad(offsetAngle + 90);
			laser.rotation.z = playerAngle;
			laser.velocity = {
				x: Math.sin(playerAngle) * speed,
				y: -Math.cos(playerAngle) * speed
			};
			this.playSound('/static/media/assets/sounds/laser7.mp3', 0.9);
		}
		this.scene.add(laser);
		this.projectiles.push(laser);
	}

	checkCollision(object1, object2) {
		const distance = object1.position.distanceTo(object2.position);
		return (distance < (object1.geometry.parameters.radius + object2.geometry.parameters.radius));
	}

	checkBoundaries(object) {
		const offset = 5; // Define an offset to move the object beyond the boundary
	
		if (object.position.x > this.boundaryX + offset) {
			object.position.x = -this.boundaryX - offset;
		} else if (object.position.x < -this.boundaryX - offset) {
			object.position.x = this.boundaryX + offset;
		}
	
		if (object.position.y > this.boundaryY + offset) {
			object.position.y = -this.boundaryY - offset;
		} else if (object.position.y < -this.boundaryY - offset) {
			object.position.y = this.boundaryY + offset;
		}
	}

	player1Death() {
		this.playSound('/static/media/assets/sounds/explosion2.mp3', 2);
		this.scene.remove(this.player1);
		this.player1Lives--;
		if (this.checkLives()) {
			this.player1IsActive = false;
			if (this.player1Lives <= 0) {
				return;
			}
			setTimeout(() => {
				this.scene.add(this.player1);
				this.player1IsActive = true;
				this.shield1.visible = true;
				this.playSound('/static/media/assets/sounds/shield.mp3', 0.4)
				this.shield1.spawnTime = 100;
				if (this.shield1.lifetime < 40) {
					this.shield1.lifetime = 80;
				}
			}, 2000);
			this.player1VelocityX = 0;
			this.player1VelocityY = 0;
			this.player1.position.set(0, 0, 5);
			if (this.gameMode === '1' || this.gameMode === '6') {
				this.player1.position.set(-20, 0, 5);
			}
		}
	}

	player2Death() {
		this.playSound('/static/media/assets/sounds/explosion2.mp3', 2);
		this.scene.remove(this.player2);
		this.player2Lives--;
		if (this.checkLives()) {
			this.player2IsActive = false;
			if (this.player2Lives <= 0) {
				return;
			}
			setTimeout(() => {
				this.scene.add(this.player2);
				this.player2IsActive = true;
				this.shield2.visible = true;
				this.playSound('/static/media/assets/sounds/shield.mp3', 0.4)
				this.shield2.spawnTime = 100;
				if (this.shield2.lifetime < 40) {
					this.shield2.lifetime = 80;
				}
			}, 2000);
			this.player2VelocityX = 0;
			this.player2VelocityY = 0;
			this.player2.position.set(20, 0, 5);
		}
	}

	createShotDisplay() {
		const geometry = new THREE.PlaneGeometry(0.3, 1);
		const material = new THREE.MeshBasicMaterial({ color: 0xff0000 });
	
		this.shotType1Display = new THREE.Mesh(geometry, material);
		this.shotType1Display.scale.set(0.8, 2, 4);
		this.shotType1Display.position.set(36, this.boundaryY + 2, 16);
		this.scene.add(this.shotType1Display);
	
		this.shotType2Display = [];
		const positions = [
			{ x: 39, y: this.boundaryY + 2, z: 16 },
			{ x: 39.5, y: this.boundaryY + 2, z: 16 },
			{ x: 40, y: this.boundaryY + 2, z: 16 }
		];
		positions.forEach(pos => {
			const mesh = new THREE.Mesh(geometry, material);
			mesh.scale.set(0.8, 2, 4);
			mesh.position.set(pos.x, pos.y, pos.z);
			mesh.visible = false;
			this.scene.add(mesh);
			this.shotType2Display.push(mesh);
		});
	}

	displayLives1() {
		for (let i = 0; i < 4; i++) {
			const imageGeometry = new THREE.PlaneGeometry(7,7,7);
			this.loader.load('/static/media/assets/lives.png', (livesTex) => {
				const imageMaterial = new THREE.MeshBasicMaterial({ map: livesTex, transparent: true, opacity: 1, depthTest: true, depthWrite: false });
				const LivesImage = new THREE.Mesh(imageGeometry, imageMaterial);
				if (this.gameMode === '2' || this.gameMode === '3' || this.gameMode === '4' || this.gameMode === '5') {
					LivesImage.position.set(i * 5 - 7.5, -44, 16);
				}
				else if (this.gameMode === '1' || this.gameMode === '6') {
					LivesImage.position.set(i * -4 - 5, -44, 16); // needs adjusting!
				}
				this.scene.add(LivesImage);
				this.lives1.push(LivesImage);
				LivesImage.material.needsUpdate = true;
			});
		}
	}

	displayLives2() {
		for (let i = 0; i < 4; i++) {
			const imageGeometry = new THREE.PlaneGeometry(7,7,7);
			this.loader.load('/static/media/assets/lives.png', (livesTex) => {
				const imageMaterial = new THREE.MeshBasicMaterial({ map: livesTex, transparent: true, opacity: 1, depthTest: true, depthWrite: false });
				const LivesImage = new THREE.Mesh(imageGeometry, imageMaterial);
				LivesImage.position.set(i * 4 + 5, -44, 16); // needs adjusting!!
				this.scene.add(LivesImage);
				this.lives2.push(LivesImage);
				LivesImage.material.needsUpdate = true;
			});
		}
	}

	checkLives() {
		if (this.gameMode === '2' || this.gameMode === '3' || this.gameMode === '4' || this.gameMode === '5') {
			if (this.player1Lives <= 0) {
				this.gameOver();
				return 0;
			}
			else if (this.lives1.length >= this.player1Lives) {
				if (this.lives1.length > 0) {
					const life = this.lives1.pop();
					this.scene.remove(life);
					life.geometry.dispose();
					life.material.dispose();
				}
			}  
			return 1;
		}
		else if (this.gameMode === '1' || this.gameMode === '6') {
			if ((this.player1Lives <= 0 || this.player2Lives <= 0) && this.playerHasLost === false) {
				this.playerHasLost = true;
				if (this.player1Lives <= 0) {
					this.player1Loser = true;
				}
				else {
					this.player1Loser = false;
				}
			}
			if (this.player1Lives <= 0 && this.player2Lives <= 0) {
				this.gameOver();
				return 0;
			}
			if (this.lives1.length >= this.player1Lives) {
				if (this.lives1.length > 0) {
					const life1 = this.lives1.pop();
					this.scene.remove(life1);
					life1.geometry.dispose();
					life1.material.dispose();
				}
			}
			if (this.lives2.length >= this.player2Lives) {
				if (this.lives2.length > 0) {
					const life2 = this.lives2.pop();
					this.scene.remove(life2);
					life2.geometry.dispose();
					life2.material.dispose();
				}
			}
			return 1;
		}
	}

	displayShieldBar1() {
		const box1Geometry = new THREE.PlaneGeometry(13, 1.5);
		const box1Material = new THREE.MeshBasicMaterial({ color: 0x808080})
		this.shieldBarBox1 = new THREE.Mesh(box1Geometry, box1Material);
		this.shieldBarBox1.position.set(this.boundaryX - 13, this.boundaryY + 2.5, 16);
		this.scene.add(this.shieldBarBox1);
		const barGeometry = new THREE.PlaneGeometry(10, 1);
		const barMaterial = new THREE.MeshBasicMaterial({ color: 0x00ff00 });
		this.shieldBar1 = new THREE.Mesh(barGeometry, barMaterial);
		this.shieldBar1.position.set(this.boundaryX - 13, this.boundaryY + 2.5, 17);
		this.scene.add(this.shieldBar1);
	}

	displayShieldBar2() {
		const box1Geometry = new THREE.PlaneGeometry(13, 1.5);
		const box1Material = new THREE.MeshBasicMaterial({ color: 0x808080})
		this.shieldBarBox2 = new THREE.Mesh(box1Geometry, box1Material);
		this.shieldBarBox2.position.set(this.boundaryX - 13, this.boundaryY - 0.5, 16);
		this.scene.add(this.shieldBarBox2);
		const barGeometry = new THREE.PlaneGeometry(10, 1);
		const barMaterial = new THREE.MeshBasicMaterial({ color: 0xff0000 });
		this.shieldBar2 = new THREE.Mesh(barGeometry, barMaterial);
		this.shieldBar2.position.set(this.boundaryX - 13, this.boundaryY - 0.5, 17);
		this.scene.add(this.shieldBar2);
	}
	
	displayLevel() {
		const geometry = new THREE.PlaneGeometry(0.4, 1);
		const material = new THREE.MeshBasicMaterial({ color: 0xffffff });
	
		if (this.level > 0) {
				this.levelDisplay = new THREE.Mesh(geometry, material);
				this.levelDisplay.scale.set(0.8, 2, 4);
				this.levelDisplay.position.set(this.level - this.boundaryX + 7, this.boundaryY + 2, 16);
				this.scene.add(this.levelDisplay);
		}
	}

	levelUp() {
		this.clearObjects(this.asteroids);
		this.clearObjects(this.sAsteroids);
		this.clearObjects(this.AIShips);
		this.clearObjects(this.powerups);
		this.clearObjects(this.projectiles);
		this.level++;
		this.shield1.visible = false;
		this.shield1.spawnTime = 100;
		if (this.level < this.levels.length) {
			this.spawnAsteroids(this.levels[this.level].asteroids, 'asteroid');
			this.spawnAsteroids(this.levels[this.level].sAsteroids, 'sAsteroid');
			this.spawnAIships(this.levels[this.level].AIShips);
			this.spawnpowerups(this.levels[this.level].powerups);
			this.player1VelocityX = 0;
			this.player1VelocityY = 0;
			if (this.gameMode === '2' || this.gameMode === '3' || this.gameMode === '4' || this.gameMode === '5') {
				this.player1.position.set(0, 0, 5);
			}
			else if (this.gameMode === '1' || this.gameMode === '6') {
				this.player2VelocityX = 0;
				this.player2VelocityY = 0;
				this.shield2.visible = false;
				this.shield2.spawnTime = 100;
				this.player1.position.set(-20, 0, 5);
				this.player2.position.set(20, 0, 5);
			}
			if (this.lvlCompleteScreen) {
				this.lvlCompleteScreen.material.opacity = 0;
				this.nextLevelTimer = 0;
			}
			else {
				console.warn("cannot find lvlCompleteScreen");
			}
			this.displayLevel();
		}
		else {
			this.gameWin();
		}
	}
	
	clearObjects(objectArray) {
		objectArray.forEach((object) => {
			this.scene.remove(object);
			if (object.geometry) object.geometry.dispose();
			if (object.material) object.material.dispose();
		});
		objectArray.length = 0; // Clear the array
	}

	checkLevelComplete() {
		if (this.asteroids.length === 0 && this.AIShips.length === 0) {
			if (this.lvlCompleteScreen) {
				this.lvlCompleteScreen.material.opacity += 0.02;
			}
			this.shield1.visible = true;
			if (this.gameMode === '1' || this.gameMode === '6') {
				this.shield2.visible = true;
			}
			this.nextLevelTimer++;
			if (this.nextLevelTimer === 200) {
				this.lvlCompleteScreen.material.opacity = 0;
				this.levelUp();
			}
		}
	}

	updateExplosion() {
		for (let i = this.explosionGroup.length - 1; i >= 0; i--) {
			const explosion = this.explosionGroup[i];
			explosion.lifetime--;
			for (let j = explosion.particles.length - 1; j >= 0; j--) {
				const particle = explosion.particles[j];
				particle.position.add(particle.velocity);

				particle.material.opacity = explosion.lifetime / 10;
				particle.material.needsUpdate = true;
				if (particle.position.x < -this.boundaryX || particle.position.x > this.boundaryX || particle.position.y < -this.boundaryY || particle.position.y > this.boundaryY) {
					this.scene.remove(particle);
					particle.geometry.dispose();
					particle.material.dispose();
					explosion.particles.splice(j, 1);
				}
			}
			if (explosion.lifetime <= 0) {
				explosion.particles.forEach(particle => {
					this.scene.remove(particle);
					particle.geometry.dispose();
					particle.material.dispose();
				});
				this.explosionGroup.splice(i, 1);
			}
		}
	}

	createExplosion(x, y, size) {
		const explosion = {
			particles: [],
			lifetime: 60 // Adjust the lifetime as needed
		};
		const numParticles = Math.floor(Math.random() * 5) + 4 + size;
		const colors = [0xffffff, 0xffff00, 0xff0000];
		for (let i = 0; i < numParticles; i++) {
			const particleSize = Math.random() * 0.2 + 0.1;
			const particleSpeed = Math.random() * 0.4 + 0.6;
			const color = colors[Math.floor(Math.random() * colors.length)];
	
			const particle = new THREE.Mesh(
				new THREE.PlaneGeometry(particleSize, particleSize),
				new THREE.MeshBasicMaterial({ color: color, transparent: true })
			);
			particle.position.set(
				x + (Math.random() - 0.5) * 0.1,
				y + (Math.random() - 0.5) * 0.1,
				5 // Fixed z position
			);
			particle.velocity = new THREE.Vector3(
				(Math.random() - 0.5) * particleSpeed,
				(Math.random() - 0.5) * particleSpeed,
				0
			);
			explosion.particles.push(particle);
			this.scene.add(particle);
		}
	
		this.explosionGroup.push(explosion);
	}

	animate() {
		if (this.keysPressed['t']) {
			if (this.unpaused) {
				this.unpaused = false;
				this.pauseCube.visible = true;
			}
			else {
				this.unpaused = true;
				this.pauseCube.visible = false;
			}
			this.keysPressed['t'] = false;
		}
		if (this.unpaused === false) {
			if (this.pauseCube) {
				this.pauseCube.rotation.x += 0.1;
				this.pauseCube.rotation.y += 0.1;
			}
		}
		else {
			if (this.GameIsRunning === false) {
				cancelAnimationFrame(this.animate);
				return;
			}
			if (this.env) {
				if (this.env.position.x > this.boundaryX) {
					this.env.position.x = -this.boundaryX;
				}
				else if (this.env.position.x < -this.boundaryX) {
					this.env.position.x = this.boundaryX;
				}
				if (this.env.position.y > this.boundaryY) {
					this.env.position.y = -this.boundaryY;
				}
				else if (this.env.position.y < -this.boundaryY) {
					this.env.position.y = this.boundaryY;
				}
			}
			if (this.gameMode === '1' || this.gameMode === '6') {
				if (this.player2IsActive) {
					if (this.keysPressed['j']) {
						this.player2.rotation.z += 0.05;
					}
					else if (this.keysPressed['l']) {
						this.player2.rotation.z -= 0.05;
					}
					if (this.keysPressed['i']) {
						const directionX = Math.sin(this.player2.rotation.z);
						const directionY = -Math.cos(this.player2.rotation.z);
						this.player2VelocityX += directionX * 0.02;
						this.player2VelocityY += directionY * 0.02;
						const speed = Math.sqrt(this.player2VelocityX * this.player2VelocityX + this.player2VelocityY * this.player2VelocityY);
						if (speed > this.maxSpeed) {
							const normalizationFactor = this.maxSpeed / speed;
							this.player2VelocityX *= normalizationFactor;
							this.player2VelocityY *= normalizationFactor;
						}
					}
					if (this.keysPressed['o'] && this.shield2.lifetime > 0) {
						this.shield2.lifetime--;
					}
					else if (this.shield2.lifetime === 0) {
						this.shield2.visible = false;
					}
					if (!this.shield2.visible) {
						for (let i = this.asteroids.length - 1; i >= 0; i--) {
							const asteroid = this.asteroids[i];
							if (this.checkCollision(this.player2, asteroid)) {
								this.createExplosion(this.player2.position.x, this.player2.position.y, 2);
								this.player2Death();
								break;
							}
						}
						for (let i = this.sAsteroids.length - 1; i >= 0; i--) {
							const sAsteroid = this.sAsteroids[i];
							if (this.checkCollision(this.player2, sAsteroid)) {
								this.createExplosion(this.player2.position.x, this.player2.position.y, 3);
								this.player2Death();
								break;
							}
						}
					}
					else {
						for (let i = this.asteroids.length - 1; i >= 0; i--) {
							const asteroid = this.asteroids[i];
							if (this.checkCollision(this.player2, asteroid)) {
								this.createExplosion(this.player2.position.x, this.player2.position.y, 2);
								break;
							}
						}
						for (let i = this.sAsteroids.length - 1; i >= 0; i--) {
							const sAsteroid = this.sAsteroids[i];
							if (this.checkCollision(this.player2, sAsteroid)) {
								this.createExplosion(this.player2.position.x, this.player2.position.y, 3);
								this.player2VelocityX += sAsteroid.velocity.x * 0.5; // Adjust the factor as needed
								this.player2VelocityY += sAsteroid.velocity.y * 0.5; // Adjust the factor as needed
								if (this.player2VelocityX > 0.5) {
									this.player2VelocityX = 0.5;
								}
								if (this.player2VelocityY > 0.5) {
									this.player2VelocityY = 0.5;
								}
								break;
							}
						}
					}
				}
				if (this.shield2.spawnTime > 0) {
					this.shield2.spawnTime--;
					if (this.shield2.spawnTime === 0) {
						this.shield2.visible = false;
					}
				}
				if (this.shieldBar2) {
					this.shieldBar2.scale.x = this.shield2.lifetime / 80;
				}
				this.player2.position.x += this.player2VelocityX;
				this.player2.position.y += this.player2VelocityY;
				this.checkBoundaries(this.player2);
	
	
			}
			if (this.player1IsActive) {
				/* if (this.keysPressed['f']) {
					this.keysPressed['f'] = false;
					if (this.shotType === 1) {
						this.shotType = 2;
						this.shotType2Display.forEach(mesh => mesh.visible = true);
						this.shotType1Display.visible = false;
					}
					else if (this.shotType === 2) {
						this.shotType = 1;
						this.shotType1Display.visible = true;
						this.shotType2Display.forEach(mesh => mesh.visible = false);
					}
				} */
				if (this.keysPressed['a']) {
					this.player1.rotation.z += 0.05;
				}
				else if (this.keysPressed['d']) {
					this.player1.rotation.z -= 0.05;
				}
				if (this.keysPressed['w']) {
					const directionX = Math.sin(this.player1.rotation.z);
					const directionY = -Math.cos(this.player1.rotation.z);
					this.player1VelocityX += directionX * 0.02;
					this.player1VelocityY += directionY * 0.02;
					const speed = Math.sqrt(this.player1VelocityX * this.player1VelocityX + this.player1VelocityY * this.player1VelocityY);
					if (speed > this.maxSpeed) {
						const normalizationFactor = this.maxSpeed / speed;
						this.player1VelocityX *= normalizationFactor;
						this.player1VelocityY *= normalizationFactor;
					}
				}
				if (this.keysPressed['e'] && this.shield1.lifetime > 0) {
					this.shield1.lifetime--;
				}
				else if (this.shield1.lifetime === 0) {
					this.shield1.visible = false;
				}
				if (this.AIShips) {
					this.AIShips.forEach(ship => {
						if (ship.shootTimer > 0) {
							ship.shootTimer--;
						}
						if (ship.moveTimer > 0) {
							ship.moveTimer--;
						}
						if (ship.shootTimer === 0) {
							this.createProjectile(ship, 0, 0);
							ship.shootTimer = Math.floor(Math.random() * (200 - 60 + 1)) + 60;
						}
						if (ship.moveTimer === 0) {
							const randomFactorX = (Math.random() < 0.5 ? -1 : 1) * 0.05;
							const randomFactorY = (Math.random() < 0.5 ? -1 : 1) * 0.05;
							ship.velocity.x += randomFactorX;
							ship.velocity.y += randomFactorY;
							if (ship.velocity.x > 0.7) {
								ship.velocity.x = 0.7;
							}
							if (ship.velocity.y > 0.7) {
								ship.velocity.y = 0.7;
							}
							ship.moveTimer = 100;
						}
					});
				}
				if (!this.shield1.visible) {
					for (let i = this.asteroids.length - 1; i >= 0; i--) {
						const asteroid = this.asteroids[i];
						if (this.checkCollision(this.player1, asteroid)) {
							this.createExplosion(this.player1.position.x, this.player1.position.y, 2);
							this.player1Death();
							break;
						}
					}
					for (let i = this.sAsteroids.length - 1; i >= 0; i--) {
						const sAsteroid = this.sAsteroids[i];
						if (this.checkCollision(this.player1, sAsteroid)) {
							this.createExplosion(this.player1.position.x, this.player1.position.y, 3);
							this.player1Death();
							break;
						}
					}
				}
				else {
					for (let i = this.asteroids.length - 1; i >= 0; i--) {
						const asteroid = this.asteroids[i];
						if (this.checkCollision(this.player1, asteroid)) {
							this.createExplosion(this.player1.position.x, this.player1.position.y, 2);
	
							break;
						}
					}
					for (let i = this.sAsteroids.length - 1; i >= 0; i--) {
						const sAsteroid = this.sAsteroids[i];
						if (this.checkCollision(this.player1, sAsteroid)) {
							this.createExplosion(this.player1.position.x, this.player1.position.y, 3);
							this.player1VelocityX += sAsteroid.velocity.x * 0.5; // Adjust the factor as needed
							this.player1VelocityY += sAsteroid.velocity.y * 0.5; // Adjust the factor as needed
							if (this.player1VelocityX > 0.5) {
								this.player1VelocityX = 0.5;
							}
							if (this.player1VelocityY > 0.5) {
								this.player1VelocityY = 0.5;
							}
							break;
						}
					}
				}
			}
			if (this.powerups) {
				for (let i = 0; i < this.powerups.length; i++) {
					const powerup = this.powerups[i];
					powerup.position.x += powerup.velocity.x;
					powerup.position.y += powerup.velocity.y;
					powerup.rotation.x += powerup.rotationSpeed.x;
					powerup.rotation.y += powerup.rotationSpeed.y;
					powerup.rotation.z += powerup.rotationSpeed.z;
					this.checkBoundaries(powerup);
					if (this.checkCollision(this.player1, powerup)) {
						this.absorbPowerup(this.shield1, powerup);
						this.scene.remove(powerup);
						this.powerups.splice(i, 1);
						i--;
					}
					if (this.gameMode === '1' || this.gameMode === '6') {
						if (this.checkCollision(this.player2, powerup)) {
							this.absorbPowerup(this.shield2, powerup);
							this.scene.remove(powerup);
							this.powerups.splice(i, 1);
							i--;
						}
					}
				}
			}
			this.checkLevelComplete();
			if (this.shield1.spawnTime > 0) {
				this.shield1.spawnTime--;
				if (this.shield1.spawnTime === 0) {
					this.shield1.visible = false;
				}
			}
			if (this.shieldBar1) {
				this.shieldBar1.scale.x = this.shield1.lifetime / 80;
			}
			this.player1.position.x += this.player1VelocityX;
			this.player1.position.y += this.player1VelocityY;
			this.checkBoundaries(this.player1);
			this.AIShips.forEach(collisionBox => {
				collisionBox.position.x += collisionBox.velocity.x;
				collisionBox.position.y += collisionBox.velocity.y;
				const player1Position = new THREE.Vector3(this.player1.position.x, this.player1.position.y, this.player1.position.z);
				if (this.gameMode === '1' || this.gameMode === '6') {
					const player2Position = new THREE.Vector3(this.player2.position.x, this.player2.position.y, this.player2.position.z);
					let targetPosition = null;
					if (this.player1IsActive && this.player2IsActive) {
						const distanceToPlayer1 = collisionBox.position.distanceTo(player1Position);
						const distanceToPlayer2 = collisionBox.position.distanceTo(player2Position);
						if (distanceToPlayer1 < distanceToPlayer2) {
							targetPosition = player1Position;
						}
						else {
							targetPosition = player2Position;
						}
					}
					else if (this.player1IsActive) {
						targetPosition = player1Position;
					}
					else if (this.player2IsActive) {
						targetPosition = player2Position;
					}
					if (targetPosition) {
						const direction = new THREE.Vector3().subVectors(targetPosition, collisionBox.position).normalize();
						const angleToTarget = Math.atan2(direction.y, direction.x);
						collisionBox.rotation.z = angleToTarget;
					}
				}
				else {
					if (this.player1IsActive) {
						const direction = new THREE.Vector3().subVectors(player1Position, collisionBox.position).normalize();
						const angleToPlayer1 = Math.atan2(direction.y, direction.x);
						collisionBox.rotation.z = angleToPlayer1;
					}
				}
				this.checkBoundaries(collisionBox);
			});
			this.asteroids.forEach(sphere => {
				sphere.position.x += sphere.velocity.x;
				sphere.position.y += sphere.velocity.y;
				sphere.rotation.x += sphere.rotationSpeed.x;
				sphere.rotation.y += sphere.rotationSpeed.y;
				sphere.rotation.z += sphere.rotationSpeed.z;
				this.checkBoundaries(sphere);
			});
			this.sAsteroids.forEach(sphere => {
				sphere.position.x += sphere.velocity.x;
				sphere.position.y += sphere.velocity.y;
				sphere.rotation.x += sphere.rotationSpeed.x;
				sphere.rotation.y += sphere.rotationSpeed.y;
				sphere.rotation.z += sphere.rotationSpeed.z;
				this.checkBoundaries(sphere);
			});
			if (this.explosionGroup.length > 0)
				this.updateExplosion();
			// projectilewise code
			for (let i = this.projectiles.length - 1; i >= 0; i--) {
				const projectile = this.projectiles[i];
				projectile.position.x += projectile.velocity.x;
				projectile.position.y += projectile.velocity.y;
				this.checkBoundaries(projectile);
				projectile.lifetime--;
				// Asteroid checks
				for (let j = this.asteroids.length - 1; j >= 0; j--) {
					const asteroid = this.asteroids[j];
					if (this.checkCollision(projectile, asteroid)) {
						this.playSound('/static/media/assets/sounds/explosion.mp3', 2);
						this.createExplosion(asteroid.position.x, asteroid.position.y, 5);
						if (asteroid.size > 1) {
							asteroid.size -= 1;
							for (let k = 0; k < 3; k++) {
								const newAsteroid = this.spawnAsteroid('asteroid', asteroid.position, asteroid.size);
								newAsteroid.size = asteroid.size; // Set the size of the new asteroids
								this.asteroids.push(newAsteroid);
							}
						}
						this.scene.remove(asteroid);
						this.asteroids.splice(j, 1);
						this.scene.remove(projectile);
						this.projectiles.splice(i, 1);
						break;
					}
				}
				for (let j = this.sAsteroids.length - 1; j >= 0; j--) {
					const sAsteroid = this.sAsteroids[j];
					if (this.checkCollision(projectile, sAsteroid)) {
						this.playSound('/static/media/assets/sounds/hit.mp3', 0.3);
						sAsteroid.velocity.x += projectile.velocity.x * 0.2;
						sAsteroid.velocity.y += projectile.velocity.y * 0.2;
						this.scene.remove(projectile);
						this.projectiles.splice(i, 1);
						break;
					}
				}
				// AI checks
				if (projectile.isPlayer === true) {
					for (let j = this.AIShips.length - 1; j >= 0; j--) {
						const AIShip = this.AIShips[j];
						if (this.checkCollision(projectile, AIShip)) {
							this.playSound('/static/media/assets/sounds/explosion.mp3', 2);
							this.createExplosion(AIShip.position.x, AIShip.position.y, 3);
							this.scene.remove(AIShip);
							this.AIShips.splice(j, 1);
							this.scene.remove(projectile);
							this.projectiles.splice(i, 1);
							break;
						}
					}
				}
				else {
					if (this.gameMode === '1' || this.gameMode === '6') {
						if (this.checkCollision(projectile, this.player2) && !this.shield2.visible) {
							this.player2Death();
							this.scene.remove(projectile);
							this.projectiles.splice(i, 1);
						}
						else if (this.checkCollision(projectile, this.player2) && this.shield2.visible) {
							this.scene.remove(projectile);
							this.projectiles.splice(i, 1);
						}
					}
					if (this.checkCollision(projectile, this.player1) && !this.shield1.visible) {
						this.player1Death();
						this.scene.remove(projectile);
						this.projectiles.splice(i, 1);
					}
					else if (this.checkCollision(projectile, this.player1) && this.shield1.visible) {
						this.scene.remove(projectile);
						this.projectiles.splice(i, 1);
					}
				}
				if (projectile.lifetime <= 0) {
					this.scene.remove(projectile);
					this.projectiles.splice(i, 1);
				}
			}
		}
		this.renderer.render(this.scene, this.camera);
		this.animationFrameID = requestAnimationFrame(this.animate);
	}
}

export default function Asteroids(gameMode, gameType) {
	if (gameMode === '1') {
		gameName = 'Player vs Player';
	}
	else {
		gameName = 'Play vs AI';
	}
	const game = new Game(gameMode, gameType);
	game.fetchShipAndColor().then(() => {
		game.init();
	});
	return game;
}