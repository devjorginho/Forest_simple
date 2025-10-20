# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/21 17:00:00 by devjorginho       #+#    #+#              #
#    Updated: 2025/10/20 12:49:57 by devjorginho      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Iinc -g -O3
RM			= rm -f

MLX_TGZ		= minilibx-linux.tgz
MLX_DIR		= ./minilibx-linux
MLX_LIB		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS		= $(shell find ./src -name "*.c" && find ./libft -name "*.c" && find ./get_next_line -name "*.c")
OBJS		= $(SRCS:.c=.o)

all: $(MLX_DIR)/libmlx.a $(NAME)

$(MLX_DIR)/libmlx.a:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo ">> Extraindo MiniLibX..."; \
		tar -xzf $(MLX_TGZ); \
	fi
	@echo ">> Compilando MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	@echo ">> Compilando $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)
	@echo "✅ Compilação concluída com sucesso!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo ">> Limpando objetos..."
	$(RM) $(OBJS)
	@$(MAKE) -C libft clean || true
	@$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	@echo ">> Limpando binários..."
	$(RM) $(NAME)
	@$(MAKE) -C libft fclean || true

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
