/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_landing_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:33:32 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/23 21:34:08 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_landingl_image(t_game *game, t_entity *player)
{
	player->image->landingl_img[0] = mlx_xpm_file_to_image(game->mlx, "assets/landing/landing_l.xpm", &player->image->width, &player->image->height);
}