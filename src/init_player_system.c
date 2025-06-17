/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_system.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:44:03 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/17 13:38:59 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_player	init_player(t_game *game)
{
	t_player	player;

	player.p_x = 0;
	player.p_y = 0;
	player.is_moving_right = 0;
	player.is_moving_left = 0;
	player.img_player = mlx_xpm_file_to_image(
		game->mlx,
		"assets/idle/idle_00.xpm",
		&player.width,
		&player.height
	);
	return (player);
}
