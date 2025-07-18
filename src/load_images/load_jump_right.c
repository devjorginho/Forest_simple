/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_jump_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:33:32 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/18 19:16:22 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_jumpr_image(t_game *game, t_entity *player)
{
	player->image->jumpr_img[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/jump/jump.xpm", &player->image->width,
			&player->image->height);
}
