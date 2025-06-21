/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:16:08 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/21 17:18:19 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	game_loop(t_game *game)
{
	int i;

	i = 0;
	mlx_clear_window(game->mlx, game->window);
	while(i < game->count_entities)
	{
		draw_system(game, &game->entities[i]);
		movement_system(game, &game->entities[i]);
		collision_system(game, &game->entities[i]);
		jump_system(game, &game->entities[i]);
		gravity_system(game, &game->entities[i]);
		i++;
	}
	return(0);
}

void	load_level(t_game *game)
{
	t_entity *player;
	player = malloc(sizeof(t_entity));
	player->position = malloc(sizeof(t_position));
	player->position->x = 64;
	player->position->y = 64;
	player->image = malloc(sizeof(t_image));
	player->image->img = mlx_xpm_file_to_image(game->mlx, "/home/devjorginho/Desktop/42/SO_LONG/assets/idle/idle01.xpm", &player->image->width, &player->image->height);
	player->gravity = malloc(sizeof(t_gravity));
	player->gravity->can_jump = 1;
	player->gravity->is_jumping = 0;
	player->gravity->velocity = 0.0f;
	player->gravity->jump_request = 0;


	player->collision = malloc(sizeof(t_collision));
	player->collision->width = 32;  // ou o tamanho que quiser
	player->collision->height = 32;
	player->keyboard = malloc(sizeof(t_keyboard));
	game->entities[game->count_entities] = *player;
	game->count_entities++;

	t_entity *player2;
	player2 = malloc(sizeof(t_entity));
	player2->position = malloc(sizeof(t_position));
	player2->position->x = 128;
	player2->position->y = 64;
	player2->image = malloc(sizeof(t_image));
	player2->image->img = mlx_xpm_file_to_image(game->mlx, "/home/devjorginho/Desktop/42/SO_LONG/assets/idle/idle01.xpm", &player2->image->width, &player2->image->height);
	player2->gravity = malloc(sizeof(t_gravity));
	player2->collision = malloc(sizeof(t_collision));
	player2->collision->width = 32;  // ou o tamanho que quiser
	player2->collision->height = 32;
	//player2->keyboard = malloc(sizeof(t_keyboard));
	game->entities[game->count_entities] = *player2;
	game->count_entities++;
}
int main()
{
	t_game game;
	
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1080, 768, "joguinho");
	game.count_entities = 0;
	load_level(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.window, 2, 1L<< 0, keydown, &game);
	mlx_hook(game.window, 3, 1L<< 1, keyup, &game);
  	mlx_loop(game.mlx);
}
