/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:34:26 by jde-carv          #+#    #+#             */
/*   Updated: 2025/10/20 14:25:22 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    e_collect_at(t_game *game, int x, int y)
{
    t_entity    *collect;

    collect = calloc(1, sizeof(t_entity));
    collect->position = calloc(1, sizeof(t_position));
    collect->sprite = calloc(1, sizeof(t_sprite));
    collect->float_item = calloc(1, sizeof(t_float_item));
    collect->collider = calloc(1, sizeof(t_collider));
    game->entities->active = 1;

    collect->float_item->dir = 1;
    
    // Carregamento e Posição
    collect->sprite->img = mlx_xpm_file_to_image(game->mlx,
            "assets/collectable/MelonWater.xpm",
            &collect->sprite->w, &collect->sprite->h);
    collect->position->x = x;
    collect->position->y = y;
    collect->float_item->initial_y = collect->position->y;

    collect->collider->width = 24;
    collect->collider->height = 24;
    collect->collider->solid = 0;

    game->entities[game->count_entities] = *collect;
    game->count_entities++;
}


void    e_collect(t_game *game)
{
    e_collect_at(game, 700, 350);
}

