/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_run_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:39:39 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/23 13:12:17 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_rleft_image(t_game *game, t_entity *player)
{
	player->image->rl_img[0] = mlx_xpm_file_to_image(game->mlx, "assets/runleft/runl_00.xpm", &player->image->width, &player->image->height);
	player->image->rl_img[1] = mlx_xpm_file_to_image(game->mlx, "assets/runleft/runl_01.xpm", &player->image->width, &player->image->height);
	player->image->rl_img[2] = mlx_xpm_file_to_image(game->mlx, "assets/runleft/runl_02.xpm", &player->image->width, &player->image->height);
	player->image->rl_img[3] = mlx_xpm_file_to_image(game->mlx, "assets/runleft/runl_03.xpm", &player->image->width, &player->image->height);
	player->image->rl_img[4] = mlx_xpm_file_to_image(game->mlx, "assets/runleft/runl_04.xpm", &player->image->width, &player->image->height);
	player->image->rl_img[5] = mlx_xpm_file_to_image(game->mlx, "assets/runleft/runl_05.xpm", &player->image->width, &player->image->height);
	player->image->rl_img[6] = mlx_xpm_file_to_image(game->mlx, "assets/runleft/runl_06.xpm", &player->image->width, &player->image->height);
	player->image->rl_img[7] = mlx_xpm_file_to_image(game->mlx, "assets/runleft/runl_07.xpm", &player->image->width, &player->image->height);
}
