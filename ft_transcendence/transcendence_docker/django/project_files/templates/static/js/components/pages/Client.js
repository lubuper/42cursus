const messageCache = {};
export const chatSockets = {}; // Track active WebSocket connections
const blockedUsers = []; // Array to store blocked users

function saveBlockedUsers() {
    localStorage.setItem('blockedUsers', JSON.stringify(blockedUsers));
}

export function Initialize(friendName, userName) {

    if (blockedUsers.includes(friendName)) {
        return;
    }

    const chatKey = `${userName}-${friendName}`;
    const chat = document.getElementsByClassName('chat-popup')

    if (chatSockets[chatKey]) {
        return; // Prevent multiple connections for the same user-friend pair
    }

    const chatSocket2 = new WebSocket(`wss://${window.location.host}/ws/chat/${userName}/${friendName}/`);
    chatSockets[chatKey] = chatSocket2; // Store the WebSocket connection

    chatSocket2.addEventListener('message', function (e) {
        const data = JSON.parse(e.data);
        const timestamp = Date.now();

        if(chat.length !== 0){
            return
        }

        if (!messageCache[friendName]) {
            messageCache[friendName] = [];
        }

        if (data.sender === friendName) {
            messageCache[friendName].push({
                sender: data.sender,
                message: data.message,
                timestamp,
                destination: userName
            });
        }

        updateChatIcons(friendName);
    })

    chatSocket2.onclose = function () {
        delete chatSockets[chatKey]; // Clean up the WebSocket reference
    };
}

export function setupChat(friendName, userName) {
    const chatKey = `${userName}-${friendName}`;
    const messageContainer = document.getElementById(`messages-${userName}-${friendName}`);

    if (!messageContainer) {
        return;
    }

    let chatSocket

    // Prevent reopening WebSocket for the same user-friend pair
    if (chatSockets[chatKey]) {
        chatSocket = chatSockets[chatKey]
    }else{
        chatSocket = new WebSocket(`wss://${window.location.host}/ws/chat/${userName}/${friendName}/`);
        chatSockets[chatKey] = chatSocket;
    }

    const handler =  (e) => {
        const data = JSON.parse(e.data);
        const newMessage = document.createElement('p');
        const timestamp = Date.now();
        const formattedTime = formatTimestamp(timestamp); // Get the current timestamp
        const statusDot = document.getElementById(`friend-status-${friendName}`).getAttribute('data-status');

        newMessage.textContent = `${data.sender} ${formattedTime}: ${data.message}`;

        if (!messageCache[friendName]) {
            messageCache[friendName] = [];
        }

        if (!messageCache[userName]) {
            messageCache[userName] = [];
        }

        if (data.type === "game_invitation") {
            // Handle game invitation message
            newMessage.classList.add('system-message'); // Use a different class for system messages
            newMessage.textContent = `${data.sender} ${formattedTime}: ${data.message}`;
        }

        // Cache messages and update UI
        if (data.sender === friendName) {
            newMessage.classList.add('friend-message');
            messageCache[friendName].push({ sender: data.sender, message: data.message, timestamp, destination: userName });
            updateChatIcons(friendName);
        } else if (data.sender === userName) {
            newMessage.classList.add('my-message');
            if(statusDot === 'online'){
                messageCache[userName].push({ sender: data.sender, message: data.message, timestamp, destination: friendName });
            }else{
                newMessage.textContent = `-- Message was not sent. ${friendName} is offline --`;
            }
        }

        messageContainer.appendChild(newMessage);
        messageContainer.scrollTop = messageContainer.scrollHeight;
    }

    chatSocket.addEventListener('message', handler)

    document.querySelector('.close-btn').addEventListener('click', () => {
        chatSocket.removeEventListener('message', handler)
    });

    const chatIcons = document.querySelectorAll('.chat-icon');
    const chatIcons2 = document.querySelectorAll('.chat-icon2');

    chatIcons.forEach((icon, index) => {
        icon.addEventListener('click', (event) => {
            chatSocket.removeEventListener('message', handler)
		});
    });

    chatIcons2.forEach((icon, index) => {
        icon.addEventListener('click', (event) => {
            chatSocket.removeEventListener('message', handler)
		});
    });

        chatSocket.onclose = function () {
            delete chatSockets[chatKey];
        };

    // Attach event listener for the "SEND" button
    const senderButton = document.querySelector(`#chat-box-${userName}-${friendName} .sender`);
    const inputField = document.querySelector(`#chat-box-${userName}-${friendName} .message-input`);

    if (senderButton && inputField) {
        senderButton.onclick = () => {
            const message = inputField.value.trim();
            if (message && chatSockets[chatKey] && chatSockets[chatKey].readyState === WebSocket.OPEN) {
                chatSockets[chatKey].send(JSON.stringify({ message })); // Send message through WebSocket
                inputField.value = ''; // Clear input field
            } else {
                console.log('WebSocket is not open or message is empty');
            }
        };

         // Add event listener to clear notifications on focus
         inputField.addEventListener('focus', () => {
            const chatIcon = document.querySelector(`.chat-icon[data-friend="${friendName}"]`);
            const chatIcon2 = document.querySelector(`.chat-icon2[data-friend="${friendName}"]`);

            if (chatIcon) {
                chatIcon.classList.remove('display-none');
            }
            if (chatIcon2) {
                chatIcon2.classList.add('display-none');
            }
        });

        // Add "Enter" key functionality
        inputField.onkeyup = (e) => {
            if (e.key === 'Enter') {
                senderButton.click();
            }
        };
    } else {
        console.log('Sender button or input field not found');
    }
}

export function displayMessages(friendName, userName) {
    const messageContainer = document.getElementById(`messages-${userName}-${friendName}`);
    if (!messageContainer) return;

    // Clear the current messages
    messageContainer.innerHTML = '';

    // Combine and sort messages by timestamp
    const combinedMessages = [
        ...(messageCache[friendName]?.filter(msg => msg.destination === userName) || []),
        ...(messageCache[userName]?.filter(msg => msg.destination === friendName) || [])
    ].sort((a, b) => a.timestamp - b.timestamp);

    // Display the sorted messages with timestamps
    combinedMessages.forEach(msg => {
        const newMessage = document.createElement('p');
        const formattedTime = formatTimestamp(msg.timestamp); // Format the timestamp

        if (msg.sender === friendName) {
            newMessage.classList.add('friend-message');
        } else if (msg.sender === userName) {
            newMessage.classList.add('my-message');
        }

        newMessage.textContent = `${msg.sender} ${formattedTime}: ${msg.message}`; // Include timestamp
        messageContainer.appendChild(newMessage);
    });

    messageContainer.scrollTop = messageContainer.scrollHeight;
}

function updateChatIcons(friendName) {
    const chatIcons = document.querySelectorAll('.chat-icon');
    const chatIcons2 = document.querySelectorAll('.chat-icon2');

    chatIcons.forEach((icon, index) => {
        if (icon.getAttribute('data-friend') === friendName) {
            icon.classList.add('display-none');
            chatIcons2[index].classList.remove('display-none');
        }
    });
}

function formatTimestamp(timestamp) {
    const date = new Date(timestamp);
    const hours = String(date.getHours()).padStart(2, '0');
    const minutes = String(date.getMinutes()).padStart(2, '0');
    const seconds = String(date.getSeconds()).padStart(2, '0');
    return `${hours}:${minutes}:${seconds}`;
}

export function toggleBlockStatus(friendName, userName) {
    const index = blockedUsers.indexOf(friendName);

    if (index !== -1) {
        // Unblock user
        blockedUsers.splice(index, 1);
        saveBlockedUsers();
        showChatIcon(friendName);
    } else {
        // Block user
        blockedUsers.push(friendName);
        saveBlockedUsers();
        hideChatIcon(friendName);

        // Close any active chat for the blocked user
        closeChatBox(friendName);
        stopWebSocket(friendName, userName);
    }
}

function stopWebSocket(friendName, userName) {
    const chatKey = `${userName}-${friendName}`;
    if (chatSockets[chatKey]) {
        chatSockets[chatKey].close();
        delete chatSockets[chatKey];
    }
}

function hideChatIcon(friendName) {
    const chatIcon = document.querySelector(`.chat-icon[data-friend="${friendName}"]`);
    const chatIcon2 = document.querySelector(`.chat-icon2[data-friend="${friendName}"]`);
    if (chatIcon) {
        chatIcon.style.display = 'none';
    }
    if (chatIcon2) {
        chatIcon2.style.display = 'none';
    }
}

function showChatIcon(friendName) {
    const chatIcon = document.querySelector(`.chat-icon[data-friend="${friendName}"]`);
    const chatIcon2 = document.querySelector(`.chat-icon2[data-friend="${friendName}"]`);
    const blockIcon = document.querySelector(`.block-icon[data-friend="${friendName}"]`);

    if (chatIcon && blockIcon) {
        chatIcon.style.display = 'inline'; // Correctly show the chat icon inline
        blockIcon.parentNode.insertBefore(chatIcon, blockIcon.nextSibling); // Ensure correct position
    }

    if (chatIcon2) {
        chatIcon2.style.display = 'none';
    }
}

function closeChatBox(friendName) {
    const chatBox = document.getElementById(`chat-box-${friendName}`);
    if (chatBox) {
        chatBox.remove();
    }
}
