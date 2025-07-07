/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:16:08 by jde-carv          #+#    #+#             */
/*   Updated: 2025/07/07 18:45:01 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_game *game)
{
	int i = 0;
	if (game->joke_cooldown > 0)
        game->joke_cooldown--;
	bg_sound(game);
	clear_framebuffer(game);
	float_item_system(game);
	movement_system(game);
	gravity_system(game);
	tell_a_joke(game);
	draw_system(game);
	//usleep(7000);
		game->n_frames++;
	mlx_put_image_to_window(game->mlx, game->window, game->framebuffer, 0, 0);
	return (0);
}
void	load_level(t_game *game)
{
	game->count_entities = 0;
	
	e_background(game);
	e_collect(game);
	e_floor(game);
	new_player(game);
}
int	main(void)
{
	static t_game	game;

	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 768, 432, "So_long");
	game.framebuffer = mlx_new_image(game.mlx, 1080, 768);
	load_level(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	game.segredo = 0;
	mlx_hook(game.window, 2, 1L << 0, keydown, &game);
	mlx_hook(game.window, 3, 1L << 1, keyup, &game);
	mlx_loop(game.mlx);
}
