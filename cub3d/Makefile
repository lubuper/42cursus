# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 15:49:19 by lde-sous          #+#    #+#              #
#    Updated: 2023/10/03 18:38:13 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS AND VARIABLES
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address #-fsanitize=leak
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
RM = rm -rf

# LIBFT
LIBFT = ./libft/libft.a
MINILIBX = ./mlx_linux/libmlx_Linux.a

# PROJECT NAME && FOLDERS
NAME = cub3D
NAME_B = cub3D_bonus
SRC =	src/main.c \
	src/map_val1.c \
	src/file_val.c \
	src/utils.c \
	src/init.c \
	src/read_file.c \
	src/line_val.c \
	src/color_utils.c \
	src/ft_angle.c \
	src/draw.c \
	src/frees.c \
	src/move.c \
	src/imgs.c \
	src/raycast.c \
	src/raycast2.c 
	
SRC_B = src_bonus/main_bonus.c \
	src_bonus/map_val1_bonus.c \
	src_bonus/file_val_bonus.c \
	src_bonus/utils_bonus.c \
	src_bonus/init_bonus.c \
	src_bonus/read_file_bonus.c \
	src_bonus/line_val_bonus.c \
	src_bonus/color_utils_bonus.c \
	src_bonus/ft_angle_bonus.c \
	src_bonus/draw_bonus.c \
	src_bonus/frees_bonus.c \
	src_bonus/move_bonus.c \
	src_bonus/move_bonus2.c \
	src_bonus/move_bonus3.c \
	src_bonus/imgs_bonus.c \
	src_bonus/raycast_bonus.c \
	src_bonus/raycast2_bonus.c \
	src_bonus/draw_map_bonus.c \
	src_bonus/draw_map_bonus2.c \
	src_bonus/animation.c \
	src_bonus/draw_border.c \
	src_bonus/rc_projectile.c \


OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

OBJDIR_B = obj_bonus
OBJ_B = $(addprefix $(OBJDIR_B)/, $(SRC_B:.c=.o))

# RULES
all: $(NAME)
	@echo "\033[1;33m                                             "
	@echo "\033[1;31m                      ██        \033[5;34m██████╗ ██████╗\033[0m"
	@echo "\033[1;31m                      ██        \033[5;34m╚════██╗██╔══██╗\033[0m"
	@echo "\033[1;31m   ╔█████╗  ██║   ██║ ██████╗    \033[5;34m█████╔╝██║  ██║\033[0m"
	@echo "\033[1;31m   ██╔═══╝  ██║   ██║ ██╔══██╗   \033[5;34m╚═══██╗██║  ██║\033[0m"
	@echo "\033[1;31m   ╚██████╗ ╚██████╔╝ ██████╔╝  \033[5;34m██████╔╝██████╔╝\033[0m"
	@echo "\033[1;37m    ╚═════╝  ╚═════╝  ╚═════╝   \033[5;34m╚═════╝ ╚═════╝\033[0m"
	@echo "\033[1;33m                                             \033[0m"
	@echo "\e[1;33mExecute './cub3D ' and the map config you wish to play!"

bonus: $(NAME_B)
	@echo "\033[1;33m                                             "
	@echo "\033[1;31m                    ██        \033[5;34m██████╗ ██████╗\033[0m   ██                                █████"
	@echo "\033[1;31m                    ██        \033[5;34m╚════██╗██╔══██╗\033[0m  ██                               ██═══╝"
	@echo "\033[1;31m   ╔████╗  ██║  ██║ ██████╗    \033[5;34m█████╔╝██║  ██║\033[0m  ██████╗  ╔████╗  ╔███╗   ██║  ██║ █████╗"
	@echo "\033[1;31m   ██╔══╝  ██║  ██║ ██╔══██╗   \033[5;34m╚═══██╗██║  ██║\033[0m  ██╔══██╗ █║   █╗ ██║ ██╗ ██║  ██║ ╚═══██╗"
	@echo "\033[1;31m   ╚█████╗ ╚█████╔╝ ██████╔╝  \033[5;34m██████╔╝██████╔╝\033[0m  ██████╔╝ ╚████╔╝ ██║ ██║ ╚█████╔╝ █████╔╝"
	@echo "\033[1;37m    ╚════╝  ╚════╝  ╚═════╝   \033[5;34m╚═════╝ ╚═════╝\033[0m   ╚═════╝   ╚═══╝  ╚═╝ ╚═╝  ╚════╝  ╚════╝"
	@echo "\033[1;33m                                             \033[0m"
	@echo "\e[1;33mExecute './cub3D ' and the map config you wish to play!"

$(LIBFT):
	@echo "Installing..."
	@echo "Compiling LIBFT..."
	@$(MAKE) -C ./libft
	@echo "Libft Done!"

$(MINILIBX):
	@echo "Compiling MiniLibX..."
	@$(MAKE) -C ./mlx_linux
	@echo "MiniLibX Done!"

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "Instalation Complete!"

$(NAME_B): $(OBJ_B) $(LIBFT) $(MINILIBX)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ_B) $(LIBFT) $(MLXFLAGS) -o $(NAME_B)
	@echo "Instalation Complete!"

$(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_B)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_B)
	$(MAKE) clean -C ./libft

fclean: clean
	@echo "Uninstalling..."
	$(RM) $(NAME) $(OBJDIR)
	$(RM) $(NAME_B) $(OBJDIR_B)
	$(MAKE) fclean -C ./libft
	@echo "Uninstall successful!"

re: fclean all

rb: fclean bonus

.SILENT:

.PHONY: all clean fclean re bonus rb
