## ABOUT
This project was a big milestone that was set to split the cursus in half. It was the first group project and it required us to build a simplified version of a Unix/Linux shell. It served us to understand the inner workings of command-line interpreters through tasks like parsing commands, implementing shell built-in commands (e.g., echo, cd), managing environment variables, basic signal handling, and implementing pipes and redirection for command input and output.

A big thank you to my collaborators Alexandre Fernandes - my group partner - João Oliveira and João Almeida for being a big part of the running wheel that this project was!

## HOW TO USE
#### COMPILATION AND EXECUTION
#### 1º - Clone the repository
```bash
git clone https://github.com/lubuper/42cursus.git
```

#### 2º - Enter the project folder and run `make`
```bash
cd minishell
make
```

#### 3º - Run the program
```bash
./minishell
```

#### 4º - Try commands you would on bash!
```cd
echo "hello!"
export SILLY=me
python3 some_python_script
exit
```

#### MAKEFILE RULES

`make` or `make all` - Compile minishell **mandatory** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.


#### NICE TO KNOW
> Some nice-to-know commands that will help the evaluatee and the evaluator.

| Important Commands                | Description                                                              |
| :-------------------------------- | :----------------------------------------------------------------------- |
| `make -n`                         | Display the compilation information without actually compiling the code. |
| `echo $?`                         | Display the exit status of the last executed command.                    |
| `nm -g ./minishell \| grep " U "` | Check for forbidden functions.                                           |
| `norminette`                      | Checks the code for compliance with the coding style and guidelines.     |
| `-R CheckForbiddenSourceHeader`   | Check the code in header files.                                          |
| `cc -g -Wall -Wextra -Werror`     | Compile with the mandatory flags.                                        |
| `-fsanitize=address`              | Check for leaks.                                                         |
| `-lreadline`                      | Necessary to use the readline library.                                   |
| `ps -e` or `ps -A`                | See all processes currently running on your computer.                    |
| `ps -a`                           | Check for any dead children.                                             |

#### VALGRIND
> Important valgrind flags that are necessary to know every single leak.

| Valgrind Flags                 | Description                                      |
| :----------------------------- | :----------------------------------------------- |
| `valgrind ./minishell`         | Check for leaks                                  |
| `-leak-check=full`             | Detailed checking for memory leaks.              |
| `--show-leak-kinds=all`        | Display all types of memory leaks.               |
| `--track-origins=yes`          | Tracks the origins of uninitialized values.      |
| `--verbose`                    | Increases the level of verbosity.                |
| `--gen-suppressions=all`       | Ignore specific known issues or false positives. |
| `--suppressions=readline.supp` | Specifies the path to a suppression file.        |
| `--log-file=memleaks.log`      | Sets the name of the file.                       |

> To ignore leaks related to the `readline` and `add_history` functions, create a file called `readline.supp` with the following content:
```
{
    leak readline
    Memcheck:Leak
    ...
    fun:readline
}
{
    leak add_history
    Memcheck:Leak
    ...
    fun:add_history
}
```

`valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all ./minishell`

## UTILITIES
#### Return Values ($?)
> The values that a function returns when it completes.

* All Linux commands return an error code between `0` and `255`.
* The value 0 represents the value true (command success).
* Values greater than 0 represent false (command failure).
* The error code of the last command used is contained in the variable `$?`.

| $?      | Description                                                                             |
| :------ | :-------------------------------------------------------------------------------------- |
| `1`     | Standard for general errors, such as a division by zero.                                |
| `2`     | Improper use of built-in commands, per Bash documentation.                              |
| `126`   | The command called cannot be executed, rights problem or the command is not executable. |
| `127`   | Command not found, possible problem with $PATH or typing error.                         |
| `128`   | Invalid command argument.                                                               |
| `128+n` | 128 + signal number.                                                                    |
| `130`   | Finished with `Ctrl` + `C` (130 = 128 + 2).                                             |
| `255`   | Exit code out of bounds. Example: `exit -1`.                                            |

#### Command Reminders
> More nice-to-know commands that may be useful in the future.

| Command       | Description                                                                                 |
| :------------ | :------------------------------------------------------------------------------------------ |
| `yes`		| Writes in an infinite loop `yes teste`.                                                     |
| `ln`		| Bind a file or directory.                                                                   |
| `chmod`	| Change file permissions `chmod 777` (all permissions) `chmod 000` (no permissions).         |
| `cd`		| Change directory. `cd -` (last visited directory) `cd` (user directory) `cd /` (root).      |
| `clear`	| Clear the screen.                                                                           |	
| `diff`	| Compare files line by line.                                                                 |
| `cmp`		| Write the first line of difference between 2 files.                                         |
| `pc`		| Copying files.                                                                              |
| `rm`		| Delete file.                                                                                |
| `rm -rf`	| Delete the directory recursively.                                                           |
| `ls -l`	| Show the contents of the directory.                                                         |
| `exit`	| Exit current process.                                                                       |
| `grep`	| Search for strings in files `grep "printf" file`.                                           |
| `mkdir`	| Create a directory.                                                                         |
| `rmdir`	| Delete a directory.                                                                         |
| `more`	| Displays a file page by page as in a man.                                                   |
| `mv`		| Move or rename.                                                                             |
| `$PATH`	| Path to executables.                                                                        |
| `cat`		| Send the file to stdout.                                                                    |

#### CHMOD
> Change the access permissions and the special mode flags of file system objects.

| Rights        | Number |
| :------------ | :----- |
| `r` (read)	| `4`    |
| `w` (write)	| `2`    |
| `x` (execute)	| `1`    |
	
| Rights  | Calculation | Total |
| :------ | :---------- | :---- |
| `---`   | `0+0+0`     | `0`   |
| `r--`   | `4+0+0`     | `4`   |
| `-w-`   | `0+2+0`     | `2`   |
| `--x`   | `0+0+1`     | `1`   |
| `rw-`   | `4+2+0`     | `6`   |
| `-wx`   | `0+2+1`     | `3`   |
| `x-ray` | `4+0+1`     | `5`   |
| `rwx`   | `4+2+1`     | `7`   |

#### DATA TYPES
> All data types, their size in bytes and the INT MIN and INT MAX range.

| Data Types | Qualifiers                        | Size (in byte) | Range                          |
| :--------- | :-------------------------------- | :------------- | :----------------------------- |
| `char`     | `char` or `signed char`		 | `1`            | `-128` to `127`                |
| `char`     | `unsigned char`			 | `1`            | `0` to `255`                   |
| `int`	     | `int` or `signed int`		 | `4`            | `-2147483648` to `2147483647`  |
| `int`	     | `unsigned int`			 | `4`            | `0` to `4294967295`            |
| `int`	     | `short int` or `short signed int` | `2`            | `-32768` to `32767`            |
| `int`	     | `unsigned short int`		 | `2`            | `0` to `65535`                 |
| `int`	     | `long int` or `signed long int`	 | `4`            | `-2147483648` to `2147483647`  |
| `int`	     | `unsigned long int`		 | `4`            | `0` to `4294967295`            |
| `float`    | `float`				 | `4`            | `1.1754e-38` to `3.4028e+38`   |
| `float`    | `double`				 | `8`            | `2.2250e-308` to `1.7976e+308` |
| `float`    | `long double`			 | `10`           | `3.4E-4932` to `3.4E+4932`     |


#### BLANK
> Exploring fundamental commands in Minishell, unravelling the core of shell interactions.

| Status  | Command |
| :------ | :------ |
| 🟢 | `<empty>`  |
| 🟢 | `<spaces>` |
| 🟢 | `../../`   |
| 🟢 | `$`        |

#### SIGNALS
> Understanding system signals, showcasing the shell's adaptability in various scenarios.

| Status  | Command |
| :------ | :------ |
| 🟢 | `Ctrl` + `C`                                |
| 🟢 | `Ctrl` + `D`                                |
| 🟢 | `Ctrl` + `\`                                |
| 🟢 | `write something then press` + `Ctrl` + `C` |
| 🟢 | `write something then press` + `Ctrl` + `D` |
| 🟢 | `write something then press` + `Ctrl` + `\` |
| 🟢 | `cat` + `Ctrl` + `C`                        |
| 🟢 | `cat` + `Ctrl` + `D`                        |
| 🟢 | `cat` + `Ctrl` + `\`                        |
| 🟢 | `sleep 5` + `Ctrl` + `C`                    |
| 🟢 | `sleep 5` + `Ctrl` + `D`                    |
| 🟢 | `sleep 5` + `Ctrl` + `\`                    |
	
#### PATH
> Managing executable file access by manipulating the system path in Minishell.

| Status  | Command |
| :------ | :------ |
| 🟢 | `/bin/echo`        |
| 🟢 | `/bin/grep`        |
| 🟢 | `/bin/ls`          |
| 🟢 | `/bin/ls -la`      |
| 🟢 | `/bin/cat`         |
| 🟢 | `/bin/pwd`         |
| 🟢 | `/bin/cd`          |
| 🟢 | `/bin/export`      |
| 🟢 | `/bin/env`         |
| 🟢 | `/bin/exit`        |

#### PWD
> Locating the present directory through the pwd command in Minishell.

| Status  | Command |
| :------ | :------ |
| 🟢 | `pwd`         |
| 🟢 | `pwd a`       |
| 🟢 | `pwd a b c d` |

#### EXPORT, ENV AND UNSET
> Harnessing environment variables via export, env, and unset commands in Minishell.

| Status  | Command |
| :------ | :------ |
| 🟢 | `ENV`                        	|
| 🟢 | `eNv`                        	|
| 🟢 | `env`                        	|
| 🟢 | ` env`                       	|
| 🟢 | `env `                       	|
| 🟢 | `  env  `                    	|
| 🟢 | `UNSET`                      	|
| 🟢 | `uNsEt`                      	|
| 🟢 | `unset`                      	|
| 🟢 | ` unset`                     	|
| 🟢 | `unset `                     	|
| 🟢 | `  unset  `                  	|
| 🟢 | `unset [variable]`           	|
| 🟢 | `unset [variable] [variable]`	|
| 🟢 | `unset [all variables]`      	|
| 🟢 | `EXPORT`                     	|
| 🟢 | `eXpOrT`                     	|
| 🟢 | `export`                     	|
| 🟢 | ` export`                    	|
| 🟢 | `export `                    	|
| 🟢 | `  export  `                 	|
| 🟢 | `export a=42`                	|
| 🟢 | `export a=24`		    	|
| 🟢 | `export b=42`                	|
| 🟢 | `export a = 42`              	|
| 🟢 | `export a=" 42 "`            	|
| 🟢 | `export a=' 42 '`            	|
| 🟢 | `export a = 42`              	|
| 🟢 | `export a` 		    	|
| 🟢 | `export a=''`           	    	|                                         
| 🟢 | `export a='"'`               	|                                   
| 🟢 | `export a='\'`               	|                                
| 🟢 | `export a='$'`               	|                                 
| 🟢 | `export a='\t'`              	|                                    
| 🟢 | `export a='''` 		 	| 
| 🟢 | `export =` 		  	|
| 🟢 | `export ==`		  	|
| 🟢 | `export a=` 		  	|
| 🟢 | `export a=42=` 		    	|
| 🟢 | `export =a=42` 		    	|
| 🟢 | `export a==42` 		    	|
| 🟢 | `export "a=42"` 		    	|
| 🟢 | `export a="42"` 		    	|
| 🟢 | `export _=42` 		    	|
| 🟢 | `export 42=42`		    	|
| 🟢 | `export a b = 42`	    	|
| 🟢 | `export a= b= 42`	    	|
| 🟢 | `export a=42 % b=42 @ c=42`  	|
| 🟢 | `export a=42 b=42 c=42`	    	|
| 🟢 | `export A=a B=b C=c D=d E=e` 	|
| 🟢 | `export F=f G=g H=h I=i J=j` 	|
| 🟢 | `export K=k L=l M=m N=n O=o` 	|
| 🟢 | `export P=p Q=q R=r S=s T=t` 	|
| 🟢 | `export U=u V=v W=w X=x Y=y Z=z` |
| 🟢 | `export _=a; echo $_a` 		|

#### EXIT
> Concluding Minishell's operations gracefully using the exit command.

| Status  | Command |
| :------ | :------ |
| 🟢 | `EXIT`                      |
| 🟢 | `eXiT`                      |
| 🟢 | `exit`                      |
| 🟢 | `exit `                     |
| 🟢 | ` exit`                     |
| 🟢 | `  exit  `                  |
| 🟢 | `exit test`                 |
| 🟢 | `exit "test"`               |
| 🟢 | `"exit test"`               |
| 🟢 | `"exit"`                    |
| 🟢 | `exit1`                     |
| 🟢 | `exita`                     |
| 🟢 | `exit exit`                 |
| 🟢 | `exit a`                    |
| 🟢 | `exit abc`                  |
| 🟢 | `exit a b c`                |
| 🟢 | `exit a b c d`              |
| 🟢 | `exit #`                    |
| 🟢 | `exit *`                    |
| 🟢 | `exit 0`                    |
| 🟢 | `exit 1`                    |
| 🟢 | `exit 123`                  |
| 🟢 | `exit 1234`                 |
| 🟢 | `exit 1 2 3 4`              |
| 🟢 | `exit +`                    |
| 🟢 | `exit -`                    |
| 🟢 | `exit +10`                  |
| 🟢 | `exit -10`                  |
| 🟢 | `exit +2000`                |
| 🟢 | `exit -2000`                |
| 🟢 | `exit +-2000`               |
| 🟢 | `exit -+2000`               |
| 🟢 | `exit ++2000`               |
| 🟢 | `exit --2000`               |
| 🟢 | `exit -2147483649`          |
| 🟢 | `exit 2147483648`           |
| 🟢 | `exit 00000000000000000000` |
| 🟢 | `exit 11111111111111111111` |
| 🟢 | `exit'42'`                  |
| 🟢 | `exit '\t42'`               |
| 🟢 | `exit '\t\f\r 42'`          |
| 🟢 | `exit '42 '`                |
| 🟢 | `exit '42\t'`               |
| 🟢 | `exit '42\r'`               |
| 🟢 | `exit '42\t\f\r '`          |
| 🟢 | `exit '42     a'`           |
| 🟢 | `exit '42\t\t\ta'`          | 

#### CD
> Traversing directories seamlessly using the cd command in Minishell.

| Status  | Command |
| :------ | :------ |
| 🟢 | `CD`                    |
| 🟢 | `cd`                    |
| 🟢 | `cd `                   |
| 🟢 | ` cd`                   |
| 🟢 | `  cd  `                |
| 🟢 | `cd .`                  |
| 🟢 | `cd ~`                  |
| 🟢 | `cd no_file`            |
| 🟢 | `cd1`                   |
| 🟢 | `cd 0`                  |
| 🟢 | `cd 1`                  |
| 🟢 | `cd 123`                |
| 🟢 | `cd 1234`               |
| 🟢 | `cd 1 2 3 4`            |
| 🟢 | `cd cd`                 |
| 🟢 | `cd a`                  |
| 🟢 | `cd abc`                |
| 🟢 | `cd a b c`              |
| 🟢 | `cd a b c d`            |
| 🟢 | `cd ../../`             |
| 🟢 | `cd ../../../../../../` |
| 🟢 | `cd ../../...`          |
| 🟢 | `cd .../../..`          |
| 🟢 | `cd .../../...`         |
| 🟢 | `cd \`                  |
| 🟢 | `cd /`                  |
| 🟢 | `cd //`                 |
| 🟢 | `cd ///`                |
| 🟢 | `cd -`                  |
| 🟢 | `cd $[VAR]`             |

#### ECHO
> Rendering text and variables in the terminal with the versatile echo command in Minishell.

| Status  | Command |
| :------ | :------ |
| 🟢 | `ECHO`                                                               |
| 🟢 | `echO`                                                               |
| 🟢 | `ECHo`                                                               |
| 🟢 | `echo`                                                               |
| 🟢 | `echo echo`                                                          |
| 🟢 | `echo `                                                              |
| 🟢 | ` echo`                                                              |
| 🟢 | `  echo  `                                                           |
| 🟢 | `echo .`                                                             |
| 🟢 | `echo ~`                                                             |
| 🟢 | `echo echo ~`                                                        |
| 🟢 | `"echo test"`                                                        |
| 🟢 | `echo "~"`                                                           |
| 🟢 | `echo '~'`                                                           |
| 🟢 | `echo ~123`                                                          |
| 🟢 | `echo 123~`                                                          |
| 🟢 | `echo ~/123`                                                         |
| 🟢 | `echo ~/123/456`                                                     |
| 🟢 | `echo #`                                                             |
| 🟢 | `echofile`                                                           |
| 🟢 | `echo file`                                                          |
| 🟢 | `echo no_file`                                                       |
| 🟢 | `echo file test`                                                     |
| 🟢 | `echo file   test`                                                   |
| 🟢 | `echo file     test file   test`                                     |
| 🟢 | `echo a"b"c`                                                         |
| 🟢 | `echo "a'b'c`                                                        |
| 🟢 | `echo "test"`                                                        |
| 🟢 | `echo test`                                                          |
| 🟢 | `echo 'test'`                                                        |
| 🟢 | `echo -n`                                                            |
| 🟢 | `echo -n -n -n -n`                                                   |
| 🟢 | `echo -nnnnnnnnnnnnnnnnnnnnnnnn`                                     |
| 🟢 | `echo -n test -n`                                                    |
| 🟢 | `"echo" "-n"`                                                        |
| 🟢 | `echo -n test`                                                       |
| 🟢 | `echo -nn test`                                                      |
| 🟢 | `echo -n -n -n test`                                                 |
| 🟢 | `echo "-n" test`                                                     |
| 🟢 | `echo -n"-n" test`                                                   |
| 🟢 | `echo "-nnnn" test`                                                  |
| 🟢 | `echo "-n -n -n"-n test`                                             |
| 🟢 | `echo "-n '-n'" test `                                               |
| 🟢 | `echo -n file test`                                                  |
| 🟢 | `echo -n -n -n file test`                                            |
| 🟢 | `echo $USER`                                                         |
| 🟢 | `echo "$USER"`                                                       |
| 🟢 | `echo "'$USER'"`                                                     |
| 🟢 | `echo " '$USER' "`                                                   |
| 🟢 | `echo text"$USER"`                                                   |
| 🟢 | `echo text"'$USER'" ' $USER '`                                       |
| 🟢 | `echo "text"   "$USER"    "$USER"`                                   |
| 🟢 | `echo '              $USER          '`                               |
| 🟢 | `echo               text "$USER"            "$USER"text`             |
| 🟢 | `echo ''''''''''$USER''''''''''`                                     |
| 🟢 | `echo """"""""$USER""""""""`                                         |
| 🟢 | `echo $USER'$USER'text oui oui     oui  oui $USER oui      $USER ''` |
| 🟢 | `echo $USER '' $USER $USER '' $USER '' $USER -n $USER`               |
| 🟢 | `echo ' \' ' \'`                                                     |
| 🟢 | `echo '\" ' " \"\""`                                                 |
| 🟢 | `echo \\\" \\\" \\\" \\\"\\\"\\\" \\\'\\\'\\\'`                      |
| 🟢 | `echo "$USER""$USER""$USER"`                                         |
| 🟢 | `echo text"$USER"test`                                               |
| 🟢 | `echo '$USER' "$USER" "text \' text"`                                |
| 🟢 | `echo '$USER'`                                                       |
| 🟢 | `echo $USER " "`                                                     |
| 🟢 | `echo "$USER""Users/$USER/file""'$USER'"'$USER'`                     |
| 🟢 | `echo "$USER$USER$USER"`                                             |
| 🟢 | `echo '$USER'"$USER"'$USER'`                                         |
| 🟢 | `echo '"$USER"''$USER'"""$USER"`                                     |
| 🟢 | `echo " $USER  "'$PWD'`                                              |
| 🟢 | `echo " $USER  \$ "'$PWD'`                                           |
| 🟢 | `echo $USER=4`                                                       |
| 🟢 | `echo $USER=thallard`                                                |
| 🟢 | `echo $USER`                                                         |
| 🟢 | `echo $?`                                                            |
| 🟢 | `echo $USER213`                                                      |
| 🟢 | `echo $USER$12USER$USER=4$USER12`                                    |
| 🟢 | `echo $USER $123456789USER $USER123456789`                           |
| 🟢 | `echo $USER $9999USER $8888USER $7777USER`                           |
| 🟢 | `echo $USER $USER9999 $USER8888 $USER7777`                           |
| 🟢 | `echo $USER $USER9999 $USER8888 $USER7777 "$USER"`                   |
| 🟢 | `echo "$USER=12$USER"`                                               |
| 🟢 | `echo "$9USER" "'$USER=12$SOMETHING'"`                               |
| 🟢 | `echo $PWD/file`                                                     |
| 🟢 | `echo "$PWD/file`                                                    |
| 🟢 | `echo "text" "text$USER" ... "$USER`                                 |
| 🟢 | `echo $PW`                                                           |
| 🟢 | `echo "'"'ola'"'"`                                                   |
| 🟢 | `echo "'"' ola '"'"`                                                 |



* [42 Norms](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) - Information about 42 code norms. `PDF`
* [Norminette](https://github.com/42School/norminette) - Tool to respect the code norm, made by 42. `GitHub`
* [42 Header](https://github.com/42Paris/42header) - 42 header for Vim. `GitHub`
