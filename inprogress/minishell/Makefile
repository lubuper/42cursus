# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 15:15:58 by alexandre         #+#    #+#              #
#    Updated: 2023/05/16 21:59:18 by alexfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = ./libft/libft.a
CFLAGS = -Werror -Wextra -Wall -g
RLFLAG = -lreadline
CC = cc
SRC =	src/main.c \
		src/lexer.c \
		src/get_tokens.c \
		commands/echo.c \
		commands/pwd.c \
		commands/cd.c \

RM = rm -rf
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)
	echo "Everything Done!"

clean:
	$(RM) $(OBJ)
	$(MAKE)	clean -C ./libft

fclean: clean
	$(RM) $(NAME) $(OBJ)
	$(MAKE) fclean -C ./libft
	echo "Everything Deleted..."

re: fclean all
	
.SILENT:

.PHONY: all clean fclean re