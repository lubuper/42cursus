# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 17:14:55 by lde-sous          #+#    #+#              #
#    Updated: 2023/03/30 13:00:23 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wextra -Wall -Werror -g 
SRC = lst_ops.c \
	push_swap.c \
	push_ops.c \
	check_errors.c \
	swap_ops.c \
	rotate_ops.c \
	reverse_ops.c \
	libutils.c \
	sort.c \
	sort_rad.c \
	aux_arr.c

OBJ = $(SRC:%.c=%.o)
RM = rm -rf

all: $(NAME)
$(LIBFT):
	@echo "Compiling..."
	@$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o push_swap
	@echo "Object Files READY"

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
