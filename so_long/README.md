## ABOUT
The so_long project is a 2D game where the player navigates through a maze-like environment, avoiding obstacles and enemies to reach a goal.
It is created using the MiniLibX library and requires students to implement game mechanics, file input/output, and basic graphics.

<a href="https://github.com/lubuper/so_long/blob/master/subject/en_subject_so_long.pdf">Click here</a> for the subject of this project.

## HOW TO USE
#### COMPILATION AND EXECUTION
#### 1º - Clone the repository
```bash
git clone git@github.com:lubuper/so_long.git
```
#### 2º - Enter the project folder and run `make` or `make bonus`
> **Important:** To run the program, you will need to download MiniLibX.
```bash
cd so_long/so_long
make or make bonus
```

#### 3º - Run the game with a map of your choice
```bash
./so_long [map.ber]
./so_long_bonus [map_bonus.ber]
```

#### MAKEFILE RULES

`make` - Compile so_long files.

`make bonus` - Compile so_long_bonus files.

`make all`  - Compile mandatory + bonus files.

`make clean`  - Delete all .o (object files) files.

`make fclean`  - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
- [x] Must use MiniLibX.
- [x] Makefile must compile source files and should not relink.
- [x] The program has to take as a parameter a map description file ending with the `.ber` extension.

#### GAME
- [x] **Goal:** Collect every collectable and escape choosing the shortest route.
- [x] `W`, `A`, `S` and `D` keys must be used to move the main character `up`, `down`, `left` and `right`.
- [x] Can't move into walls.
- [x] Number of movements must be displayed in the shell.
- [x] Must be a 2D view (top-down or profile).
- [x] Doesn't need to be real-time.

#### GRAPHIC MANAGEMENT
- [x] Display the image in a window and must remain smooth (changing windows, minimizing, ...).
- [x] Pressing `ESC` must close the window and quit the program in a clean way.
- [x] Clicking on the window cross must also close and quit the program in a clean way.
- [x] The use of the images of the MiniLibx is mandatory.

#### MAP COMPONENTS
- [x] The map should include 3 components to be constructed: walls, collectables and free space.
- [x] Should be composed of only these 5 characters:

| Characters | Description |
| :--: | :--: |
| `0` | Empty space.              |
| `1` | Wall.                     |
| `C` | Collectible.              |
| `E` | Map exit.                 |
| `P` | Player starting position. |

#### MAP VALIDATION
- [x] The map must contain 1 exit, at least 1 collectable, and 1 starting position to be valid.
- [x] Map must be rectangular.
- [x] Map must be closed/surrounded by walls. If not, the program should return an error.
- [x] Check if there is a valid path in the map.
- [x] The program must be able to parse any kind of map, as long it respects the rules.
- [x] If an error/misconfiguration is encountered, it should return `Error\n` followed by an explicit message.

Map `.ber` example:
```
111111111111
1001000000C1
100000011101
1P0011E00001
111111111111
```

## BONUS
- [x] Develop original extra features (optional).
- [x] Make the player lose when they touch an enemy patrol.
- [x] Add sprite animation.
- [x] Display the movement count directly on the screen, instead of writing in the shell.
