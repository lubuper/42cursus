# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:59:19 by lde-sous          #+#    #+#              #
#    Updated: 2022/11/10 16:15:05 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS  = -Wall -Wextra -Werror

RM = rm -f

OBJ = $(FT_FUNCTIONS:.c=.o)

FT_FUNCTIONS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	       ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
	       ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
	       ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	       ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	       ft_tolower.c ft_toupper.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
