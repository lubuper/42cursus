let selectedGameMode = null;
let selectedGameType = null;
let tournamentPlayers = null;
let playerNames = [];

export default function LocalPlay(navigate) {
	const $games = document.createElement('div');
	$games.innerHTML = `
		<div class="container vh-100 d-flex flex-column align-items-center justify-content-start pt-3">
			<!-- Top Row for Game Mode and Game Type Cards -->
			<div class="row w-100 mb-3">
				<!-- Select Game Mode Card -->
				<div class="col-md-6">
					<div class="card bg-dark text-white w-100" style="border: 1px solid #343a40; opacity: 0.8;">
						<div class="card-body">
							<h5 class="card-title text-center">Select Game Mode</h5>
							<div class="form-check">
								<input class="form-check-input" type="radio" name="gameMode" id="pvp" value="1" checked>
								<label class="form-check-label" for="pvp">Player vs Player</label>
							</div>
							<div class="form-check">
								<input class="form-check-input" type="radio" name="gameMode" id="ai" value="2">
								<label class="form-check-label" for="ai">Play vs AI</label>
							</div>
							<div class="form-check">
								<input class="form-check-input" type="radio" name="gameMode" id="tournament" value="6">
								<label class="form-check-label" for="tournament">Tournament Mode</label>
							</div>
							<div id="difficultyOptions" class="mt-1" style="display: none;">
								<h6 class="text-center mb-1">Select Difficulty</h6>
								<div class="d-flex justify-content-center">
									<div class="form-check me-2">
										<input class="form-check-input" type="radio" name="gameMode" id="ai-easy" value="2">
										<label class="form-check-label" for="ai-easy">Easy</label>
									</div>
									<div class="form-check me-2">
										<input class="form-check-input" type="radio" name="gameMode" id="ai-medium" value="3">
										<label class="form-check-label" for="ai-medium">Medium</label>
									</div>
									<div class="form-check me-2">
										<input class="form-check-input" type="radio" name="gameMode" id="ai-hard" value="4">
										<label class="form-check-label" for="ai-hard">Hard</label>
									</div>
									<div class="form-check">
										<input class="form-check-input" type="radio" name="gameMode" id="ai-impossible" value="5">
										<label class="form-check-label" for="ai-impossible">Impossible</label>
									</div>
								</div>
							</div>
						</div>
					</div>
				</div>
				<!-- Select Game Type Card -->
				<div class="col-md-6">
					<div class="card bg-dark text-white w-100" style="border: 1px solid #343a40; opacity: 0.8;">
						<div class="card-body">
							<h5 class="card-title text-center">Select Game Type</h5>
							<div class="d-flex justify-content-center">
								<div class="form-check me-2">
									<input class="form-check-input" type="radio" name="gameType" id="default" value="default" checked>
									<label class="form-check-label" for="default">Default</label>
								</div>
								<div class="form-check">
									<input class="form-check-input" type="radio" name="gameType" id="powered-up" value="powered">
									<label class="form-check-label" for="powered-up">Powered Up</label>
								</div>
							</div>
						</div>
					</div>
				</div>
			</div>
			<!-- Tournament Setup Section -->
			<div class="row w-100 mb-3" id="tournamentSetup" style="display: none;">
				<div class="col-md-12">
					<div class="card bg-dark text-white w-100" style="border: 1px solid #343a40; opacity: 0.8;">
						<div class="card-body">
							<h5 class="card-title text-center">Tournament Setup</h5>
							<div class="form-group">
								<label for="tournamentPlayers" class="form-label">Number of Players</label>
								<select class="form-control" id="tournamentPlayers">
									<option value="" selected>Select number of players</option>
									<option value="4">4</option>
									<option value="8">8</option>
								</select>
							</div>
							<div id="playerNamesContainer" class="mt-3"></div>
							<div class="form-group mt-3">
								<label for="tournamentGameType" class="form-label">Select Game for Tournament</label>
								<select class="form-control" id="tournamentGameType">
									<option value="pong">Pong</option>
									<option value="asteroids">Asteroids</option>
								</select>
							</div>
							<div class="d-flex justify-content-center mt-4">
								<button class="btn btn-purple btn-lg mx-5 text-white shadow-lg" id="startTournament">Start Tournament</button>
							</div>
						</div>
					</div>
				</div>
			</div>
			<!-- Game Sections -->
			<div class="row w-100">
				<!-- Pong Section -->
				<div class="col-md-6 text-center d-flex flex-column align-items-center">
					<img src="/static/media/assets/pongsplash.png" alt="Pong Game" class="img-fluid mt-2" style="width: 100%; height: auto;">
					<div class="card bg-dark text-white mt-3 w-100" style="border: 1px solid #343a40; opacity: 0.8;">
						<div class="card-body">
							<h5 class="card-title text-center">How To Play</h5>
							<div class="card-text">
								<div class="row">
									<div class="col-6">
										<h6>Player 1</h6>
										<ul class="list-unstyled">
											<li><i class="fas fa-arrow-left"></i> Move left/top: A</li>
											<li><i class="fas fa-arrow-right"></i> Move right/bottom: D</li>
										</ul>
									</div>
									<div class="col-6">
										<h6>Player 2</h6>
										<ul class="list-unstyled">
											<li><i class="fas fa-arrow-left"></i> Move left/top: J</li>
											<li><i class="fas fa-arrow-right"></i> Move right/bottom: L</li>
											</ul>
									</div>
									<div><i class="fas fa-camera"></i> Cameras toggle: C</div>
									<div><i class="fas fa-pause"></i> Pause: Spacebar</div>
								</div>
							</div>
						</div>
					</div>
					<div class="d-flex justify-content-center mt-4">
						<button class="btn btn-purple btn-lg mx-5 text-white shadow-lg" data-path="/pong">Pong</button>
					</div>
				</div>
				<!-- Asteroids Section -->
				<div class="col-md-6 text-center d-flex flex-column align-items-center">
					<img src="/static/media/assets/asteroidssplash.png" alt="Asteroids Game" class="img-fluid mt-2" style="width: 100%; height: auto;">
					<div class="card bg-dark text-white mt-3 w-100" style="border: 1px solid #343a40; opacity: 0.8;">
						<div class="card-body">
							<h5 class="card-title text-center">How To Play</h5>
							<div class="card-text">
								<div class="row">
									<div class="col-6">
										<h6>Player 1</h6>
										<ul class="list-unstyled">
											<li><i class="fas fa-arrow-left"></i> Rotate left: A</li>
											<li><i class="fas fa-arrow-right"></i> Rotate right: D</li>
											<li><i class="fas fa-arrow-up"></i> Thruster: W</li>
											<li><i class="fas fa-space-shuttle"></i> Fire: Space</li>
											<li><i class="fas fa-shield-alt"></i> Shields: E</li>
										</ul>
									</div>
									<div class="col-6">
										<h6>Player 2</h6>
										<ul class="list-unstyled">
											<li><i class="fas fa-arrow-left"></i> Rotate left: J</li>
											<li><i class="fas fa-arrow-right"></i> Rotate right: L</li>
											<li><i class="fas fa-arrow-up"></i> Thruster: I</li>
											<li><i class="fas fa-space-shuttle"></i> Fire: P</li>
											<li><i class="fas fa-shield-alt"></i> Shields: O</li>
										</ul>
									</div>
								</div>
							</div>
						</div>
					</div>
					<div class="d-flex justify-content-center mt-4">
						<button class="btn btn-purple btn-lg mx-5 text-white shadow-lg" data-path="/asteroids">Asteroids</button>
					</div>
				</div>
			</div>
		</div>
	`;

	// Event listener to show/hide difficulty options and tournament setup
	$games.addEventListener('change', (event) => {
		if (event.target.name === 'gameMode') {
			const difficultyOptions = document.getElementById('difficultyOptions');
			const tournamentSetup = document.getElementById('tournamentSetup');
			const selectedValue = document.querySelector('input[name="gameMode"]:checked').value;
			if (selectedValue === '2') {
				difficultyOptions.style.display = 'block';
				tournamentSetup.style.display = 'none';
			} else if (selectedValue === '1') {
				difficultyOptions.style.display = 'none';
				tournamentSetup.style.display = 'none';
			} else if (selectedValue === '6') {
				difficultyOptions.style.display = 'none';
				tournamentSetup.style.display = 'block';
				// Trigger change event to populate player names
				document.getElementById('tournamentPlayers').dispatchEvent(new Event('change'));
			}
		}
	});

	// Event listener to update player name inputs
	$games.querySelector('#tournamentPlayers').addEventListener('change', (event) => {
		tournamentPlayers = Number(event.target.value);
		const playerNamesContainer = document.getElementById('playerNamesContainer');
		playerNamesContainer.innerHTML = '';
		if (tournamentPlayers) {
			if (tournamentPlayers === 4) {
				selectedGameMode = '8';
			}
			else if (tournamentPlayers === 8) {
				selectedGameMode = '9';
			}
			for (let i = 1; i <= tournamentPlayers; i++) {
				const playerInput = document.createElement('div');
				playerInput.className = 'form-group';
				playerInput.innerHTML = `
					<label for="playerName${i}" class="form-label">Player ${i} Name</label>
					<input type="text" class="form-control" id="playerName${i}" placeholder="Enter Player ${i} Name" required>
				`;
				playerNamesContainer.appendChild(playerInput);
			}
		}
	});

	$games.addEventListener('click', (event) => {
		if (event.target.matches('[data-path]')) {
			event.preventDefault();
			const path = event.target.getAttribute('data-path');
			selectedGameMode = document.querySelector('input[name="gameMode"]:checked').value;
			selectedGameType = document.querySelector('input[name="gameType"]:checked').value;
			navigate(path);
		}
	});

	function areNamesUnique(names) {
		const nameSet = new Set(names);
		return nameSet.size === names.length;
	}

	function shuffleArray(array) { //Fisher-Yates algorithm
		for (let i = array.length - 1; i > 0; i--) {
			const j = Math.floor(Math.random() * (i + 1));
			[array[i], array[j]] = [array[j], array[i]];
		}
		return array;
	}

	// Event listener to start the tournament
	$games.querySelector('#startTournament').addEventListener('click', () => {
		playerNames = [];
		let allNamesProvided = true;
		for (let i = 1; i <= tournamentPlayers; i++) {
			const playerName = document.getElementById(`playerName${i}`).value;
			if (!playerName) {
				allNamesProvided = false;
				break;
			}
			playerNames.push(playerName);
		}
		if (!allNamesProvided) {
			alert('Please enter all player names.');
			return;
		}
			if (!areNamesUnique(playerNames)) {
				alert('Player names must be unique.');
				return;
			}
		playerNames = shuffleArray(playerNames);
		startTournament(navigate);
	});
	return $games;
}

function startTournament(navigate) {
	alert(`Starting a tournament with ${tournamentPlayers} players: ${playerNames.join(', ')}`);
	alert(`First Match: ${playerNames[0]} vs ${playerNames[1]}!`);
	const tournamentGameTypeElement = document.getElementById('tournamentGameType');
	if (tournamentGameTypeElement) {
		const gamePath = tournamentGameTypeElement.value === 'pong' ? '/pong' : '/asteroids';
		const tournamentData = {
			playerNames: playerNames,
			gameType: tournamentGameTypeElement.value,
			numberOfGames: tournamentPlayers / 2 // Assuming each game is between two players
		};
		localStorage.setItem('tournamentData', JSON.stringify(tournamentData)); // Store data in local storage
        localStorage.setItem('tournamentWinners', JSON.stringify([])); // Initialize winners
		navigate(gamePath);
	} else {
		console.log('Tournament game type element not found when starting the tournament.');
	}
}

export function getSelectedGameMode() {
	return selectedGameMode;
}

export function getSelectedGameType() {
	return selectedGameType;
}
