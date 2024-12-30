export default function Home() {
	const $home = document.createElement('home')
	$home.innerHTML = `
		<button id="localplaybutton" class="btn btn-purple btn-lg mx-5 nav-link text-white shadow-lg" data-path="/localplay">Local Play</button>
		<button id="remoteplaybutton" class="btn btn-purple btn-lg mx-5 nav-link text-white shadow-lg mt-3" data-path="/remoteplay">Remote Play</button>
	`
	return $home
}