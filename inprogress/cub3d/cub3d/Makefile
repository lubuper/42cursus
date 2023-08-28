# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 15:49:19 by lde-sous          #+#    #+#              #
#    Updated: 2023/08/28 14:21:53 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS AND VARIABLES
CC = cc -g
CFLAGS = -Wall -Wextra -Werror #-fsanitize=leak
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
RM = rm -rf

# LIBFT
LIBFT = ./libft/libft.a
MINILIBX = ./mlx_linux/libmlx_Linux.a

# PROJECT NAME && FOLDERS
NAME = cub3D
SRC =	src/main.c \
	src/map_val1.c \
	src/file_val.c \
	src/utils.c \
	src/init.c \
	src/read_file.c \
	src/line_val.c \
	src/color_utils.c \
	src/ft_angle.c \
	src/draw.c

OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

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

$(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C ./libft

fclean: clean
	@echo "Uninstalling..."
	$(RM) $(NAME) $(OBJDIR)
	$(MAKE) fclean -C ./libft
	@echo "Uninstall successful!"

re: fclean all

.SILENT:

.PHONY: all clean fclean re
