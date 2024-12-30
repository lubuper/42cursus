export default function GameLost() {
	const loser = localStorage.getItem('localUser') || 'Player 1';
	const $gameLost = document.createElement('gamelost');
	$gameLost.innerHTML = `
		<div class="vh-100 d-flex flex-column align-items-center justify-content-center text-center">
			<h2 class="text-white">Game Over ${loser}!</h2>
			<p class="text-white">You'll get them next time!</p>
			<div class="mt-3">
				<button class="btn btn-purple btn-lg text-white shadow-lg" data-path="/">Go Back To HomePage</button>
			</div>
		</div>
	`;

	return $gameLost;
}