# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 13:35:09 by lde-sous          #+#    #+#              #
#    Updated: 2023/07/11 11:27:28 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g #-fsanitize=address
SRC =	src/philo.c \
		src/p_utils.c \
		src/time_fun.c \

OBJSDIR = obj
OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Object Files READY"
	
$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@echo "Cleaning..."
	$(RM) $(OBJ)
	@echo "Done!"
	
fclean: clean
	$(RM) $(NAME) $(OBJSDIR)
	
re: fclean all

.SILENT:

.PHONY: all clean fclean re
