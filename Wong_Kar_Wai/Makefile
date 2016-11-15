# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 15:53:05 by fhenry            #+#    #+#              #
#    Updated: 2016/01/31 23:18:31 by jnaddef          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC_PATH = Src/
OBJ_PATH = Objet/
INCLUDE_PATH = Include/

SRC_NAME = main.c \
		   init_table.c \
		   rand_num.c \
		   window.c \
		   init_dimensions.c \
		   itoa_table.c \
		   atoi_table.c \
		   execute_move.c \
		   execute_move_top.c \
		   execute_move_left.c \
		   execute_move_bottom.c \
		   execute_move_right.c \
		   add_rand.c \
		   merge_top_left.c \
		   merge_bot_right.c \
		   check_victory.c \
		   check_defeat.c \
		   draw_window.c


OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	    @$(CC) -c $(SRC) $(CFLAGS) -I $(INCLUDE_PATH)
		@mkdir Objet/
		@mv $(OBJ_NAME) $(OBJ_PATH)
		@$(CC) -o $(NAME) $(OBJ) $(INCLUDE_PATH)libft.a -lncurses

$(OBJ): $(INCLUDE_PATH)game.h

clean:
	    @rm -rf $(OBJ_PATH) && $(MAKE) -C ./libft/ $@

fclean: clean
	    @rm -f $(NAME) && $(MAKE) -C ./libft/ $@

re: fclean all

.PHONY: all, clean, fclean, re
