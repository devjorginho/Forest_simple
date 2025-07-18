/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:45:53 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/18 18:44:30 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	e_floor(t_game *game)
{
	void		*image;
	t_entity	*floor;
	int			w;
	int			h;
	int			i;

	image = mlx_xpm_file_to_image(game->mlx, "assets/floor/floor.xpm", &w, &h);
	i = 0;
	while (i < 25)
	{
		floor = calloc(1, sizeof(t_entity));
		floor->position = calloc(1, sizeof(t_position));
		floor->sprite = calloc(1, sizeof(t_sprite));
		floor->sprite->img = image;
		floor->sprite->h = h;
		floor->sprite->w = w;
		floor->position->x = 32 * i;
		floor->position->y = 400;
		game->entities[game->count_entities] = *floor;
		game->count_entities++;
		i++;
	}
}
