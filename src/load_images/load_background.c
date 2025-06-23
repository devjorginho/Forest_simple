/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:38:22 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/23 01:40:26 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_background(t_game *game)
{
	game->bg_img = mlx_xpm_file_to_image(game->mlx, "assets/background/background.xpm", &game->bg_width, &game->bg_height);
}
