/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:16:08 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/17 23:06:31 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../minilibx-linux/mlx.h"

typedef struct s_position
{
	float	x;
	float	y;
} t_position;

typedef struct s_keyboard
{
} t_keyboard;

typedef struct	s_image
{
	void	*img;
	int		width;
	int		height;
} t_image;

typedef struct	s_gravity
{
} t_gravity;

typedef	struct s_entity
{
	t_position	*position;
	t_image		*image;
	t_gravity	*gravity;
	t_keyboard	*keyboard;
} t_entity;

typedef struct s_game
{
	t_entity	entities[10];
	void		*mlx;
	void		*window;
	int			keymap[256];
	int			count_entities;
} t_game;

void	draw_system(t_game *game, t_entity *entity)
{
	if(!entity->image || !entity->position)
	return ;
	mlx_put_image_to_window(game->mlx, game->window, entity->image->img, (int)entity->position->x, (int)entity->position->y);
}

void	gravity_system(t_game *game, t_entity *entity)
{
	(void) game;
	if(!entity->position || !entity->gravity)
		return ;
	if(entity->position->y > 0 && entity->position->y < 282)
		entity->position->y += 0.005f;
	//printf("%f\n", entity->position->y);
}
void	jump_system(t_game *game, t_entity *entity)
{
	if(!entity->keyboard)
		return;
	if(game->keymap[119])
		entity->position->y -= 0.02f;
}
void	movement_system(t_game *game, t_entity *entity)
{
	if(!entity->keyboard)
		return;
	if(game->keymap[100] && entity->position->x < 570)
		entity->position->x += 0.004f;
	if(game->keymap[97] && entity->position->x > 0)
		entity->position->x -= 0.004f;
}
int	keydown(int keycode, t_game *game)
{
	game->keymap[keycode] = 1;
	(void) game;
	return (0);
}
int	keyup(int keycode, t_game *game)
{
	game->keymap[keycode] = 0;

	(void) game;
	return (0);
}
int	game_loop(t_game *game)
{
	int i;

	i = 0;
	while(i < game->count_entities)
	{
		draw_system(game, &game->entities[i]);
		movement_system(game, &game->entities[i]);
		gravity_system(game, &game->entities[i]);
		jump_system(game, &game->entities[i]);
		i++;
	}
	return(0);
}

void	load_level(t_game *game)
{
	t_entity *player;
	player = malloc(sizeof(t_entity));
	player->position = malloc(sizeof(t_position));
	player->position->x = 0;
	player->position->y = 1;
	player->image = malloc(sizeof(t_image));
	player->image->img = mlx_xpm_file_to_image(game->mlx, "../assets/idle/idle01.xpm", &player->image->width, &player->image->height);
	player->gravity = malloc(sizeof(t_gravity));
	player->keyboard = malloc(sizeof(t_keyboard));
	game->entities[game->count_entities] = *player;
	game->count_entities++;

}
int main()
{
	t_game game;
	
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 600, 342, "joguinho");
	game.count_entities = 0;
	load_level(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.window, 2, 1L<< 0, keydown, &game);
	mlx_hook(game.window, 3, 1L<< 1, keyup, &game);
  	mlx_loop(game.mlx);
}
