## Introducing LibFT!
This was my first ever project from the 42 Common Core, and it was meant to be a lesson about how the standard functions in C programming work, as well as a first contact with Makefile.
Although being the first project it was made with some rigor, as future assignments at 42 demand the use of the functions made.
Every function with a ft_ prefix was made to have the same output and behaviour of their non-prefixed counterpart.

<a href="https://github.com/lubuper/libft/blob/master/subject/en_subject_libft.pdf">Click here</a> for the subject of this project.

## HOW TO USE
#### COMPILATION
#### 1º - Clone the repository
```bash
git clone git@github.com:lubuper/libft.git
```

#### 2º - Enter the project folder and run `make`
```bash
cd libft/libft
make
```

#### 3º - To use in your code, include the header
```c
#include "libft.h"
```

#### MAKEFILE RULES

`make` - Compile libft **mandatory** files.

`make bonus` - Compile libft **bonus** files.

`make all` - Compile **mandatory** + **bonus** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object file) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
The mandatory functions in libft include both functions from the standard C library and other functions that are useful for character, string, and memory manipulation. These **34 mandatory functions** are essential to achieving a **grade of 100**.

#### Check and manipulate characters:

- [x] `ft_isalpha`
- [x] `ft_isdigit`
- [x] `ft_isalnum`
- [x] `ft_isascii`
- [x] `ft_toupper`
- [x] `ft_tolower`

#### Manipulate strings:

- [x] `ft_strlen`
- [x] `ft_strlcpy`
- [x] `ft_strlcat`
- [x] `ft_strchr`
- [x] `ft_strrchr`
- [x] `ft_strncmp`
- [x] `ft_strnstr`
- [x] `ft_substr`
- [x] `ft_strjoin`
- [x] `ft_strtrim`
- [x] `ft_split`
- [x] `ft_strmapi`
- [x] `ft_striteri`

#### Manipulate memory:

- [x] `ft_calloc`
- [x] `ft_memset`
- [x] `ft_bzero`
- [x] `ft_memcpy`
- [x] `ft_memmove`
- [x] `ft_memchr`
- [x] `ft_memcmp`
- [x] `ft_strdup`

#### Manipulate numbers:

- [x] `ft_atoi`
- [x] `ft_itoa`

#### Write to a file descriptor:

- [x] `ft_putchar_fd`
- [x] `ft_putstr_fd`
- [x] `ft_putendl_fd`
- [x] `ft_putnbr_fd`

## BONUS
The bonus functions in libft are focused on list manipulation and are worth an additional 25 towards the final grade. To achieve a **grade of 125**, **all 9 bonus functions and 34 mandatory functions** must be completed accurately.

- [x] `ft_lstnew`
- [x] `ft_lstadd_front`
- [x] `ft_lstsize`
- [x] `ft_lstlast`
- [x] `ft_lstadd_back`
- [x] `ft_lstdelone`
- [x] `ft_lstclear`
- [x] `ft_lstiter`
- [x] `ft_lstmap`
