/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_run_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:39:39 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/23 12:47:26 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_rright_image(t_game *game, t_entity *player)
{
	player->image->rr_img[0] = mlx_xpm_file_to_image(game->mlx, "assets/runright/runr_00.xpm", &player->image->width, &player->image->height);
	player->image->rr_img[1] = mlx_xpm_file_to_image(game->mlx, "assets/runright/runr_01.xpm", &player->image->width, &player->image->height);
	player->image->rr_img[2] = mlx_xpm_file_to_image(game->mlx, "assets/runright/runr_02.xpm", &player->image->width, &player->image->height);
	player->image->rr_img[3] = mlx_xpm_file_to_image(game->mlx, "assets/runright/runr_03.xpm", &player->image->width, &player->image->height);
	player->image->rr_img[4] = mlx_xpm_file_to_image(game->mlx, "assets/runright/runr_04.xpm", &player->image->width, &player->image->height);
	player->image->rr_img[5] = mlx_xpm_file_to_image(game->mlx, "assets/runright/runr_05.xpm", &player->image->width, &player->image->height);
	player->image->rr_img[6] = mlx_xpm_file_to_image(game->mlx, "assets/runright/runr_06.xpm", &player->image->width, &player->image->height);
	player->image->rr_img[7] = mlx_xpm_file_to_image(game->mlx, "assets/runright/runr_07.xpm", &player->image->width, &player->image->height);
}
