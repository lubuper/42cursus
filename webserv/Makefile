# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 15:37:50 by lde-sous          #+#    #+#              #
#    Updated: 2024/05/24 12:23:22 by lde-sous         ###   ########.fr        #
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
		srcs/server/Cluster.cpp \
		srcs/config/Configuration.cpp \
		srcs/requests/Request.cpp \
		srcs/Utils.cpp \
		srcs/HTML.cpp \
		srcs/responses/Response.cpp \
		srcs/server/Connection.cpp \

OBJ_D = bin
LOGS_D = logs

VALGRIND_LOG_DIR = logs/valgrind
VALGRIND_LOG_FILE = $(VALGRIND_LOG_DIR)/valgrind.log
DUMMY_FILE = .dummy_file

#----------OBJECTS----------#

OBJ = $(addprefix $(OBJ_D)/, $(SRC:.cpp=.o))

#----------COLORS----------#

BLACK	=	\033[0;90m
GREENER	=	\033[1;32m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
CYAN	=	\033[1;36m
RED		=	\033[1;31m
RESET	=	$(shell tput sgr0)

#----------DOCKER OPERATIONS----------#

# Define the Docker image name (adjust as needed)
DOCKER_IMAGE = lubuper/42_webserv_html:latest

# Define the path inside the container where files are located
CONTAINER_VAR_PATH = /usr/webserv/var

# Define the local target directory
LOCAL_VAR_PATH = .

# Verify if docker is installed
DOCKER_EXISTS := $(shell command -v docker > /dev/null 2>&1; echo $$?)

#----------RULES----------#

all: pull-and-copy-files $(NAME)


$(NAME): $(OBJ)
		@echo "Installing..."
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
		@echo "$(GREENER)Done!$(RESET)"

$(OBJ_D)/%.o: %.cpp
		mkdir -p $(@D)
		mkdir -p $(LOGS_D)
		$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to pull the Docker image and copy files to the local directory
pull-and-copy-files:
	@if [ "$(DOCKER_EXISTS)" -eq 0 ]; then \
		echo "$(YELLOW)Pulling Docker image $(DOCKER_IMAGE)...$(BLACK)"; \
		docker pull $(DOCKER_IMAGE); \
		echo "$(YELLOW)Creating temporary container to copy files...$(RESET)"; \
		docker create --name temp_webserv $(DOCKER_IMAGE); \
		echo "$(YELLOW)Copying files from container to local directory $(LOCAL_VAR_PATH)...$(RESET)"; \
		mkdir -p $(LOCAL_VAR_PATH); \
		docker cp temp_webserv:$(CONTAINER_VAR_PATH) $(LOCAL_VAR_PATH); \
		echo "$(YELLOW)Removing temporary container...$(RESET)"; \
		docker rm temp_webserv; \
		echo "$(GREEN)Files copied to $(LOCAL_VAR_PATH) successfully $(RESET)"; \
	else \
		echo "$(RED)Docker is not installed. Please install Docker.$(RESET)"; \
		exit 1; \
	fi

clean:
		@echo "$(YELLOW)Cleaning logs...$(RESET)"
		$(RM) $(LOGS_D)
		@echo "$(GREENER)Done!$(RESET)"

fclean:
	@echo "$(YELLOW)Uninstalling...$(RESET)"
	@IMAGE_ID=$$(docker images -q lubuper/42_webserv_html:latest); \
	if [ -n "$$IMAGE_ID" ]; then \
		echo "$(YELLOW)Image found, removing...$(BLACK)"; \
		docker image rm lubuper/42_webserv_html:latest; \
	else \
		echo "No image found, skipping..."; \
	fi
	@$(RM) $(OBJ) $(NAME) $(OBJ_D) var
	@echo "$(GREENER)Done!$(RESET)"

re: fclean all

.PHONY: all clean fclean re check_config_file pull-and-copy-files

.SILENT:
