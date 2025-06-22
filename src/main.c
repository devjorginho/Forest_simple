/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:16:08 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/22 23:40:36 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_game *game)
{
	int	i;

	i = 0;
	mlx_clear_window(game->mlx, game->window);
	while (i < game->count_entities)
		draw_system(game, &game->entities[i++]);
	i = 0;
	while (i < game->count_entities)
		movement_system(game, &game->entities[i++]);
	i = 0;
	while (i < game->count_entities)
		collision_system(game, &game->entities[i++]);
	i = 0;
	while (i < game->count_entities)
		gravity_system(game, &game->entities[i++]);
	usleep(10000);
		game->n_frames++;
	return (0);
}
void	load_level(t_game *game)
{
	t_entity	*player;
	//t_entity	*player2;

	player = new_player(game);
	//player2 = new_player2(game);
}
int	main(void)
{
	static t_game	game;

	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1080, 768, "joguinho");
	load_level(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.window, 2, 1L << 0, keydown, &game);
	mlx_hook(game.window, 3, 1L << 1, keyup, &game);
	mlx_loop(game.mlx);
}
