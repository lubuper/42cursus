# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 15:41:06 by lde-sous          #+#    #+#              #
#    Updated: 2022/11/08 15:52:29 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror -I.

SRC = ${filter-out ${wildcard *_bonus.c}, ${wildcard *.c}}

OBJ = ${SRC:.c=.o}

BONUS = ${wildcard *_bonus.c}

BONUS_OBJ = ${BONUS:.c=.o}

NAME = libft.a

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}
	ranlib ${NAME}

clean:
	rm -rf ${OBJ} ${BONUS_OBJ}

fclean: clean
	rm -rf ${NAME}

bonus: ${OBJ} ${BONUS_OBJ}
	ar rcs ${NAME} ${OBJ} ${BONUS_OBJ}
	ranlib ${NAME}
re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(OBJ) $(BONUS_OBJ)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_OBJ)
