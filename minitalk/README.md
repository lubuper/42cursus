## ABOUT
Minitalk is a server/client system that uses UNIX signals for communication. The server displays its PID and receives decrypted signals as characters, while the client encrypts messages and sends true/false signals using SIGUSR1 or SIGUSR2 to the server's PID.

<a href="https://github.com/lubuper/minitalk/blob/master/subject/en_subject_minitalk.pdf">Click here</a> for the subject of this project.

## HOW TO USE
#### COMPILATION AND EXECUTION
#### 1º - Clone the repository
```bash
git clone https://github.com/lubuper/minitalk
```

#### 2º - Enter the project folder and run `make`
```bash
cd minitalk/minitalk
make
```

#### 3º - Run server or server_bonus and copy its PID
```bash
./server
./server_bonus
```

#### 4º - Open another terminal, run client or client_bonus, paste the PID and write a message
```bash
./client [SERVER PID] [MESSAGE]
./client_bonus [SERVER PID] [MESSAGE] [EMOTE]
```

#### MAKEFILE RULES

`make` - Compile minitalk **mandatory** files.

`make bonus` - Compile minitalk **bonus** files.

`make all` - Compile **mandatory** + **bonus** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
- [x] Produce server and client executables.
- [x] Client must communicate a string passed as a parameter to the server (referenced by its process ID) and display it.
- [x] Use `SIGUSR1` and `SIGUSR2` signals only.

## BONUS
- [x] Add reception acknowledgement system.
- [x] Support Unicode characters.
