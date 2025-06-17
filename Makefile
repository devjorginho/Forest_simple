# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 08:45:00 by devjorginho       #+#    #+#              #
#    Updated: 2025/06/17 12:48:06 by devjorginho      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRC_DIR		= src
INC_DIR		= inc
MLX_DIR		= minilibx-linux

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR)

SRC			= \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/init_game_system.c \
			$(SRC_DIR)/init_player_system.c \
			$(SRC_DIR)/render_player_system.c \
			$(SRC_DIR)/game_loop_system.c \
			$(SRC_DIR)/keyboard_system.c 


OBJ			= $(SRC:.c=.o)

MLX_LIB		= $(MLX_DIR)/libmlx_Linux.a
LIBS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)
