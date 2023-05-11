# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 13:35:09 by lde-sous          #+#    #+#              #
#    Updated: 2023/05/11 13:47:24 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = src/philo.c

OBJ = $(SRC:%.c=%.o)
RM = rm -rf

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Object Files READY"
clean:
	@echo "Cleaning..."
	$(RM) $(OBJ)
	@echo "Done!"
fclean: clean
	$(RM) $(NAME)
re: fclean all

.SILENT:

.PHONY: all clean fclean re
