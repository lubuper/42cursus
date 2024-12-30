export default function GameWon() {
	const winner = localStorage.getItem('localUser') || 'Player 1';
	const $gameWon = document.createElement('gamewon');
	$gameWon.innerHTML = `
		<div class="vh-100 d-flex flex-column align-items-center justify-content-center text-center">
			<h2 class="text-white">Congratulations ${winner}!</h2>
			<p class="text-white">You have won!</p>
			<div class="mt-3">
				<button class="btn btn-purple btn-lg text-white shadow-lg" data-path="/">Go Back To HomePage</button>
			</div>
		</div>
	`;

	return $gameWon;
}