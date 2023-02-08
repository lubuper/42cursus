# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 14:45:02 by lde-sous          #+#    #+#              #
#    Updated: 2023/02/08 20:50:58 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

CL = client
SV = server

B_CL = client_bonus
B_SV = server_bonus

OBJC = $(FC:.c=.o)
OBJS = $(FS:.c=.o)

BONUS_OBJC = $(BONUS_FC:.c=.o)
BONUS_OBJS = $(BONUS_FS:.c=.o)

FC = client.c
FS = server.c

BONUS_FC = client_bonus.c 
BONUS_FS = server_bonus.c

#RULES
all: $(CL) $(SV)
	@echo "Libft functions compiled"

$(LIBFT): make -C ./libft

$(CL): $(OBJC)
	make -C ./libft
	@$(CC) $(CFLAGS) $(OBJC) $(LIBFT) -o client

$(SV): $(OBJS)
	make -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o server

bonus: $(B_SV) $(B_CL)
	@echo "Libft functions compiled"

$(B_CL): $(BONUS_OBJC)
	make -C ./libft
	@$(CC) $(CFLAGS) $(BONUS_OBJC) $(LIBFT) -o client_bonus

$(B_SV): $(BONUS_OBJS)
	make -C ./libft
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o server_bonus

clean:
	make clean -C ./libft
	@rm -rf $(OBJC)
	@rm -rf $(OBJS)
	@rm -rf $(BONUS_OBJC)
	@rm -rf $(BONUS_OBJS)

fclean: clean
	make fclean -C ./libft
	@rm -rf $(CL) $(SV) $(B_CL) $(B_SV)

re: fclean all

.SILENT:

.PHONY: all clean fclean re bonus
