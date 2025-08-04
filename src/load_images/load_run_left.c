/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_run_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:39:39 by devjorginho       #+#    #+#             */
/*   Updated: 2025/08/04 13:47:32 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_rleft_image(t_game *game, t_entity *player)
{
	char	*image_path;
	int		i;

	image_path = strdup("assets/runleft/runl_00.xpm");
	i = 0;
	while (i < 8)
	{
		player->image->rl_img[i] = mlx_xpm_file_to_image(game->mlx, image_path,
				&player->image->width, &player->image->height);
		image_path[21] = i + '0' + 1;
		i++;
	}
}
