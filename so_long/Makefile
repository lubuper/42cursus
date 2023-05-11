# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:06:52 by lde-sous          #+#    #+#              #
#    Updated: 2023/05/11 13:44:34 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wextra -Wall -Werror -g
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
SRC = std/main.c \
      std/map_val1.c \
      std/map_val2.c \
      std/events.c \
      std/put_imgs.c \
      std/put_imgs_two.c \
      std/move_ops.c \
      std/check_utils.c

SRC_BONUS = bonus/main_bonus.c \
	    bonus/map_val1_bonus.c \
	    bonus/map_val2_bonus.c \
	    bonus/events_bonus.c \
	    bonus/put_imgs_bonus.c \
	    bonus/put_imgs_two_bonus.c \
	    bonus/move_ops_bonus.c \
	    bonus/check_utils_bonus.c \
	    bonus/move_mobs.c \
	    bonus/moby.c

OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)
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
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "Object Files READY"
$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BONUS)
	@echo "BONUS Object Files READY"
bonus:  $(NAME_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BONUS)
clean:
	@echo "Cleaning..."
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)
	@echo "Done!"
fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
re: fclean all

.SILENT:

.PHONY: all clean fclean re
