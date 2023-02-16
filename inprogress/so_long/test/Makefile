# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 18:32:30 by lde-sous          #+#    #+#              #
#    Updated: 2023/02/15 19:16:08 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = window
CC = cc
CFLAGS = -Wextra -Wall -Werror
SRC = main.c
OBJ = $(SRC:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@$(RM) a.out
fclean: $(RM) $(NAME)
re: fclean all

.SILENT:

.PHONY: all clean fclean re
