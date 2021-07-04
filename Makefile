# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: murachid <murachid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 11:50:55 by murachid          #+#    #+#              #
#    Updated: 2021/07/04 16:45:25 by murachid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS =  -Wall -Wextra -Werror

SRC = *.c

all : $(NAME)

$(NAME): $(SRC)
	@$(CC)  $(SRC) -g -o $(NAME)

clean:
	@echo "no .o avalaible"

fclean:
	@rm -rf $(NAME)
re:	fclean all