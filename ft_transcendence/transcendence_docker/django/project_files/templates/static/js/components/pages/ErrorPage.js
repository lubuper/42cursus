export default function ErrorPage() {
	const $error = document.createElement('error');
	$error.innerHTML = `
		<div class="vh-100 d-flex align-items-center justify-content-center position-relative">
			<div class="text-center">
				<h1 class="text-white">404</h1>
				<p class="text-purple">The url you tried to access doesn't exist</p>
				<button class="btn btn-purple btn-lg text-white shadow-lg" onclick="window.history.back()">Go Back</button>
			</div>
		</div>
	`
	return $error;
}