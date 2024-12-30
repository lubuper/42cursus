import { navigate } from "../helpers/App.js";
import background from '../components/background.js';

export default function Header() {
	const $header = document.createElement('header');

	fetch('/current-user/')
		.then(async (response) => {
			const user = await response.json();
			localStorage.setItem('localUser', user.username);
			const base = `
				<nav class="navbar navbar-expand-lg d-flex justify-content-between" style="background: transparent;">
					<h1 class="fw-bold text-center text-white display-6 ms-3" data-path="/">ft_transcendence</h1>
					<div class="d-flex align-items-center" id="loggedInFlag">
						<button class="btn btn-purple btn-custom mx-1 nav-link text-white shadow-lg d-flex align-items-center" data-path="/profile">
							<img src="${user.profile_picture}" alt="${user.username}'s profile picture" style="width: 30px; height: 30px; border-radius: 50%; margin-right: 8px;">
							${user.username}
						</button>
						<button class="btn btn-danger btn-custom mx-1 nav-link text-white shadow-lg" id="logout-btn">Logout</button>
						<button class="btn btn-purple btn-custom mx-1 nav-link text-white shadow-lg" data-path="/dashboard">Dashboard</button>
					</div>
				</nav>
			`;
			$header.innerHTML = base;

			if (user.username) {
				const logoutButton = $header.querySelector('#logout-btn');
				logoutButton.addEventListener('click', async () => {
					await fetch('/logout/', { method: 'POST', credentials: 'same-origin' });
					setTimeout(() => {
						navigate('/'); // Redirect to home page after 1 second
					}, 1000);
				});
			}
		})
		.catch((error) => {
			$header.innerHTML = `
				<nav class="navbar navbar-expand-lg d-flex justify-content-between" style="background: transparent;">
					<h1 class="fw-bold text-center text-white display-6 ms-3" data-path="/">ft_transcendence</h1>
					<div class="d-flex">
						<button class="btn btn-purple btn-custom mx-1 nav-link text-white shadow-lg" data-path="/login">Login</button>
						<button class="btn btn-purple btn-custom mx-1 nav-link text-white shadow-lg me-3" data-path="/createaccount">Create Account</button>
					</div>
				</nav>
			`;
		});

	return $header;
}