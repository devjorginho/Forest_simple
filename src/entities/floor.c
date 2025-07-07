/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:45:53 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/07 01:48:28 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

t_entity *e_floor(t_game *game)
{	
	void	*image;
	int		w;
	int		h;
	image = mlx_xpm_file_to_image(game->mlx, "assets/floor/floor.xpm", &w, &h);
	int i = 0;
	while(i < 25)
	{
		t_entity *floor;
		floor = calloc(1,sizeof(t_entity));
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