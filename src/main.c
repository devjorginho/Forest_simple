/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:43:20 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/17 00:22:49 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct s_position
{
	float	x;
	float	y;
}	t_position;
typedef struct s_keyboard
{
} t_keyboard;
typedef struct s_sprite
{
	void	*img[4];
}	t_sprite;

typedef	struct	s_entity
{
	int	id;
	t_sprite	*sprite;
	t_keyboard	*keyboard;
	t_position	*position;
} t_entity;

typedef struct s_game
{
	t_entity 	entities[10];
	bool		keymap[0xFFFFF];
	void		*mlx;
	void		*game_window;
	unsigned int e_count;
	unsigned long long frame;
} t_game;

void	putnbr(int nb)
{
	char c;

	if (nb > 9)
		putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}
void	draw_system(t_entity *entity, t_game *game)
{
	if(entity->position && entity->sprite)
	{
		mlx_put_image_to_window(game->mlx, game->game_window, entity->sprite->img[4], (int)entity->position->x, (int)entity->position->y);
	}
}

void	movement_system(t_entity *entity, t_game *game)
{
	if(entity->position && entity->sprite && entity->keyboard)
	{
		if(game->keymap[100])
			entity->position->x += 2;
		else if (game->keymap[97])
			entity->position->x -= 2;
	}
}
int	keydown(int keycode, t_game *game)
{
	game->keymap[keycode] = true;
	(void) game;
	return (0);
}
int	keyup(int keycode, t_game *game)
{
	game->keymap[keycode] = false;

	(void) game;
	return (0);
}

int	game_loop(t_game *game)
{
	usleep(16000);
	game->frame++;
	for(unsigned int i = 0; i < game->e_count; i++)
	{
		//animation_system(&game->entities[i], game);
		movement_system(&game->entities[i], game);
		draw_system(&game->entities[i], game);
	}
	return(0);
}
int main(void)
{
	int		width;
	int		height;
	t_game	game;

	// iniate library
	game.mlx = mlx_init();
	//game window
	game.game_window = mlx_new_window(game.mlx, 800, 600, "SAMURAI RUN");
	//game init
	game.e_count = 0;
	game.frame = 0;
	t_entity *player;
	player = malloc(sizeof(t_entity));
	player->position = malloc(sizeof(t_position));
	player->keyboard = malloc(sizeof(t_keyboard));
	player->position->x = 10;
	player->position->y = 10;
	player->sprite = malloc(sizeof(t_sprite));
	player->sprite->img[0] = mlx_xpm_file_to_image(game.mlx, "assets/Player/Idle/Idle_00.xpm", &width, &height);
	player->sprite->img[1] = mlx_xpm_file_to_image(game.mlx, "assets/Player/Idle/Idle_01.xpm", &width, &height);
	player->sprite->img[2] = mlx_xpm_file_to_image(game.mlx, "assets/Player/Idle/Idle_02.xpm", &width, &height);
	player->sprite->img[3] = mlx_xpm_file_to_image(game.mlx, "assets/Player/Idle/Idle_03.xpm", &width, &height);
	//add entity
	game.entities[game.e_count] = *player;
	game.e_count++;


	//t_entity *player_2;
	//player_2 = malloc(sizeof(t_entity));
	//player_2->position = malloc(sizeof(t_position));
	//player_2->position->x = 0;
	//player_2->position->y = 0;
	//player_2->sprite = malloc(sizeof(t_sprite));
	//player_2->sprite->img = mlx_xpm_file_to_image(game.mlx, "assets/Samurai/Idle.xpm", &width, &height);
	////add entity
	//game.entities[game.e_count] = *player_2;
	//game.e_c (*)(iount++;
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.game_window, 2, 1L<<0, keydown, &game);
	mlx_hook(game.game_window, 3, 1L<<1, keyup, &game);
	//drawimage
	// game loop
	mlx_loop(game.mlx);
}