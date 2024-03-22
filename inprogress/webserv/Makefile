# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 15:37:50 by lde-sous          #+#    #+#              #
#    Updated: 2024/03/13 16:20:10 by andvieir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#----------COMANDS----------#

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

#----------DIRS----------#

NAME = webserv

SRC =	main.cpp \
		srcs/server/Server.cpp \
		srcs/server/ServerCluster.cpp \
		srcs/config/Config.cpp \
		srcs/requests/Request.cpp \
		srcs/Utils.cpp \
		srcs/responses/Response.cpp \

OBJ_D = bin
LOGS_D = logs

OBJ = $(addprefix $(OBJ_D)/, $(SRC:.cpp=.o))

#----------COLORS----------#

GREEN	=	\033[0;32m
YELLOW	=	$(shell tput setaf 3)
CYAN	=	\033[1;36m
RED		=	\033[0;31m
RESET	=	$(shell tput sgr0)

#----------RULES----------#

all: $(NAME)


$(NAME): $(OBJ)
		@echo "Installing..."
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
		@echo "done!"

$(OBJ_D)/%.o: %.cpp
		mkdir -p $(@D)
		mkdir -p $(LOGS_D)
		$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
		@echo "Cleaning logs..."
		$(RM) $(LOGS_D)
		@echo "done!"

fclean:
		@echo "Uninstalling..."
		$(RM) $(OBJ) $(NAME) $(OBJ_D)
		@echo "done!"

re: fclean all

run:
	if [ "$$(id -u)" -ne 0 ]; then \
		echo "$(RED)WARNING: This program requires sudo privileges to run if you are setting ports under 1024.$(RESET)"; \
	fi; \
	read -p "Enter the path to the config file: " CONFIG_FILE_PATH; \
	./webserv $$CONFIG_FILE_PATH; \



.PHONY: all clean fclean re
