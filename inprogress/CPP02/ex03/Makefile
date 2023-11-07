# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:20:24 by lde-sous          #+#    #+#              #
#    Updated: 2023/11/07 13:14:56 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS VARIABLES
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98
RM = rm -rf

# NAME && FOLDERS
NAME = fixed03
SRC =	main.cpp \
		Fixed.cpp \

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
		@echo "Cleaning successeful!"

fclean:
		@echo "Uninstalling..."
		$(RM) $(OBJ) $(NAME) $(OBJ_D)
		@echo "Uninstall complete!"

re: fclean all

.SILENT:

.PHONY: all clean fclean re