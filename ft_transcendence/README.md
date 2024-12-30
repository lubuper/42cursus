# ft_transcendence

## Overview

The **ft_transcendence** project is the final undertaking in the 42 school’s Common Core curriculum. Its primary goal is to prepare students for real-world development challenges by combining software engineering principles, teamwork, and practical problem-solving. This capstone project involves the development of a comprehensive and real-time **Single Page Application (SPA)** using technologies, frameworks, and programming languages that were unfamiliar at the start of the project.

## Technologies Used

- **Backend**: Django, for robust and scalable server-side logic.
- **Frontend**: Plain JavaScript, ensuring a lightweight and dynamic user interface.
- **Database Management**: PostgreSQL, for efficient and reliable data handling.
- **Containerization**: Docker, ensuring consistent environments and streamlined deployment.
- **Styling**: Bootstrap and raw HTML/CSS, for responsive and visually appealing design.

## Project Highlights

### Core Features

- **Pong**: A recreation of a real-time multiplayer Pong game with hotseat and online gameplay options.
- **Asteroids**: A recreation of the old Asteroids game with multiplayer hotseat and single player options.
- **AI**: An AI with different difficulty settings available to play in Pong and in Asteroids games.
- **Matchmaking System**: Enables users to find and compete against players of similar skill levels.
- **Tournaments**: Supports competitive local gameplay with 4 or 8 players in turns.
- **Personalizations**: Includes profile picture upload, game power-ups, field customization and a selection of nine unique ships for gameplay variety.
- **Live Chat**: Text your friends and ask them to play with you via the Dashboard Chat.

### Advanced Functionality

- **Real-Time Interaction**: Utilized WebSockets for smooth and instantaneous communication between players.
- **Responsive Design**: Ensured compatibility across browsers, enhancing accessibility and user experience.

## Educational Objectives

1. **Skill Integration**: Combining backend, frontend, database management, and debugging skills in a cohesive project.
2. **Learning New Technologies**: Working with previously unfamiliar tools and frameworks to build confidence and adaptability.
3. **End-to-End Development**: Building an application from scratch, including architecture, testing, and deployment.
4. **Collaboration and Problem-Solving**: Working in a team environment to address challenges and deliver a polished product.

## Getting Started

### Prerequisites

- Linux preferred system or WSL console (Windows)
- Docker installed on the system.
- Basic knowledge of shell is recommended to navigate and start the App.

### Installation

1. Clone the repository:
   ```bash
   git clone git@github.com:lubuper/42cursus.git
   ```
2. Navigate to the project directory:
   ```bash
   cd 42cursus/ft_transcendence
   ```
3. Build and start the application using Makefile:
   ```bash
   make
   ```
4. Incorporate the self-signed SSL newly-created certificates:
   - 42cursus/ft_trancendence/transcendence_docker/nginx/ca.crt

5. Access the application:
   (You have to retrieve the server's IP address displayed on the first lines of your console after you use 'make')
   ```bash
   Host IP: ##.##.#.##
   ```
   - [https://##.##.#.##:8443]

### Usage

1. **Create Account**: Use a unique username, an email, and a secure password (8 characters, 1 uppercase, 1 number).
2. **Login**: Use the credentials you've just created.
3. **Start Playing**: Locally, against our AI opponent, or if anyone else is available remotely, just play!
4. **Explore Features**: Choose your ship, add and chat with friends, and track rankings.

---

