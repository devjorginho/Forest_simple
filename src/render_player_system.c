/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_system.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:00:53 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/17 12:31:35 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_player(t_game *game)
{
	mlx_put_image_to_window(
		game->mlx, 
		game->window,
		game->player.img_player,
		game->player.p_x,
		game->player.p_y
	);
}