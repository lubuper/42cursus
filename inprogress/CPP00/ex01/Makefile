# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 10:34:42 by lde-sous          #+#    #+#              #
#    Updated: 2023/10/23 15:43:23 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS AND VARIABLES
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

# PROJECT NAME && FOLDERS
NAME = myVeryFirstPhoBo
SRC =	PhoneBook.cpp \
	Contact.cpp \
	main.cpp
	
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

.PHONY: all clean fclean re
