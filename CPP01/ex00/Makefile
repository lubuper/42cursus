# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 16:37:31 by lde-sous          #+#    #+#              #
#    Updated: 2023/10/20 16:51:42 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS AND VARIABLES
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# PROJECT NAME && FOLDERS

NAME = zombie0
SRC =	main.cpp \
		newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp

OBJ_D = bin
OBJ = $(addprefix $(OBJ_D)/, $(SRC:.cpp=.o))

# RULES
all: $(NAME)

$(NAME): $(OBJ)
		@echo "Installing..."
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "Instalation Complete!"

$(OBJ_D)/%.o: %.cpp
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "Cleaning..."
		$(RM) $(OBJ)
		@echo "Cleaning successful!"

fclean:
		@echo "Uninstalling..."
		$(RM) $(OBJ)
		$(RM) $(NAME) $(OBJ_D)
		@echo "Uninstall successful!"

re: fclean all

.SILENT:

.PHONY: all clean fclean re