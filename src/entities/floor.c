/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:45:53 by devjorginho       #+#    #+#             */
/*   Updated: 2025/10/20 14:25:12 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* floor.c (CORRIGIDO) */
/* ************************************************************************** */

#include "so_long.h"

void    e_floor(t_game *game)
{
    void        *image;
    t_entity    *floor;
    int         w;
    int         h;
    int         i;

    image = mlx_xpm_file_to_image(game->mlx, "assets/floor/floor.xpm", &w, &h);
    i = 0;
    while (i < 25)
    {
        floor = calloc(1, sizeof(t_entity));
        floor->position = calloc(1, sizeof(t_position));
        floor->sprite = calloc(1, sizeof(t_sprite));
        floor->collider = calloc(1, sizeof(t_collider));
        game->entities->active = 1;
        floor->sprite->img = image;
        floor->sprite->h = h;
        floor->sprite->w = w;
        floor->position->x = 32 * i;
        floor->position->y = 400;
        floor->collider->width = 32;
        floor->collider->height = 32;
        floor->collider->solid = 1;
        game->entities[game->count_entities] = *floor;
        game->count_entities++;
        i++;
    }
}

void    e_platform(t_game *game, int x, int y, int count)
{
    void        *image;
    t_entity    *platform;
    int         w;
    int         h;
    int         i;

    image = mlx_xpm_file_to_image(game->mlx, "assets/floor/floor.xpm", &w, &h);
    i = 0;
    while (i < count)
    {
        platform = calloc(1, sizeof(t_entity));
        platform->position = calloc(1, sizeof(t_position));
        platform->sprite = calloc(1, sizeof(t_sprite));
        platform->collider = calloc(1, sizeof(t_collider));
        
        platform->sprite->img = image;
        platform->sprite->h = h;
        platform->sprite->w = w;
        
        platform->position->x = x + (32 * i);
        platform->position->y = y;
        
        platform->collider->width = 32;
        platform->collider->height = 32;
        platform->collider->solid = 1;
        
        game->entities[game->count_entities] = *platform;
        game->count_entities++;
        i++;
    }
}

