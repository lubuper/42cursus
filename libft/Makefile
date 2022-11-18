# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:59:19 by lde-sous          #+#    #+#              #
#    Updated: 2022/11/18 20:33:46 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS  = -Wall -Wextra -Werror

RM = rm -rf

OBJ = $(FT_FUNCTIONS:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

FT_FUNCTIONS = ft_atoi.c \
	       ft_bzero.c \
	       ft_calloc.c \
	       ft_isalnum.c \
	       ft_isalpha.c \
	       ft_isascii.c \
	       ft_isdigit.c \
	       ft_isprint.c \
	       ft_itoa.c \
	       ft_memchr.c \
	       ft_memcmp.c \
	       ft_memcpy.c \
	       ft_memmove.c \
	       ft_memset.c \
	       ft_putchar_fd.c \
	       ft_putendl_fd.c \
	       ft_putnbr_fd.c \
	       ft_putstr_fd.c \
	       ft_split.c \
	       ft_strchr.c \
	       ft_strdup.c \
	       ft_striteri.c \
	       ft_strjoin.c \
	       ft_strlcat.c \
	       ft_strlcpy.c \
	       ft_strlen.c \
	       ft_strmapi.c \
	       ft_strncmp.c \
	       ft_strnstr.c \
	       ft_strrchr.c \
	       ft_strtrim.c \
	       ft_substr.c \
	       ft_tolower.c \
	       ft_toupper.c

BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(BONUS_OBJ)
	@$(RM) a.out
	@$(RM) libft.h.gch

fclean: clean
	@$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
