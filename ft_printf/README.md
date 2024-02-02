## ft_printf
This project was all about recreating the well-known C library function, printf. It was the perfect and most suitable opportunity to learn about variadic arguments and structures.

<a href="https://github.com/lubuper/ft_printf/blob/master/subject/en_subject_ft_printf.pdf">Click here</a> for the subject of this project.

## HOW TO USE
#### COMPILING AND EXECUTION
#### 1º - Clone the repository
```git
git clone git@github.com:lubuper/ft_printf.git
```

#### 2º - Enter the project folder and run `make`
```bash
cd ft_printf/ft_printf
make
```

#### 3º - To use in your code, include the header
```c
#include "ft_printf.h"
```

#### MAKEFILE RULES

`make` or `make all` - Compile ft_printf files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
This ft_printf function supports several format specifiers, described below.

- [x] `%c` - Print a single character.
- [x] `%s` - Print a string.
- [x] `%p` - Print void * pointer argument in hexadecimal format.
- [x] `%d` - Print a decimal (base 10) number.
- [x] `%i` - Print an integer in base 10.
- [x] `%u` - Prints an unsigned decimal (base 10) number.
- [x] `%x` - Print a number in hexadecimal (base 16) lowercase format.
- [x] `%X` - Print a number in hexadecimal (base 16) uppercase format.
- [x] `%%` - Print a percent sign.

## BONUS

- [ ] Manage any combination of the following flags: `-O` and the field minimum width under all conversions.
- [ ] Manage all the following flags: `#` ` ` `+`.
