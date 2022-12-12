# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 17:34:36 by lde-sous          #+#    #+#              #
#    Updated: 2022/12/12 18:38:27 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wexra -Werror

RM = rm -rf

OBJ = $(FT_FUNC:.c=.o)

FT_FUNC = 
	ft_printf.c\
	ft_printf_utils.c


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

