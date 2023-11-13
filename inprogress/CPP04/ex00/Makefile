# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:20:35 by lde-sous          #+#    #+#              #
#    Updated: 2023/11/13 19:56:01 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS && VARIABLES
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# NAME && FOLDERS
NAME = poly
SRC =	main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \

OBJ_D = bin
OBJ = $(addprefix $(OBJ_D)/, $(SRC:.cpp=.o))

# RULES
all: $(NAME)

$(NAME): $(OBJ)
		@echo "Installing..."
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "Installation complete!"

$(OBJ_D)/%.o: %.cpp
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "Cleaning..."
		$(RM) $(OBJ)
		@echo "Cleaning successful!"

fclean:
		@echo "Uninstalling..."
		$(RM) $(OBJ) $(NAME) $(OBJ_D)
		@echo "Uninstall successful!"

re: fclean all

.SILENT:

.PHONY: all clean fclean re
