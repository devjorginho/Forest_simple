/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_run_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:39:39 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/18 19:17:23 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_rright_image(t_game *game, t_entity *player)
{
	char	*image_path;
	int		i;

	image_path = ft_strdup("assets/runright/runr_00.xpm");
	i = 0;
	while (i < 8)
	{
		player->image->rr_img[i] = mlx_xpm_file_to_image(game->mlx, image_path,
				&player->image->width, &player->image->height);
		image_path[22] = i + '0' + 1;
		i++;
	}
}
