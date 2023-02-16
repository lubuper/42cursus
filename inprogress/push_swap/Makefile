# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 17:14:55 by lde-sous          #+#    #+#              #
#    Updated: 2023/02/16 15:23:03 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wextra -Wall -Werror
SRC = lst_ops.c \
	push_swap.c \
	push_ops.c \
#	sb.c \
      ss.c \
      ra.c \
      rb.c \
      rr.c \
      rra.c \
      rrb.c \
      rrr.c \

OBJ = $(SRC:%.c=%.o)
RM = rm -rf

all: $(NAME)
$(LIBFT):
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
