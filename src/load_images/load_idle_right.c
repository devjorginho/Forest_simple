/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_idle_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:33:32 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/05 22:52:42 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_idler_image(t_game *game, t_entity *player)
{
	player->image->idler_img[0] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle00.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[1] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle01.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[2] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle02.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[3] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle03.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[4] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle04.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[5] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle05.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[6] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle06.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[7] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle07.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[8] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle08.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[9] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle09.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[10] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle10.xpm", &player->image->width, &player->image->height);
	player->image->idler_img[11] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle11.xpm", &player->image->width, &player->image->height);
}
