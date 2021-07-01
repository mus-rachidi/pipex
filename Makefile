# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: murachid <murachid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 11:50:55 by murachid          #+#    #+#              #
#    Updated: 2021/06/29 16:32:47 by murachid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
#dlsakmldkmalskdlias
#mlkdml
CC = gcc

CFLAGS =  -Wall -Wextra -Werror -fsanitize=address

SRC = *.c

all : $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -g -o $(NAME)

clean:
	@echo "no .o avalaible"

fclean:
	@rm -rf $(NAME)
re:	fclean all