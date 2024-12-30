import { navigate } from '../../helpers/App.js';

export default function Login() {
	const $loginForm = document.createElement('loginForm');
	$loginForm.innerHTML = `
		<div class="vh-100 d-flex align-items-center justify-content-center position-relative">
			<div class="container row justify-content-center col-md-2">
				<form id="loginForm">
					<div class="form-group">
						<label for="username" class="text-white">Username</label>
						<input type="text" class="form-control" id="username" required>
					</div>
					<div class="form-group">
						<label for="password" class="text-white">Password</label>
						<input type="password" class="form-control" id="password" required>
					</div>
					<button type="submit" class="btn btn-purple btn-custom mt-3 text-white">Login</button>
					<div id="login-message"></div>
				</form>
			</div>
		</div>
	`;

	$loginForm.querySelector('#loginForm').addEventListener('submit', async (event) => {
		event.preventDefault(); // Prevent the form from reloading the page

		const username = document.getElementById('username').value;
		const password = document.getElementById('password').value;

		const response = await fetch('/login/', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/json',
				'X-CSRFToken': getCookie('csrftoken') // Ensure you include the CSRF token
			},
			body: JSON.stringify({
				username: username,
				password: password
			})
		});

		const result = await response.json();
		const loginMessage = document.getElementById('login-message');

		if (response.ok) {
			loginMessage.innerHTML = '<p class="text-success">Login successful!</p>';
			setTimeout(() => {
				navigate('/');
			}, 1000);
		} else {
			loginMessage.innerHTML = `<p class="text-danger">Login failed: ${result.message}</p>`;
			setTimeout(() => {
				loginMessage.innerHTML = `<p </p>`;
			}, 500);
		}
	});

	return $loginForm;
}

// Helper function to get the CSRF token
function getCookie(name) {
	let cookieValue = null;
	if (document.cookie && document.cookie !== '') {
		const cookies = document.cookie.split(';');
		for (let i = 0; i < cookies.length; i++) {
			const cookie = cookies[i].trim();
			// Does this cookie string begin with the name we want?
			if (cookie.substring(0, name.length + 1) === (name + '=')) {
				cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
				break;
			}
		}
	}
	return cookieValue;
}