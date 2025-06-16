# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 18:03:47 by jde-carv          #+#    #+#              #
#    Updated: 2025/06/16 19:26:21 by jde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
INC_DIR = include
MLX_DIR = minilibx-linux

SRCS = $(SRC_DIR)/main.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
