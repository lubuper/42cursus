# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 11:20:13 by lde-sous          #+#    #+#              #
#    Updated: 2023/12/30 11:34:16 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS && VARIABLES
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# NAME && FOLDERS
NAME = PmergeMe

SRC =	main.cpp \
		PmergeMe.cpp

OBJ_D = bin

OBJ = $(addprefix $(OBJ_D)/, $(SRC:.cpp=.o))

# RULES
all: $(NAME)

$(NAME): $(OBJ)
		@echo "Installing..."
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
		@echo "Installation complete!"

$(OBJ_D)/%.o: %.cpp
		mkdir -p $(@D)
		$(CXX) $(CXXFLAGS) -c $< -o $@

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
