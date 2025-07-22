# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/21 17:00:00 by devjorginho       #+#    #+#              #
#    Updated: 2025/07/22 18:16:05 by jde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -Iinc -g -O3

MLX_DIR	= ./minilibx-linux
MLX_LIB	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS	= $(shell find ./src -name "*.c" && find ./libft -name "*.c" && find ./get_next_line -name "*.c")
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	cd libft && make clean
	
fclean: clean
	rm -f $(NAME)
	cd libft && make fclean
	
re: fclean all
	cd libft && make re
	
run: all
	./$(NAME)

.PHONY: all clean fclean re run
