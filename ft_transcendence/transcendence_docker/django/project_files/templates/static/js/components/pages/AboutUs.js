export default function AboutUs() {
	const $aboutUs = document.createElement('aboutus');
	$aboutUs.innerHTML = `
		<div class="vh-100 d-flex flex-column align-items-center justify-content-center text-center">
			<h1 class="text-white">About Me</h1>
			<p class="text-white">We are a 42 Porto group of students in the last project: ft_transcdendence</p>
			<p class="text-white"><a href="https://github.com/lubuper" target="_blank">Luis Pereira</a>, <a href="https://github.com/macastanm" target="_blank">Maria Marques</a>, <a href="https://github.com/Zpedro99" target="_blank">Jose Goncalves</a>, <a href="https://github.com/RafaSoares1" target="_blank">Rafael Soares</a></p>
			<p class="text-white">Apologies for the mistakes, the learning curve is always steep!</p>
			<p class="text-white">You can find more info on 42 Porto <a href="https://www.42porto.com/" target="_blank">Here</a>.</p>
			<h4 class="text-white">Special thanks to the authors of the models, textures and sound effects modified or/and used in this project:</h4>
			<p class="text-white"><br>dklon
			<br>NenadSimic
			<br>Bogardt VGM - https://www.facebook.com/BogartVGM/
			<br>iamoneabe
			<br>pauliuw
			<br>AntumDeluge
			<br>contact@solarsystemscope.com
			<br>rubberduck
			</p>
			<button class="btn btn-purple btn-lg text-white shadow-lg mt-3" onclick="window.history.back()">Go Back</button>
		</div>
	`
	return $aboutUs
}