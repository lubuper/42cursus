export default function TournamentOver() {
	const $tournamentOver = document.createElement('tournamentover');
	$tournamentOver.innerHTML = `
		<div class="vh-100 d-flex flex-column align-items-center justify-content-center text-center">
			<h2 class="text-white">Congratulations everyone!</h2>
			<p class="text-white">The tournament has ended!</p>
			<div class="mt-3">
				<button class="btn btn-purple btn-lg text-white shadow-lg" data-path="/">Go Back To HomePage</button>
			</div>
		</div>
	`;

	return $tournamentOver;
}