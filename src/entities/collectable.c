/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:34:26 by jde-carv          #+#    #+#             */
/*   Updated: 2025/07/07 17:55:51 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void e_collect(t_game *game)
{
	t_entity *collect;
	collect = calloc(1,sizeof(t_entity));
	collect->position = calloc(1, sizeof(t_position));
	collect->sprite = calloc(1, sizeof(t_sprite));
	collect->float_item = calloc(1, sizeof(t_float_item));
	collect->float_item->dir = 1;
	collect->sprite->img = mlx_xpm_file_to_image(game->mlx, "assets/collectable/MelonWater.xpm", &collect->sprite->w, &collect->sprite->h);
	collect->position->x = 700;
	collect->position->y = 350;
	collect->float_item->initial_y = collect->position->y;
	game->entities[game->count_entities] = *collect;
	game->count_entities++;
}