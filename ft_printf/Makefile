# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 17:34:36 by lde-sous          #+#    #+#              #
#    Updated: 2022/12/15 12:22:00 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

OBJ = $(FT_FUNC:.c=.o)

FT_FUNC = ft_printf.c \
	ft_printchar.c \
	ft_printnum.c \
	ft_chck.c \
	ft_printhexa.c \
	ft_printpointer.c \
	ft_printstring.c \
	ft_printundec.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@$(RM) a.out
	@$(RM) ft_printf.h.gch

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

