## ABOUT
In the cub3D project, I delved into the realm of computer graphics, drawing inspiration from the legendary Wolfenstein 3D game, which stands as the pioneer of First Person Shooter (FPS) games. This endeavor wasn't just about coding; it was about reimagining a crucial piece of video game history through the lens of modern technology.

My task was to construct a vivid, three-dimensional maze exploration experience, entirely from a first-person viewpoint. I leveraged the C programming language, complemented by the capabilities of the miniLibX library, to breathe life into this vision.

What made this project especially challenging—and rewarding—was the intricate implementation it demanded. I was tasked with managing window operations smoothly, rendering textures on walls that changed based on their orientation to the player, and capturing the essence of movement through the maze with intuitive keyboard controls.

Moreover, I navigated through the complexities of parsing a custom map format, ensuring that my code gracefully handled any potential misconfigurations. This aspect of the project put my problem-solving skills to the test, challenging me to anticipate and mitigate errors before they occurred.

Beyond the sheer technicality of graphics programming, the cub3D project was a masterclass in code structure, efficient memory management, and the art of algorithmic problem-solving. It was an adventure that not only honored the legacy of a game that shaped an entire genre but also pushed me to the forefront of software development and design thinking.

## HOW TO USE
#### COMPILATION AND EXECUTION
#### 1º - Clone the repository
```bash
git clone https://github.com/lubuper/42cursus
```

#### 2º - Enter the project folder and run `make` or `make bonus`
```bash
cd cub3d/
make
```
or
```bash
cd cub3d/
make bonus
```

#### 3º - Run ./cub3D or ./cub3D_bonus and a map that is set in the maps folder
```bash
./cub3D maps/valid/dungeon.cub
```
or
```bash
./cub3D_bonus maps/vmapb1.cub
```

#### MAKEFILE RULES

`make` - Compile cub3D **mandatory** files.

`make bonus` - Compile cub3D **bonus** files.

`make all` - Compile **mandatory** + **bonus** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
- [x] W A S D to navigate the maze.
- [x] ESC closes the window.
- [x] left and right arrows change the point of view.

## BONUS
- [x] Wall collisions.
- [x] A minimap system.
- [x] Doors which open and close.
- [x] Animated sprites.
- [x] Usage of mouse to rotate the point of view
