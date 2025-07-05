/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:16:08 by jde-carv          #+#    #+#             */
/*   Updated: 2025/07/05 01:20:13 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_game *game)
{
	//int	i;

	//i = 0;
	//if (game->joke_cooldown > 0)
    //    game->joke_cooldown--;
	//mlx_clear_window(game->mlx, game->window);
	//mlx_put_image_to_window(game->mlx, game->window, game->bg_img, 0, 0);
	//bg_sound(game);
	//tell_a_joke(game);
	//while (i < game->count_entities)
		draw_system(game, &(*game->entities));
	//i = 0;
	//while (i < game->count_entities)
	//	movement_system(game, &game->entities[i++]);
	//i = 0;
	//while (i < game->count_entities)
	//	collision_system(game, &game->entities[i++]);
	//i = 0;
	//while (i < game->count_entities)
	//	gravity_system(game, &game->entities[i++]);
	//usleep(14500);
	//	game->n_frames++;
	mlx_put_image_to_window(game->mlx, game->window, game->framebuffer, 0, 0);
	return (0);
}
void	load_level(t_game *game)
{
	new_player(game);
}
int	main(void)
{
	static t_game	game;

	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1080, 768, "So_long");
	game.framebuffer = mlx_new_image(game.mlx, 1080, 768);
	load_background(&game);
	load_level(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.window, 2, 1L << 0, keydown, &game);
	mlx_hook(game.window, 3, 1L << 1, keyup, &game);
	mlx_loop(game.mlx);
}
