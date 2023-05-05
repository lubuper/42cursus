# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:06:52 by lde-sous          #+#    #+#              #
#    Updated: 2023/05/05 23:34:16 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wextra -Wall -Werror -g
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
SRC = main.c \
      map_val1.c \
      map_val2.c \
      events.c \
      put_imgs.c \
      put_imgs_two.c \
      move_ops.c \
      check_utils.c

SRC_BONUS = main_bonus.c \
	    map_val1_bonus.c \
	    map_val2_bonus.c \
	    events_bonus.c \
	    put_imgs_bonus.c \
	    put_imgs_two_bonus.c \
	    move_ops_bonus.c \
	    check_utils_bonus.c \
	    move_mobs.c

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
	@$(RM) $(NAME) 
	@$(RM) $(NAME_BONUS)
	@echo "Done!"
fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
re: fclean all

.SILENT:

.PHONY: all clean fclean re
