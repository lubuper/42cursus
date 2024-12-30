import { navigate } from '../../helpers/App.js';
import { calculateRankedStats } from './Dashboard.js';
export let selectedGameType = 'Pong';
export let selectedGameID = null;
export let otherPlayer = null;
export let senderPlayer = null;

export async function sendInvitation(sender, receiver, gameName) {
	const response = await fetch('/send-game-invitation/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/x-www-form-urlencoded',
			'X-CSRFToken': getCSRFToken(),
		},
		body: JSON.stringify({
			'username': receiver,
			'game_name': gameName
		})
	})

		const resultGame = await response.json();
		selectedGameID = resultGame.game_id;
		senderPlayer = sender;
		otherPlayer = receiver;
		return resultGame;
}

const base = `
			<div class="vh-100 d-flex flex-column align-items-center justify-content-center position-relative">
                <div class="card bg-dark text-white mb-3" style="width: 400px;">
                <div class="card-body text-center">
                <img src="/static/media/sadAlien.jpg"
                     alt="Sad Alien"
                     style="width: 300px; height: 300px; border-radius: 10px; margin-bottom: 20px;">
                <h5 class="card-title">You must be logged to play remote!</h5>
                </div>
                </div>
                <div class="d-flex">
						<button class="btn btn-purple btn-lg mt-3 nav-link text-white shadow-lg me-3" data-path="/login">Login</button>
						<button class="btn btn-purple btn-lg mt-3 nav-link text-white shadow-lg me-3" data-path="/createaccount">Create Account</button>
						<button class="btn btn-purple btn-lg text-white shadow-lg mt-3 custom-button" onclick="window.history.back()">Go Back To HomePage</button>
				</div>
            </div>
			`;

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

export async function getDataRemote() {
		const response = await fetch('/api/get-data-remote/');
		if (!response.ok) {
			const resp = await  response.json();
			throw new Error(resp.error);
		}
		const dataRemote = await response.json();
		return dataRemote;
}

export default function RemotePlay() {
	selectedGameType = 'Pong';
	const $games = document.createElement('div');
	getDataRemote().then(dataRemote => {

		let currentGameRank = calculateRankedStats(dataRemote.match_history, "Pong Remote");
	$games.addEventListener('change', (event) => {
		if (event.target.name === 'gameType') {
			event.preventDefault();
			selectedGameType = document.querySelector('input[name="gameType"]:checked').value;
		}
	});

		$games.innerHTML = `
		<div class="container vh-100 d-flex flex-column align-items-center justify-content-start pt-3">
			<!-- Send invitation -->
			<div class="row w-100 mb-3">
				<div class="col-md-6 d-flex align-items-stretch">
					<div class="card bg-dark text-white w-100" style="border: 1px solid #343a40; opacity: 0.8;">
						<div class="card-body">
							<h5 class="card-title text-center">Play with a stranger</h5>
								<div class="d-flex justify-content-center mt-4" id="currentGameRank">
								<p class="card-text">
									Your rank:
									<img src="/static/media/rank/${currentGameRank.rank}.png"
										alt="${currentGameRank.rank}"
										style="width: 64px; height: 64px; margin-right: 2px;">
									${currentGameRank.rank}
								</p>
								</div>
								<div class="d-flex justify-content-center mt-4">
									<button class="btn btn-purple btn-lg mx-5 text-white shadow-lg" id="startGameByRank">Start Game</button>
								</div>
								<div class="card-body" id="returned-message-by-rank"></div>
						</div>
					</div>
				</div>
				<div class="col-md-6 text-center d-flex flex-column align-items-center">
					<img src="/static/media/assets/pongsplash.png" alt="Pong Game" class="img-fluid" style="width: 100%; height: auto;">
				</div>
			</div>
			<div class="row w-100 mb-3">
				<!-- invitations -->
				<div class="col-md-6 d-flex align-items-stretch">
					<div class="card bg-dark text-white w-100" style="border: 1px solid #343a40; opacity: 0.8;">
						<div class="card-body">
							<h5 class="card-title text-center">Invite other user</h5>
							<form id="send-friend-invitation">
								<input type="text" class="form-control mb-3" id="playerNameInvitation" name="username" placeholder="Enter Player Name" required>
								<div id="playerNamesContainer" class="mt-3"></div>
								<div class="d-flex justify-content-center mt-4">
									<button class="btn btn-purple btn-lg mx-5 text-white shadow-lg" id="startRemoteGame">Start Game</button>
								</div>
								<div class="card-body" id="returned-message"></div>
							</form>
						</div>
					</div>
				</div>
				<div class="col-md-6 d-flex align-items-stretch">
					<div class="card bg-dark text-white w-100" style="border: 1px solid #343a40; opacity: 0.8;">
						<div class="card-body">
						<h5 class="card-title text-center">How To Play</h5>
							<div class="card-text">
								<div class="row">
									<div class="text-center">
										<ul class="list-unstyled">
											<li><i class="fas fa-arrow-left"></i> Move left/top: A</li>
											<li><i class="fas fa-arrow-right"></i> Move right/bottom: D</li>
											<li><i class="fas fa-camera"></i> Cameras toggle: C</li>
										</ul>
									</div>
								</div>
							</div>
						</div>
					</div>
				</div>
			</div>
			<!-- Game Especifications -->
			<div class="row w-100 mb-3">
				<!-- Pong Section -->
				<div class="col-md-6 d-flex align-items-stretch">
					<div class="card bg-dark text-white w-100" style="border: 1px solid #343a40; opacity: 0.8;">
						<div class="card-body">
							<h5 class="card-title text-center">Invitations</h5>
								<div class="card-body">
								${dataRemote.remote_game_invitations.length > 0 ?
										dataRemote.remote_game_invitations.map(remote_game_invitations => `
										<p>${remote_game_invitations.sender__user__username} #${remote_game_invitations.game_id}
										<button id="AcceptRequest-${remote_game_invitations.game_id}" value="${remote_game_invitations.game_id}" type="button" class="btn btn-success btn-sm ml-2">✔️</button>
										<button id="RejectRequest-${remote_game_invitations.game_id}" value="${remote_game_invitations.game_id}" type="button" class="btn btn-danger btn-sm ml-2">X</button>
										</p>
									`).join('') :
								'<p>You currently have no game invitations.</p>'
								}
								</div>
						</div>
					</div>
				</div>
			</div>
		</div>
	`;

	document.getElementById('startGameByRank').addEventListener('click', async function() {
			event.preventDefault();

		const returnedMessageByRank = document.getElementById('returned-message-by-rank');
		const response = await fetch('/start-game-by-rank/', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/x-www-form-urlencoded', // or 'application/json'
				'X-CSRFToken': getCSRFToken(), // Make sure you include your CSRF token
			},
			body: JSON.stringify({
				'username': dataRemote.username,
				'game_name': selectedGameType,
				'rank': currentGameRank.rank
			})
		})
		const result = await response.json();

		if (response.ok) {
				returnedMessageByRank.innerHTML = '<p class="text-success">Game invitation sent successfully!</p>';
				setTimeout(() => {
					returnedMessageByRank.innerHTML = '<p </p>';
				}, 2000);
				if (result.message === 'Game invitation found successfully!') {
					selectedGameID = result.game_id;
					senderPlayer = result.sender;
					otherPlayer = dataRemote.username;
				} else if (result.message === 'Game created successfully!') {
					selectedGameID = result.game_id;
					senderPlayer = dataRemote.username;
					otherPlayer = null;
				}
				if (selectedGameType === 'Pong') {
					navigate('/pongremote');
				}
		} else {
				returnedMessageByRank.innerHTML = `<p class="text-danger">Failed to send game invitation! ${result.message} </p>`;
				setTimeout(() => {
					returnedMessageByRank.innerHTML = '<p </p>';
				}, 2000);
		}
	});

	document.getElementById('startRemoteGame').addEventListener('click', async function() {
		event.preventDefault();
		const username = document.getElementById('playerNameInvitation').value;

		const returnedMessage = document.getElementById('returned-message');
		if (username === dataRemote.username)
		{
			returnedMessage.innerHTML = `<p class="text-danger">You can not play with yourself!</p>`;
			setTimeout(() => {
				returnedMessage.innerHTML = '<p </p>';
			}, 2000);
			return;
		}

		const result = await sendInvitation(dataRemote.username, username, selectedGameType);

		if (result.message === "Game invitation sent successfully!") {
			returnedMessage.innerHTML = '<p class="text-success">Game invitation sent successfully!</p>';
			setTimeout(() => {
				returnedMessage.innerHTML = '<p </p>';
			}, 2000);
			if (selectedGameType === 'Pong') {
				navigate('/pongremote');
			}
		} else {
			returnedMessage.innerHTML = `<p class="text-danger">Failed to send game invitation! ${result.message} </p>`;
			setTimeout(() => {
				returnedMessage.innerHTML = '<p </p>';
			}, 2000);
		}
	});

		dataRemote.remote_game_invitations.forEach(remote_game_invitations => {
			document.getElementById(`AcceptRequest-${remote_game_invitations.game_id}`).addEventListener('click', async function() {
				const response = await fetch('/accept-game-invitation/', {
					method: 'POST',
					headers: {
						'Content-Type': 'application/json',
						'X-CSRFToken': getCSRFToken() // Ensure CSRF token is sent
					},
					body: JSON.stringify({
						'username': remote_game_invitations.sender__user__username,
						'game_id': remote_game_invitations.game_id// Send the username in the request body
					}),
				})

				const result = await response.json();

				if (response.ok) {
					selectedGameID = result.game_id;
					otherPlayer = result.receiver;
					senderPlayer = result.sender;
					let gameNameExtracted = selectedGameID.match(/[a-zA-Z]+/)[0];
					if (gameNameExtracted === 'Pong') {
						navigate('/pongremote');
					}
				} else {
					alert('Other user already closed the game');
					setTimeout(() => {
						navigate('/');
					}, 100);
				}
			});

			document.getElementById(`RejectRequest-${remote_game_invitations.game_id}`).addEventListener('click', async function() {
				const response = await fetch('/reject-game-invitation/', {
					method: 'POST',
					headers: {
						'Content-Type': 'application/json',
						'X-CSRFToken': getCSRFToken() // Ensure CSRF token is sent
					},
					body: JSON.stringify({
						'username': remote_game_invitations.sender__user__username,
						'game_id': remote_game_invitations.game_id
					}),
				})
				const result = await response.json();

				if (response.ok) {
					const gameRejectWebsocket = new WebSocket(`wss://${window.location.host}/ws/pong/${result.game_id}/?purpose=reject`);
					gameRejectWebsocket.onopen = function () {
						console.log(`WebSocket connected for rejection`);
						gameRejectWebsocket.close(1001, "Player rejected the game");
					};
					gameRejectWebsocket.onclose = function (event) {
						if (event.code === 1001) {
							console.log(`Game socket closed with rejection for game ID: ${result.game_id}`);
						} else {
							console.log(`Game socket closed with code: ${event.code}`);
						}
						delete gameRejectWebsocket[result.game_id];
					};
					navigate('/');
				} else {
					setTimeout(() => {
						navigate('/');
					}, 100);
				}
			});
		});

	})
	.catch((error) => {
		$games.innerHTML = base;
	});
	return $games;
}

export function getSelectedGameID() {
	return selectedGameID;
}

export function getSenderPlayer() {
	return senderPlayer;
}

export function getOtherPlayer() {
	return otherPlayer;
}
