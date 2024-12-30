import { navigate } from '../../helpers/App.js';
import { setupChat, Initialize, displayMessages, toggleBlockStatus, chatSockets} from './Client.js';
import {selectedGameType, sendInvitation} from "./RemotePlay.js";
//import {selectedGameType, sendInvitation, setGameVariables} from './RemotePlay.js';

const avatarPaths = [
	'/static/media/assets/ships/splash/1.png',
	'/static/media/assets/ships/splash/7.png',
	'/static/media/assets/ships/splash/5.png',
	'/static/media/assets/ships/splash/4.png',
	'/static/media/assets/ships/splash/2.png',
	'/static/media/assets/ships/splash/6.png',
	'/static/media/assets/ships/splash/3.png',
	'/static/media/assets/ships/splash/9.png',
	'/static/media/assets/ships/splash/8.png'
];

export let currentFriend = '';

const colorNames = [
	'00ff00',
	'8000ff',
	'ff8000',
	'00ffff'
];

export function saveMatchHistory(match) {

	return fetch('/api/save-match-history/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'X-CSRFToken': getCSRFToken() // Ensure CSRF protection for Django
		},
		body: JSON.stringify(match) // Convert match object to JSON
	})
	.then(response => {
		if (!response.ok) {
			throw new Error('Failed to save match history');
		}
		return response.json(); // Parse the JSON response
	})
	.then(data => {
		console.log('Match history saved successfully:');
	})
	.catch(error => {
		console.log('Error saving match history:', error);
	});
}

export function calculateRankedStats(matchHistory, gameName) {
	const stats = { wins: 0, total: 0 };
	matchHistory.forEach(match => {
		if (match.game === gameName) {
			if (match.result === "Win") {
				stats.wins++;
			}
			stats.total++;
		}
	});

	let resultString;
	let rank;

	if (stats.total < 5) {
		resultString = `${gameName}: No rank ${stats.wins}/${stats.total}`;
		rank = "NoRank";
	} else {
		const winPercentage = (stats.wins / stats.total) * 100;

		if (winPercentage <= 20) {
			rank = "Bronze";
		} else if (winPercentage <= 40) {
			rank = "Silver";
		} else if (winPercentage <= 60) {
			rank = "Gold";
		} else if (winPercentage <= 80) {
			rank = "Platinum";
		} else {
			rank = "Diamond";
		}
		resultString = `${gameName}: ${rank} ${stats.wins}/${stats.total}`;
	}
	return {
		result: resultString,
		rank: rank
	};
}
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

export async function getMatchHistory() {
	try {
		const response = await fetch('/api/load-match-history/');
		if (!response.ok) {
			throw new Error(`HTTP error! Status: ${response.status}`);
		}
		const matchHistory = await response.json();
		return matchHistory;
	} catch (error) {
		console.log('Error fetching match history:', error);
		throw error; // Rethrow or handle the error as needed
	}
}

export default function DashBoard() {

	const $dashboard = document.createElement('dashboard');
	getMatchHistory().then(matchHistory => {

		const pongRank = calculateRankedStats(matchHistory.match_history, "Pong Remote")
		localStorage.setItem('selectedAvatarId', matchHistory.game_customization[0].ship);
		localStorage.setItem('selectedColorId', matchHistory.game_customization[0].color);
	$dashboard.innerHTML = `
		<div class="vh-100 d-flex flex-column align-items-center justify-content-start position-relative">
			<div class="container mt-3">
				<div class="row align-items-start">
					<div class="col-md-3">
						<div class="card bg-dark text-white mb-3">
							<div class="card-body text-center">
								<img id="avatar" src="/static/media/assets/ships/splash/${localStorage.getItem('selectedAvatarId')}.png" class="rounded-circle mb-3" alt="Avatar" style="width: 100px; height: 100px;">
								<h5 class="card-title">${matchHistory.username}</h5>
								<p class="card-text">
									<img src="/static/media/rank/${pongRank.rank}.png"
										alt="${pongRank.rank}"
										style="width: 64px; height: 64px; margin-right: 2px;">
									<span class="tooltiptext">The game ranking starts after 5 remote matches, Good luck!</span>
								</p>
								<p class="card-text">${pongRank.result}</p>
							</div>
						</div>
						<div class="card bg-dark text-white mb-3">
							<div class="card-header">Select Ship</div>
							<div class="card-body">
								<div class="d-flex flex-wrap">
									${avatarPaths.map((path, index) =>
										`<img src="${path}" data-ship-id="${index + 1}" class="avatar-option rounded-circle m-1 ${(index + 1).toString() === localStorage.getItem('selectedAvatarId') ? 'selected-color' : ''}" alt="Avatar" style="width: 50px; height: 50px; cursor: pointer;">`
									).join('')}
								</div>
							</div>
						</div>
						<div class="card bg-dark text-white mb-3">
							<div class="card-header">Select Color</div>
							<div class="card-body">
								<div class="d-flex flex-wrap">
									${colorNames.map((names) =>
										`<img src="/static/media/assets/color/${names}.png" data-color-id="#${names}" class="color-option rounded-circle m-1 ${`#${names}` === localStorage.getItem('selectedColorId') ? 'selected-color' : ''}" alt="Color" style="width: 50px; height: 50px; cursor: pointer;">`
									).join('')}
								</div>
							</div>
						</div>
					</div>
					<div class="col-md-6">
						<div class="card bg-dark text-white mb-3">
							<div class="card-header">
								<button class="btn btn-link text-white" type="button" data-bs-toggle="collapse" data-bs-target="#pongStatsCollapse" aria-expanded="false" aria-controls="pongStatsCollapse">
									Pong Game Statistics
								</button>
							</div>
							<div id="pongStatsCollapse" class="collapse">
								<div class="card-body">
									<div class="row">
										<div class="col-md-12 text-center mb-3">
											<span class="badge bg-success">Games Won</span>
											<span class="badge bg-danger">Games Lost</span>
										</div>
										<div class="col-md-4 text-center">
											<canvas id="pongAIStatsChart" width="200" height="200"></canvas> <!-- Canvas for Pong AI Chart -->
											<p>Player vs AI</p>
										</div>
										<div class="col-md-4 text-center">
											<canvas id="pongLocalStatsChart" width="200" height="200"></canvas> <!-- Canvas for Pong Local Chart -->
											<p>Local PvP</p>
										</div>
										<div class="col-md-4 text-center">
											<canvas id="pongRemoteStatsChart" width="200" height="200"></canvas> <!-- Canvas for Pong Remote Chart -->
											<p>Remote Play</p>
										</div>
									</div>
								</div>
							</div>
						</div>
						<div class="card bg-dark text-white mb-3">
							<div class="card-header">
								<button class="btn btn-link text-white" type="button" data-bs-toggle="collapse" data-bs-target="#asteroidsStatsCollapse" aria-expanded="false" aria-controls="asteroidsStatsCollapse">
									Asteroids Game Statistics
								</button>
							</div>
							<div id="asteroidsStatsCollapse" class="collapse">
								<div class="card-body">
									<div class="row">
										<div class="col-md-12 text-center mb-3">
											<span class="badge bg-success">Games Won</span>
											<span class="badge bg-danger">Games Lost</span>
										</div>
										<div class="col-md-4 text-center">
											<canvas id="asteroidsAIStatsChart" width="200" height="200"></canvas> <!-- Canvas for Asteroids AI Chart -->
											<p>Player vs AI</p>
										</div>
										<div class="col-md-4 text-center">
											<canvas id="asteroidsLocalStatsChart" width="200" height="200"></canvas> <!-- Canvas for Asteroids Local Chart -->
											<p>Local PvP</p>
										</div>
									</div>
								</div>
							</div>
						</div>
						<div class="card bg-dark text-white mb-3">
							<div class="card-header">
								<button class="btn btn-link text-white" type="button" data-bs-toggle="collapse" data-bs-target="#matchHistoryCollapse" aria-expanded="false" aria-controls="matchHistoryCollapse">
									Match History
								</button>
							</div>
							<div id="matchHistoryCollapse" class="collapse">
								<div class="card-body">
									${matchHistory.match_history
										.filter(match => !match.game.includes('Tournament'))
										.map(match => `
										<p>
											${match.game}: ${match.score} ->
											<span style="color: ${match.result === 'Win' ? 'green' : 'red'};">
												${match.result}
											</span>
											at ${new Date(match.timestamp).toLocaleString('en-GB', {
												day: '2-digit',
												month: '2-digit',
												year: 'numeric',
												hour: '2-digit',
												minute: '2-digit',
												hour12: true
											})}
										</p>
									`).join('')}
								</div>
							</div>
						</div>
						<div class="card bg-dark text-white mb-3">
							<div class="card-header">
								<button class="btn btn-link text-white" type="button" data-bs-toggle="collapse" data-bs-target="#tournamentsCollapse" aria-expanded="false" aria-controls="tournamentsCollapse">
									Tournaments
								</button>
							</div>
							<div id="tournamentsCollapse" class="collapse">
								<div class="card-body">
									${matchHistory.match_history
										.filter(match => match.game.includes('Tournament'))
										.map(match => `
										<p>
											${match.game} ->
											<span style="color: ${match.result === 'Winner' ? 'green' : 'red'};">
												${match.result}
											</span>
											: ${match.score}
											at ${new Date(match.timestamp).toLocaleString('en-GB', {
												day: '2-digit',
												month: '2-digit',
												year: 'numeric',
												hour: '2-digit',
												minute: '2-digit',
												hour12: true
											})}
										</p>
									`).join('')}
								</div>
							</div>
						</div>
					</div>
					<div class="col-md-3 friends-column">
						<div class="card bg-dark text-white mb-3">
							<form id="send-friend-request">
								<input type="text" class="form-control mb-3" id="searchInput" name="username" placeholder="Search friends to add...">
								<button id="SearchButton" type="submit" class="btn btn-purple btn-custom mx-3 nav-link text-white shadow-lg">Search</button>
								<div class="card-body" id="friend-message"></div>
							</form>
							<div class="card-header">Friends: ${matchHistory.friends_count}</div>
							<div class="card-body" id="friends-list">
								${matchHistory.friends.map(friend => `
								<p>
									${friend.username ? friend.username : 'You currently have no friends.'}
									${friend ? `
										<img src="/static/media/icons/${friend.status ? 'online' : 'offline'}.png"
											class="profile-icon ml-2"
											alt="Profile-friend-status"
											style="width: 20px; height: 20px; pointer-events: none;"
											id="friend-status-${friend.username}"
											data-status="${friend.status === true ? 'online' : friend.status}">
										<img src="/static/media/icons/block-icon.png"
											class="block-icon ml-2"
											alt="Block"
											style="width: 20px; height: 20px; cursor: pointer; filter: invert(29%) sepia(81%) saturate(2034%) hue-rotate(186deg) brightness(95%) contrast(101%);"
											data-friend="${friend.username}"
											title="Block/Unblock ${friend.username}">
										<img src="/static/media/icons/chat-icon.png"
											class="chat-icon ml-2"
											alt="Chat"
											style="width: 20px; height: 20px; cursor: pointer; filter: invert(29%) sepia(81%) saturate(2034%) hue-rotate(186deg) brightness(95%) contrast(101%);"
											data-friend="${friend.username}"
											user="${matchHistory.username}"
											title="Chat with ${friend.username}">
										<img src="/static/media/icons/chat-icon2.png"
											class="chat-icon2 ml-2 display-none"
											alt="Chat"
											style="width: 20px; height: 20px; cursor: pointer; filter: invert(29%) sepia(81%) saturate(2034%) hue-rotate(186deg) brightness(95%) contrast(101%);"
											data-friend="${friend.username}"
											user="${matchHistory.username}"
											title="Chat with ${friend.username}">
										<img src="/static/media/icons/profile.png"
											class="profile-icon ml-2"
											alt="Profile-friend"
											style="width: 20px; height: 20px; cursor: pointer; filter: invert(29%) sepia(81%) saturate(2034%) hue-rotate(186deg) brightness(95%) contrast(101%);"
											data-friend="${friend.username}"
											user="${matchHistory.username}"
											id="Profile-id-${friend.username}">
									` : ''}
								</p>
								`).join('')}
							</div>
							<form id="friend-requests">
								<div class="card-header">Friend Requests:</div>
								<div class="card-body">
									${matchHistory.friend_requests.length > 0 ?
										matchHistory.friend_requests.map(friend_request => `
											<p>${friend_request}
											<button id="AcceptFriendRequest-${friend_request}" type="button" class="btn btn-success btn-sm ml-2">✔️</button>
											<button id="RejectFriendRequest-${friend_request}" type="button" class="btn btn-danger btn-sm ml-2">X</button>
											</p>
										`).join('') :
										'<p>You currently have no friend requests.</p>'
									}
								</div>
								<div class="card-body" id="friend-request-message"></div>
							</form>
							<div class="card-body" id="request-message"></div>
						</div>
					</div>
				</div>
			</div>
		</div>
	`;

	const pongRemoteGamesPlayed = matchHistory.match_history.filter(match => match.game === "Pong Remote").length;
	const pongRemoteGamesWon = matchHistory.match_history.filter(match => match.game === "Pong Remote" && match.result === 'Win').length;
	const pongRemoteGamesLost = pongRemoteGamesPlayed - pongRemoteGamesWon;

	const pongAIGamesPlayed = matchHistory.match_history.filter(match => match.game === "Pong Play vs AI").length;
	const pongAIGamesWon = matchHistory.match_history.filter(match => match.game === "Pong Play vs AI" && match.result === 'Win').length;
	const pongAIGamesLost = pongAIGamesPlayed - pongAIGamesWon;

	const pongLocalGamesPlayed = matchHistory.match_history.filter(match => match.game === "Pong Player vs Player").length;
	const pongLocalGamesWon = matchHistory.match_history.filter(match => match.game === "Pong Player vs Player" && match.result === 'Win').length;
	const pongLocalGamesLost = pongLocalGamesPlayed - pongLocalGamesWon;

	const asteroidsAIGamesPlayed = matchHistory.match_history.filter(match => match.game === "Asteroids Play vs AI").length;
	const asteroidsAIGamesWon = matchHistory.match_history.filter(match => match.game === "Asteroids Play vs AI" && match.result === 'Win').length;
	const asteroidsAIGamesLost = asteroidsAIGamesPlayed - asteroidsAIGamesWon;

	const asteroidsLocalGamesPlayed = matchHistory.match_history.filter(match => match.game === "Asteroids Player vs Player").length;
	const asteroidsLocalGamesWon = matchHistory.match_history.filter(match => match.game === "Asteroids Player vs Player" && match.result === 'Win').length;
	const asteroidsLocalGamesLost = asteroidsLocalGamesPlayed - asteroidsLocalGamesWon;

	function createPieChart(ctx, label, data) {
		const totalGames = data.reduce((a, b) => a + b, 0);
		new Chart(ctx, {
			type: 'doughnut',
			data: {
				labels: ['Games Won', 'Games Lost'],
				datasets: [
					{
						label: label,
						data: data,
						backgroundColor: ['#28a745', '#dc3545'],
						borderColor: ['#28a745', '#dc3545'],
						borderWidth: 1
					}
				]
			},
			options: {
				responsive: true,
				cutout: '80%',
				plugins: {
					legend: {
						display: false
					},
					tooltip: {
						callbacks: {
							label: function (context) {
								const label = context.label || '';
								const value = context.raw || 0;
								const total = context.chart.data.datasets[0].data.reduce((a, b) => a + b, 0);
								const percentage = ((value / total) * 100).toFixed(2);
								return `${label}: ${value} (${percentage}%)`;
							}
						}
					}
				}
			},
			plugins: [
				{
					id: 'centerText',
					beforeDraw(chart) {
						const { width } = chart;
						const { height } = chart;
						const ctx = chart.ctx;
						ctx.save();
						ctx.font = '14px Arial';
						ctx.textAlign = 'center';
						ctx.textBaseline = 'middle';
						ctx.fillStyle = '#666';
						ctx.fillText('Total Games Played', width / 2, height / 2 - 10);
						ctx.font = 'bold 20px Arial';
						ctx.fillText(totalGames, width / 2, height / 2 + 15);
						ctx.restore();
					}
				}
			]
		});
	}

	createPieChart(document.getElementById('pongRemoteStatsChart').getContext('2d'), 'Pong Remote Game Statistics', [pongRemoteGamesWon, pongRemoteGamesLost]);
	createPieChart(document.getElementById('pongAIStatsChart').getContext('2d'), 'Pong AI Game Statistics', [pongAIGamesWon, pongAIGamesLost]);
	createPieChart(document.getElementById('pongLocalStatsChart').getContext('2d'), 'Pong Local Game Statistics', [pongLocalGamesWon, pongLocalGamesLost]);
	createPieChart(document.getElementById('asteroidsAIStatsChart').getContext('2d'), 'Asteroids AI Game Statistics', [asteroidsAIGamesWon, asteroidsAIGamesLost]);
	createPieChart(document.getElementById('asteroidsLocalStatsChart').getContext('2d'), 'Asteroids Local Game Statistics', [asteroidsLocalGamesWon, asteroidsLocalGamesLost]);

	document.querySelectorAll('.block-icon').forEach(icon => {
		icon.addEventListener('click', event => {
			const friendName = event.currentTarget.getAttribute('data-friend'); // Get the friend's name from the block icon
			toggleBlockStatus(friendName, matchHistory.username); // Pass friendName and username to toggleBlockStatus
		});
	});

	matchHistory.friends.map((friend, index) => {
		Initialize(friend.username, matchHistory.username); // Initialize chat functionality for the friend
	})

	const chatIcons = document.querySelectorAll('.chat-icon');
	const chatIcons2 = document.querySelectorAll('.chat-icon2');

	chatIcons2.forEach((icon, index) => {
		icon.addEventListener('click', (event) => {
			const friendName = event.currentTarget.getAttribute('data-friend');
			const userName = event.currentTarget.getAttribute('user');

			if (!icon.classList.contains('display-none')) {
				chatIcons[index].classList.remove('display-none');
				icon.classList.add('display-none');
			}

			openChatBox(friendName, userName);
		});
	});

	chatIcons.forEach(icon => {
	    icon.addEventListener('click', (event) => {
	        const friendName = event.currentTarget.getAttribute('data-friend');
			const userName = event.currentTarget.getAttribute('user');

	        openChatBox(friendName, userName);
	    });
	});

	let currentChatBox = null; // Track the currently open chat box

	function openChatBox(friendName, userName) {
		// Close and remove the currently open chat box if it exists
		if (currentChatBox) {
			currentChatBox.remove();
			currentChatBox = null;
		}

		currentFriend = friendName;
		const shortName = friendName.length > 6 ? friendName.slice(0, 6) : friendName;
		const chatBox = document.createElement('div');
		chatBox.classList.add('chat-popup');
		chatBox.id = `chat-box-${userName}-${friendName}`;

		chatBox.innerHTML = `
			<div class="chat-box">
				<div class="chat-header">
					<span>${shortName} Live-Chat</span>
					<img src="/static/media/icons/pongIcon.png" class="invite-btn"
					title="Invite to a Pong game"
                     style="width: 20px; height: 20px; cursor: pointer;
                            filter: invert(29%) sepia(81%) saturate(2034%) hue-rotate(186deg) brightness(95%) contrast(101%);">
					<div>
						<button class="minimize-btn">-</button>
						<button class="close-btn">&times;</button>
					</div>
				</div>
				<div class="chat-content">
					<div class="messages" id="messages-${userName}-${friendName}"></div>
					<div class="input-container">
						<input type="text" class="message-input" placeholder="Type your message...">
						<button class="sender">SEND</button>
					</div>
				</div>
			</div>
		`;

		document.getElementsByClassName('friends-column')[0].appendChild(chatBox);
		currentChatBox = chatBox;

		// Display cached messages for the friend, if available
		displayMessages(friendName, userName);

		// Close the chat box with animation when the X button is clicked
		chatBox.querySelector('.close-btn').addEventListener('click', () => {
			chatBox.remove();
			currentChatBox = null;
		});

		chatBox.querySelector('.invite-btn').addEventListener('click', async function() {
			event.preventDefault();

			const result = await sendInvitation(userName, friendName, 'Pong');

			if (result.message === "Game invitation sent successfully!") {
				// Send a WebSocket message to notify the friend
				const chatKey = `${userName}-${friendName}`;
				const chatSocket = chatSockets[chatKey];

				if (chatSocket && chatSocket.readyState === WebSocket.OPEN) {
					chatSocket.send(JSON.stringify({
						type: "game_invitation",
						sender: userName,
						message: `${userName} invited you to a Pong game!`
					}));
				}
				setTimeout(() => {
					navigate('/pongremote');
				}, 100);
			}
		});

		// Minimize/maximize functionality for the chat box
		const minimizeButton = chatBox.querySelector('.minimize-btn');
		const chatContent = chatBox.querySelector('.chat-content');
		minimizeButton.addEventListener('click', () => {
			chatContent.classList.toggle('hidden');
			minimizeButton.textContent = chatContent.classList.contains('hidden') ? '+' : '-';
		});

		// Initialize WebSocket or reuse existing connection
		setupChat(friendName, userName);
	}

	const socket = new WebSocket('wss://' + window.location.host + '/ws/friend-status/');

	// Listen for messages from the server
	socket.onmessage = function(e) {
		const data = JSON.parse(e.data);

		// Log the raw data to the browser console for debugging

		const friendUsername = data.friend_;
		const status = data.status;

		// Update the status dot dynamically
		const statusDot = document.getElementById(`friend-status-${friendUsername}`);
		if (statusDot) {
			statusDot.src = status === "online"
				? "/static/media/icons/online.png"
				: "/static/media/icons/offline.png";

				statusDot.setAttribute('data-status', status);

			// Log confirmation of status dot update
		} else {
			console.warn(`Status dot for friend ${friendUsername} not found in the DOM.`);
		}
	};

		const avatarElement = $dashboard.querySelector('#avatar');
		const avatarOptions = $dashboard.querySelectorAll('.avatar-option');
		const colorOptions = $dashboard.querySelectorAll('.color-option');
		const profileIcons = document.querySelectorAll('.profile-icon');

		profileIcons.forEach(profile => {
			profile.addEventListener('click', function() {
				const friend = profile.getAttribute('data-friend');
				profileFriend(friend);
			})
		})

		avatarOptions.forEach(option => {
			option.addEventListener('click', function() {
				avatarOptions.forEach(opt => opt.classList.remove('selected-color'));
				const selectedAvatarId = this.getAttribute('data-ship-id');  // Get the ship ID
				avatarElement.src = this.src;
				this.classList.add('selected-color');

				localStorage.setItem('selectedAvatarId', selectedAvatarId);  // Store the ID
				sendCustomizationToServer();  // Send to server with the correct ID
			});
		});

		// Event listener for color selection
		colorOptions.forEach(option => {
			option.addEventListener('click', function() {
				colorOptions.forEach(opt => opt.classList.remove('selected-color'));
				const selectedColorId = this.getAttribute('data-color-id');
				this.classList.add('selected-color');

				localStorage.setItem('selectedColorId', selectedColorId);
				sendCustomizationToServer();
			});
		});

		// Function to send the selected ship (avatar) and color to the Django backend
		function sendCustomizationToServer() {
			const selectedAvatarId = localStorage.getItem('selectedAvatarId');
			const selectedColor = localStorage.getItem('selectedColorId');

			if (selectedAvatarId || selectedColor) {
				fetch('/save-customization/', {
					method: 'POST',
					headers: {
						'Content-Type': 'application/json',
						'X-CSRFToken': getCSRFToken(),  // Ensure CSRF token is sent
					},
					body: JSON.stringify({
						ship: selectedAvatarId,
						color: selectedColor
					}),
				}).then(response => response.json())
					.then(data => {
						if (data.status === 'success') {
							//console.log('Customization saved');
						} else {
							console.log('Error saving customization:', data.error);
						}
					});
			} else {
				console.log('Missing ship or color selection.');
			}
		}

	document.getElementById('SearchButton').addEventListener('click', async function() {
		event.preventDefault();
		const username = document.getElementById('searchInput').value;

		const friendMessage = document.getElementById('friend-message');
		if (username === matchHistory.username)
		{
			friendMessage.innerHTML = `<p class="text-danger">You can not be friends with yourself!</p>`;
			setTimeout(() => {
				friendMessage.innerHTML = '<p </p>';
			}, 2000);
			return;
		}

		const response = await fetch('/send-friend-request/', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/x-www-form-urlencoded', // or 'application/json'
				'X-CSRFToken': getCSRFToken(), // Make sure you include your CSRF token
			},
			body: JSON.stringify({
				'username': username
			})
		})
		const result = await response.json();

		if (response.ok) {
			friendMessage.innerHTML = '<p class="text-success">Friend request sent successfully!</p>';
			setTimeout(() => {
				friendMessage.innerHTML = '<p </p>';
			}, 2000);
		} else {
			friendMessage.innerHTML = `<p class="text-danger">Failed to send friend request! ${result.message} </p>`;
			setTimeout(() => {
				friendMessage.innerHTML = '<p </p>';
			}, 2000);
		}
	});

		function profileFriend(friendName) {
			currentFriend = friendName;
			navigate('/profileFriend');
		}

	matchHistory.friend_requests.forEach(friend_request => {
		// Adding event listener for the accept button
		document.getElementById(`AcceptFriendRequest-${friend_request}`).addEventListener('click', async function() {
			const response = await fetch('/accept-friend-request/', {
				method: 'POST',
				headers: {
					'Content-Type': 'application/json',
					'X-CSRFToken': getCSRFToken() // Ensure CSRF token is sent
				},
				body: JSON.stringify({
					'username': friend_request // Send the username in the request body
				}),
			})

			const result = await response.json();
			const friendAcceptMessage = document.getElementById('friend-request-message');

			if (response.ok) {
				friendAcceptMessage.innerHTML = '<p class="text-success">Friend request accepted successfully!</p>';
				setTimeout(() => {
					friendAcceptMessage.innerHTML = '<p </p>';
					navigate('/dashboard');
				}, 2000);
			} else {
				friendAcceptMessage.innerHTML = `<p class="text-danger">Failed to accept friend request! ${result.message} </p>`;
				setTimeout(() => {
					friendAcceptMessage.innerHTML = '<p </p>';
				}, 2000);
			}
		});

		// Adding event listener for the reject button
		document.getElementById(`RejectFriendRequest-${friend_request}`).addEventListener('click', async function() {
			const response = await fetch('/reject-friend-request/', {
				method: 'POST',
				headers: {
					'Content-Type': 'application/json',
					'X-CSRFToken': getCSRFToken() // Ensure CSRF token is sent
				},
				body: JSON.stringify({
					'username': friend_request // Send the username in the request body
				}),
			})
			const result = await response.json();
			const friendRejectMessage = document.getElementById('friend-request-message');

			if (response.ok) {
				friendRejectMessage.innerHTML = '<p class="text-success">Friend request rejected successfully!</p>';
				setTimeout(() => {
					friendRejectMessage.innerHTML = '<p </p>';
					navigate('/dashboard');
				}, 1000);
			} else {
				friendRejectMessage.innerHTML = `<p class="text-danger">Failed to reject friend request! ${result.message} </p>`;
				setTimeout(() => {
					friendRejectMessage.innerHTML = '<p </p>';
				}, 1000);
			}
		});
	});

	});
	return $dashboard;
}
