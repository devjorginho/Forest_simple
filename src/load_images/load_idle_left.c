/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_idle_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:33:32 by devjorginho       #+#    #+#             */
/*   Updated: 2025/08/04 13:47:32 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_idlel_image(t_game *game, t_entity *player)
{
	char	*image_path;
	int		i;

	i = 0;
	image_path = strdup("assets/idleleft/idle00.xpm");
	while (i < 10)
	{
		player->image->idlel_img[i] = mlx_xpm_file_to_image(game->mlx,
				image_path, &player->image->width, &player->image->height);
		image_path[21] = i + '0' + 1;
		i++;
	}
	player->image->idlel_img[i++] = mlx_xpm_file_to_image(game->mlx,
			"assets/idleleft/idle10.xpm", &player->image->width,
			&player->image->height);
	player->image->idlel_img[i++] = mlx_xpm_file_to_image(game->mlx,
			"assets/idleleft/idle11.xpm", &player->image->width,
			&player->image->height);
}
