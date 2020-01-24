# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 22:54:31 by ahakanen          #+#    #+#              #
#    Updated: 2019/12/27 15:56:18 by cphillip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = ./libft/libft.a
HEADER_PATH = ./header/
SRC_PATH = ./src/
SRC = main.c check_piece.c convert_piece.c create_square.c error.c place.c \
		print_map.c solver.c starting_size.c store_tetris.c undo.c \
		val_string.c val_tetri.c validate.c
OBJ = $(SRC_PATH $SRC:.c:.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB) -I $(HEADER_PATH)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
