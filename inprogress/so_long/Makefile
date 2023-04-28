# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:06:52 by lde-sous          #+#    #+#              #
#    Updated: 2023/04/28 21:42:24 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wextra -Wall -Werror -g
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
SRC = test.c \
      map_val1.c \
      map_val2.c \
      test2.c \
      put_imgs.c \
      move_ops.c \
      check_utils.c

OBJ = $(SRC:%.c=%.o)
RM = rm -rf

all: $(NAME)
$(LIBFT):
	@echo "Compiling LIBFT..."
	@$(MAKE) -C ./libft
	@echo "Done!"

$(MINILIBX):
	@echo "Compiling MiniLibX..."
	@$(MAKE) -C ./mlx-linux
	@echo "Done!"

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS)
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
