# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:13:56 by lde-sous          #+#    #+#              #
#    Updated: 2023/11/02 18:42:36 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS && VARIABLES
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

# PROJECT NAME && FOLDERS
NAME = harl
SRC =	main.cpp \
		Harl.cpp

OBJ_D = bin
OBJ = $(addprefix $(OBJ_D)/, $(SRC:.cpp=.o))

# RULES
all: $(NAME)

$(NAME): $(OBJ)
		@echo "Installing..."
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "Instalation complete!"
		@echo "Type ./harl"

$(OBJ_D)/%.o: %.cpp
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
		@echo "Cleaning..."
		$(RM) $(OBJ)
		@echo "Cleaning successful!"

fclean: 
		@echo "Uninstalling"
		$(RM) $(OBJ) $(NAME) $(OBJ_D)
		@echo "Uninstall successful"

re: fclean all

.SILENT:

.PHONY: all clean fclean re
