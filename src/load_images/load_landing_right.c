/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_landing_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:33:32 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/06 00:54:00 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_landingr_image(t_game *game, t_entity *player)
{
	player->image->landingr_img[0] = mlx_xpm_file_to_image(game->mlx, "assets/landing/landing-right.xpm", &player->image->width, &player->image->height);
}