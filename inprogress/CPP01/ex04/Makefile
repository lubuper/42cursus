# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 16:08:30 by lde-sous          #+#    #+#              #
#    Updated: 2023/10/27 16:49:53 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS AND VARIABLES
CC = c++
CFLAGS = -Wall -Wextra -Werror -stdc++=98
RM = rm -rf

# PROJECT NAME && FOLDERS
NAME = sed
SRC = main.cpp

OBJ_D = bin
OBJ = $(addprefix $(OBJ_D)/, $(SRC:.cpp=.o))

# RULES
all: $(NAME)

$(NAME): $(OBJ)
		@echo "Installing..."
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "Instalation complete!"

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
		@echo "Uninstall successful"

re: fclean all

.SILENT:

.PHONY: all clean fclean re