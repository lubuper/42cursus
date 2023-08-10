# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 15:49:19 by lde-sous          #+#    #+#              #
#    Updated: 2023/08/09 19:03:22 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS AND VARIABLES
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
RM = rm -rf

# LIBFT
LIBFT = ./libft/libft.a
MINILIBX = ./mlx_linux/libmlx_Linux.a

# PROJECT NAME && FOLDERS
NAME = cub3d
SRC =	src/main.c \
	src/map_val1.c \
	src/map_val2.c \
	src/map_val3.c \
	src/map_val4.c \

OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# RULES
all: $(NAME)

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
	@echo "Uninstall successeful!"

re: fclean all

.SILENT:

.PHONY: all clean fclean re
