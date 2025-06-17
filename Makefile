# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 22:11:25 by devjorginho       #+#    #+#              #
#    Updated: 2025/06/17 23:09:49 by devjorginho      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinc

MLX_DIR		= ./minilibx-linux
MLX_LIB		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS		= src/main.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)
	$(MAKE) clean

.PHONY: all clean fclean re run
