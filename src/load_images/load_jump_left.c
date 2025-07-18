/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_jump_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:26:28 by jde-carv          #+#    #+#             */
/*   Updated: 2025/07/18 19:17:00 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_jumpl_image(t_game *game, t_entity *player)
{
	player->image->jumpl_img[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/jump/jump-left.xpm", &player->image->width,
			&player->image->height);
}
