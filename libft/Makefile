# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:59:19 by lde-sous          #+#    #+#              #
#    Updated: 2022/11/07 15:46:33 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS  = -Wall -Wextra -Werror
RM = rm -f

FT_FUNCTIONS = 	ft_atoi
		ft_bzero
		ft_calloc
		ft_isalnum
		ft_isalpha
		ft_isascii
		ft_isdigit
		ft_isprint
		ft_memchr
		ft_memcmp
		ft_memcpy
		ft_memmove
		ft_memset
		ft_strchr
		ft_strdup
		ft_strlcat
		ft_strlcpy
		ft_strlen
		ft_strncmp
		ft_strnstr
		ft_strrchr
		ft_tolower
		ft_toupper

OBJ = $(FT_FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			@ar crs $(NAME) $(OBJ) //Create Replace Sort

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
clean:
	@$(RM) $(OBJ)
fclean: clean
	@rm - f $(NAME)
re: all fclean //recompile all and clean
.PHONY: all clean fclean re
