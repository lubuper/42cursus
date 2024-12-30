import { navigate } from '../../helpers/App.js';

export default function Profile() {
    const $ProfileForm = document.createElement('profile');

    const base = `
		<h1>You are not logged yet!</h1>
	`

    $ProfileForm.innerHTML = base;

    fetch('/profile/')
        .then(async (response) => {

            if (!response.ok) {
                throw new Error('Failed to fetch profile data');
            }
            const user = await response.json();

            const profilePicHTML = user.profile_picture
                ? `<img src="${user.profile_picture}" alt="${user.username}'s profile picture" 
                     class="rounded-circle mb-3" 
                     alt="Avatar" 
                     style="width: 200px; height: 200px;">`
                : '<div>No profile picture available</div>';

            $ProfileForm.innerHTML = `
            <style>
            .bar{
				display: block;
				background-color: #582a6b;
			}
			.bar h1{
				margin: 0px;
				font-size: 22px;
				padding: 10px;
				color: white;
				-webkit-font-smoothing: antialiased;
				-moz-osx-font-smoothing: grayscale;
				font-weight: normal;
			}
			.profile-photo-div{
				position: relative;
				margin: 0px auto 0px auto;
				width: 200px;
				height: auto;
				overflow: hidden;
				border-radius: 10px;
				-webkit-transition: ease .3s;
				-o-transition: ease .3s;
				transition: ease .3s;
			}
			.profile-img-div{
				display: block;
				position: relative;
				overflow: hidden;
			}
			#loader{
				position: absolute;
				top:0;
				left: 0;
				width: 0%;
				height: 100%;
				background-color: #582a6b;
				z-index:10;
				-webkit-transition: .3s;
				-o-transition: .3s;
				transition: .3s;
			}
			#profile-img{
				position: absolute;
				display: block;
				width: 100%;
				height: 100%;
				top: 0;
				left: 0;
			}
			#change-photo{
				display: none;
			}
			.profile-buttons-div{
				position: relative;
				display: block;
			}
			.button{
				position: relative;
				display: block;
				font-size: 15px;
				padding:20px;
				text-align: center;
				color: white;
				background-color: #582a6b;
				cursor: pointer;
				-webkit-transition: .5s;
				-o-transition: .5s;
				transition: .5s;
				overflow: hidden;
				-webkit-font-smoothing: antialiased;
				-moz-osx-font-smoothing: grayscale;
			}
			.button:hover{
				letter-spacing: 1px;
			}
			.button:after{
				content: '';
				position: absolute;
				top: 50%;
				left: 50%;
				-webkit-transform: translate(-50%,-50%);
				-ms-transform: translate(-50%,-50%);
				transform: translate(-50%,-50%);
				width: 10px;
				height: 10px;
				background-color: rgba(255,255,255,0.4);
				border-radius: 50%;
				opacity: 0;
				-webkit-transition: .9s;
				-o-transition: .9s;
				transition: .9s;
			}
			.button:hover:after{
				-webkit-transform: scale(50);
				-ms-transform: scale(50);
				transform: scale(50);
				opacity: 1;
			}
			.button.half{
				width: 50%;
			}
			.green{
				background-color: #15ae6b;
			}
			.red{
				background-color: #ae0000;
			}
			#x-position{
				position: absolute;
				bottom: 5px;
				left: 50%;
				-webkit-transform: translateX(-50%);
				-ms-transform: translateX(-50%);
				transform: translateX(-50%);
				display: none;
			}
			#y-position{
				position: absolute;
				right: -50px;
				top: 50%;
				-webkit-transform: translateY(-50%) rotate(90deg);
				-ms-transform: translateY(-50%) rotate(90deg);
				transform: translateY(-50%) rotate(90deg);
				display: none;
			}
			canvas{
				position: fixed;
				top: -2000px;
				left: -2000px;
				z-index: -1;
			}
			.profile-img-confirm{
				display: -webkit-box;
				display: -webkit-flex;
				display: -ms-flexbox;
				display: flex;
				width: 100%;
			}
			.error{
				font-family: Helvetica, sans-serif;
				font-size: 13px;
				color: red;
				text-align:center;
				display: none;
			}
            </style>
			<div class="d-flex align-items-center justify-content-center position-relative">
            <div class="container row justify-content-center col-md-2">
                <form id="profile-form" enctype="multipart/form-data">
                    <div class="form-group">
                        <label class="text-white">Profile Picture</label>
                        <div class="profile-photo-div" id="profile-photo-div">
                            <div class="profile-img-div" id="profile-img-div">
                                <div id="loader">
                                    </div>
                                    <img id="profile-img" src="${user.profile_picture}" />
                                    <input id="x-position" type="range" name="x-position" value="0" min="0" />
                                    <input id="y-position" type="range" name="y-position" value="0" min="0" />
                                    </div>
                                <div class="profile-buttons-div">
                                    <div class="profile-img-input" id="profile-img-input">
                                    <label class="button" id="change-photo-label" for="change-photo">Upload Photo</label>
                                    <input id="change-photo" name="change-photo" type="file" style="display: none" accept="image/*" />
                                </div>
                                <div class="profile-img-confirm" id="profile-img-confirm" style="display: none">
                                    <div class="button half green" id="save-img">
                                    <span aria-hidden="true">Crop</span>
                                    </div>
                                    <div class="button half red" id="cancel-img">
                                    <span aria-hidden="true">Cancel</span>
                                </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="error" id="error">min sizes 400*400px</div>
                    <canvas id="croppedPhoto" width="400" height="400"></canvas>
                    <div class="form-group">
                        <label for="username" class="text-white">Username</label>
                        <input type="text" class="form-control" id="username" name="username" value="${user.username}" readonly required>
                    </div>
                    <div class="form-group">
                        <label for="email" class="text-white">Email</label>
                        <input type="email" class="form-control" id="email" name="email" value="${user.email}" required>
                    </div>
                    <div class="form-group">
                        <label for="new-password" class="text-white">New Password</label>
                        <input type="password" class="form-control" id="new-password" name="new-password">
                    </div>
                    <div class="form-group">
                        <label for="new-confirmPassword" class="text-white">Confirm New Password</label>
                        <input type="password" class="form-control" id="new-confirmPassword" name="new-confirmPassword">
                    </div>
                    <div class="form-group">
                        <label for="password" class="text-white">Insert your Password to confirm changes</label>
                        <input type="password" class="form-control" id="old-password" name="old-password" required>
                    </div>
                    <button type="submit" class="btn btn-purple btn-custom mt-3 text-white">Save</button>
                	<div id="update-account-message"></div>
                </form>
            </div>
            </div>
	        `;

            const $profileImgDiv = document.getElementById("profile-img-div"),
                  $profileImg = document.getElementById("profile-img"),
                  $changePhoto = document.getElementById("change-photo"),
                  $xPosition = document.getElementById("x-position"),
                  $yPosition = document.getElementById("y-position"),
                  $saveImg = document.getElementById("save-img"),
                  $loader = document.getElementById("loader"),
                  $cancelImg = document.getElementById("cancel-img"),
                  $profileImgInput = document.getElementById("profile-img-input"),
                  $profileImgConfirm = document.getElementById("profile-img-confirm"),
                  $error = document.getElementById("error");

            let currentProfileImg = ""
            let profileImgDivW = getSizes($profileImgDiv).elW
            let NewImgNatWidth = 0
            let NewImgNatHeight = 0
            let NewImgNatRatio = 0
            let NewImgWidth = 0
            let NewImgHeight = 0
            let NewImgRatio = 0
            let xCut = 0
            let yCut = 0
            let profilePictureFinal;

            makeSquared($profileImgDiv);

            $changePhoto.addEventListener("change", function() {
                currentProfileImg = $profileImg.src;
                showPreview(this, $profileImg);
                $loader.style.width = "100%";
                $profileImgInput.style.display = "none";
                $profileImgConfirm.style.display = "flex";
                $error.style.display = "none";
            });

            $xPosition.addEventListener("input", function() {
                $profileImg.style.left = -this.value + "px";
                xCut = this.value;
                yCut = 0;
            });

            $yPosition.addEventListener("input", function() {
                $profileImg.style.top = -this.value + "px";
                yCut = this.value;
                xCut = 0;
            });

            $saveImg.addEventListener("click", function() {
                cropImg($profileImg);
                // resetAll(true);
            });

            $cancelImg.addEventListener("click", function() {
                resetAll(false);
            });

            window.addEventListener("resize", function() {
                makeSquared($profileImgDiv);
                profileImgDivW = getSizes($profileImgDiv).elW;
            });

            function makeSquared(el) {
                let elW = el.clientWidth;
                el.style.height = elW + "px";
            }

            function showPreview(input, el) {
                let reader = new FileReader();
                reader.readAsDataURL(input.files[0]);
                if (input.files && input.files[0]) {
                    reader.onload = function(e) {
                        setTimeout(function() {
                            el.src = e.target.result;
                        }, 300);

                        let poll = setInterval(function() {
                            if (el.naturalWidth && el.src != currentProfileImg) {
                                clearInterval(poll);
                                setNewImgSizes(el);
                                setTimeout(function() {
                                    $loader.style.width = "0%";
                                    $profileImg.style.opacity = "1";
                                }, 1000);
                            }
                        }, 100);
                    };
                } else {
                    return;
                }
            }

            function setNewImgSizes(el) {
                if (getNatSizes(el).elR > 1) {
                    el.style.width = "auto";
                    el.style.height = "100%";
                    NewImgNatWidth = getSizes(el).elW;
                    $xPosition.style.display = "block";
                    $yPosition.style.display = "none";
                    $xPosition.max = NewImgNatWidth - profileImgDivW;
                } else if (getNatSizes(el).elR < 1) {
                    el.style.width = "100%";
                    el.style.height = "auto";
                    NewImgNatHeight = getSizes(el).elH;
                    $xPosition.style.display = "none";
                    $yPosition.style.display = "block";
                    $yPosition.max = NewImgNatHeight - profileImgDivW;
                } else if (getNatSizes(el).elR == 1) {
                    el.style.width = "100%";
                    el.style.height = "100%";
                    $xPosition.style.display = "none";
                    $yPosition.style.display = "none";
                }
            }

            function getNatSizes(el) {
                let elW = el.naturalWidth,
                    elH = el.naturalHeight,
                    elR = elW / elH;
                return {
                    elW: elW,
                    elH: elH,
                    elR: elR
                };
            }

            function getSizes(el) {
                let elW = el.clientWidth,
                    elH = el.clientHeight,
                    elR = elW / elH;
                return {
                    elW: elW,
                    elH: elH,
                    elR: elR
                };
            }

            function cropImg(el) {
                let natClientImgRatio = getNatSizes(el).elW / getSizes(el).elW;
                const myCanvas = document.getElementById("croppedPhoto");
                const ctx = myCanvas.getContext("2d");
                ctx.fillStyle = "#ffffff";
                ctx.fillRect(0, 0, 400, 400);
                try {
                    ctx.drawImage(
                        el,
                        xCut * natClientImgRatio,
                        yCut * natClientImgRatio,
                        profileImgDivW * natClientImgRatio,
                        profileImgDivW * natClientImgRatio,
                        0,
                        0,
                        400,
                        400
                    );
                } catch (error) {
                    alert("Please upload a valid image file.");
                    resetAll(false);
                    return;
                }
                let newProfileImgUrl = myCanvas.toDataURL("image/jpeg");
                $profileImg.src = newProfileImgUrl;
                myCanvas.toBlob((blob) => {
                    profilePictureFinal = blob;  // Store the cropped image blob
                }, 'image/jpeg');
                resetAll(true);
            }

            function resetAll(confirm) {
                if (!confirm) {
                    $profileImg.src = currentProfileImg;
                }
                $changePhoto.value = "";
                $profileImgInput.style.display = "block";
                $profileImgConfirm.style.display = "none";
                $profileImg.style.left = "0";
                $profileImg.style.top = "0";
                $profileImg.style.width = "100%";
                $profileImg.style.height = "100%";
                $xPosition.style.display = "none";
                $yPosition.style.display = "none";
                $xPosition.value = "0";
                $yPosition.value = "0";
                xCut = "0";
                yCut = "0";
            }

            function checkMinSizes(el) {
                if (getNatSizes(el).elW > 400 && getNatSizes(el).elH > 400) {
                    return true;
                } else {
                    return false;
                }
            }

            const formP = $ProfileForm.querySelector('#profile-form');

            formP.addEventListener('submit', async (event) => {
                event.preventDefault(); // Prevent default form submission

                const form = document.getElementById('profile-form');

                const formPData = new FormData(form);

                const data = Object.fromEntries(formPData.entries());

                if (profilePictureFinal) {
                    formPData.set('profile-picture', profilePictureFinal, 'user.jpeg');
                }


                try {
                    const response = await fetch('/update_profile/', {
                        method: 'POST',
                        headers: {
                            'X-CSRFToken': getCookie('csrftoken')
                        },
                        body: formPData,
                    });

                    const UPMessage = document.getElementById('update-account-message');

                    const result = await response.json();

                    if (response.ok) {
                        UPMessage.innerHTML = '<p class="text-success">Account updated successfully!</p>';
                        setTimeout(() => {
                            navigate('/');
                        }, 2000);
                    } else {
                        UPMessage.innerHTML = `<p class="text-danger">Failed to update account: ${result.message || 'Unknown error'}</p>`;
                    }
                } catch (error) {
                    console.log('Error:', error);
                }
            });

        })
        .catch((error) => {
            console.log("error", error)
            $ProfileForm.innerHTML = `
			${base}
			`
        })

    return $ProfileForm;
}

function getCookie(name) {
    let cookieValue = null;
    if (document.cookie && document.cookie !== '') {
        const cookies = document.cookie.split(';');
        for (let i = 0; i < cookies.length; i++) {
            const cookie = cookies[i].trim();
            // Check if this cookie string begins with the name we want
            if (cookie.substring(0, name.length + 1) === (name + '=')) {
                cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
                break;
            }
        }
    }
    return cookieValue;
}
