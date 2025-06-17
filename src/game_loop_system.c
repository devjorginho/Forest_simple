/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:36:57 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/17 13:02:11 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	game_loop(void *param)
{
	static int	frame_count = 0;
	t_game		*game;

	game = (t_game *)param;
	frame_count++;
	if (frame_count % 25 == 0)
	{
		if (game->player.is_moving_right && game->player.p_x < 600)
				game->player.p_x++;
		if (game->player.is_moving_left && game->player.p_x > 0)
				game->player.p_x--;
	}
	mlx_clear_window(game->mlx, game->window);
	render_player(game);
	return (0);
}

