# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 13:35:09 by lde-sous          #+#    #+#              #
#    Updated: 2023/08/02 18:24:47 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc -g
CSANI = cc -fsanitize=leak
CFLAGS = -Wall -Wextra -Werror -pthread
SRC =	src_bonus/philo_b.c \
		src_bonus/p_utils_b.c \
		src_bonus/eat_b.c \
		src_bonus/time_fun.c \
		src_bonus/death_b.c \

OBJSDIR = obj_bonus
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
	@echo "fsanitize ON!"
	
fclean: clean
	$(RM) $(NAME) $(OBJSDIR)
	
re: fclean all

.SILENT:

.PHONY: all clean fclean re
