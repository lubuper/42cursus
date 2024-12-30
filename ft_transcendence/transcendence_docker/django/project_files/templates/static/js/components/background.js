export default function background() {
	const $player = document.createElement('div');
	$player.innerHTML = `
		<div style="position: fixed; top: 0; left: 50%; transform: translateX(-50%); z-index: 100;">
			<audio id="audioplayer" controls autoplay loop style="max-width: 300px; width: 100%;">
				<source src="/static/media/assets/music/track1.mp3" type="audio/mp3">
			</audio>
			<select id="musicSelection" style="display: block; margin: 0 auto;">
				<option value="/static/media/assets/music/track1.mp3">Hungarian Dance</option>
				<option value="/static/media/assets/music/track2.mp3">The Ascent (version a)</option>
				<option value="/static/media/assets/music/track3.mp3">Midnight Explosion</option>
				<option value="/static/media/assets/music/track4.mp3">Maximum Overdrive</option>
			</select>
		</div>
		<video id="videoplayer" autoplay loop muted
			style="pointer-events: none; position: fixed; top: 0; left: 0; width: 100%; height: 100%; object-fit: cover; z-index: -1;">
			<source src="/static/media/assets/1.mp4" type="video/mp4">
		</video>
	`;

	const audioPlayer = $player.querySelector('#audioplayer');
	const musicSelection = $player.querySelector('#musicSelection');
	audioPlayer.volume = 0.2;

	// Handle the ended event to loop the track or play the next one
	audioPlayer.addEventListener('ended', function() {
		const selectedIndex = musicSelection.selectedIndex;
		const nextIndex = (selectedIndex + 1) % musicSelection.options.length;
		musicSelection.selectedIndex = nextIndex;
		audioPlayer.src = musicSelection.value;
		audioPlayer.play();
	});

	musicSelection.addEventListener('change', function() {
		// Fade out the current track
		let currentVolume = audioPlayer.volume;
		const fadeOutInterval = setInterval(() => {
			if (currentVolume > 0.05) {
				currentVolume -= 0.05;
				audioPlayer.volume = currentVolume;
			} else {
				clearInterval(fadeOutInterval);
				audioPlayer.src = this.value;
				audioPlayer.volume = 0; // Start with volume at 0
				audioPlayer.play();
				const fadeInInterval = setInterval(() => {
					if (audioPlayer.volume < 0.2) {
						audioPlayer.volume += 0.05;
					} else {
						clearInterval(fadeInInterval);
					}
				}, 100);
			}
		}, 100);
	});

	return $player;
}