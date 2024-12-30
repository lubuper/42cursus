export default function Footer() {
	const $footer = document.createElement('footer')
	$footer.innerHTML = `
		<footer class="navbar navbar-expand-lg d-flex justify-content-between" style="background: transparent; position: fixed; bottom: 0; width: 100%;">
			<div class="d-flex">
				<button class="btn btn-purple btn-custom mx-1 nav-link text-white shadow-lg" data-path="/aboutus">About Us</button>
			</div>
		</footer>
	`
	return $footer
}