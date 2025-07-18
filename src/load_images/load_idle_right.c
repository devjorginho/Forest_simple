/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_idle_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:33:32 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/18 19:16:51 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_idler_image(t_game *game, t_entity *player)
{
	char	*image_path;
	int		i;

	i = 0;
	image_path = ft_strdup("assets/idle/idle00.xpm");
	while (i < 10)
	{
		player->image->idler_img[i] = mlx_xpm_file_to_image(game->mlx,
				image_path, &player->image->width, &player->image->height);
		image_path[17] = i + '0' + 1;
		i++;
	}
	player->image->idler_img[i++] = mlx_xpm_file_to_image(game->mlx,
			"assets/idle/idle10.xpm", &player->image->width,
			&player->image->height);
	player->image->idler_img[i++] = mlx_xpm_file_to_image(game->mlx,
			"assets/idle/idle11.xpm", &player->image->width,
			&player->image->height);
}
