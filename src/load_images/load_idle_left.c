/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_idle_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:33:32 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/23 13:21:08 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_idlel_image(t_game *game, t_entity *player)
{
	player->image->idlel_img[0] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel00.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[1] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel01.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[2] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel02.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[3] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel03.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[4] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel04.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[5] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel05.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[6] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel06.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[7] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel07.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[8] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel08.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[9] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel09.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[10] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel10.xpm", &player->image->width, &player->image->height);
	player->image->idlel_img[11] = mlx_xpm_file_to_image(game->mlx, "assets/idleleft/idlel11.xpm", &player->image->width, &player->image->height);
}
