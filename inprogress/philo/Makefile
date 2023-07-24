# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 13:35:09 by lde-sous          #+#    #+#              #
#    Updated: 2023/07/24 20:07:42 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc -g
CSANI = cc -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror -pthread
SRC =	src/philo.c \
		src/p_utils.c \
		src/time_fun.c \
		src/death.c \

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

fsani: re $(OBJ)
	$(CSANI) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "fsanitize=address ON!"
	
fclean: clean
	$(RM) $(NAME) $(OBJSDIR)
	
re: fclean all

.SILENT:

.PHONY: all clean fclean re
