/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:48:43 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/05 21:17:03 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

t_entity *e_background(t_game *game)
{
	t_entity *background;
	background = malloc(sizeof(t_entity));
	background->position = malloc(sizeof(t_position));
	background->sprite = malloc(sizeof(t_sprite));
	background->sprite->img = mlx_xpm_file_to_image(game->mlx, "assets/background/back-1.xpm", &background->sprite->w, &background->sprite->h);
	background->position->x = 0;
	background->position->y = 0;
	game->entities[game->count_entities] = *background;
	game->count_entities++;
	
	t_entity *first_layer;
	first_layer = malloc(sizeof(t_entity));
	first_layer->position = malloc(sizeof(t_position));
	first_layer->sprite = malloc(sizeof(t_sprite));
	first_layer->sprite->img = mlx_xpm_file_to_image(game->mlx, "assets/background/back-2.xpm", &first_layer->sprite->w, &first_layer->sprite->h);
	first_layer->position->x = 0;
	first_layer->position->y = 0;
	game->entities[game->count_entities] = *first_layer;
	game->count_entities++;
	
	t_entity *second_layer;
	second_layer = malloc(sizeof(t_entity));
	second_layer->position = malloc(sizeof(t_position));
	second_layer->sprite = malloc(sizeof(t_sprite));
	second_layer->sprite->img = mlx_xpm_file_to_image(game->mlx, "assets/background/back-3.xpm", &second_layer->sprite->w, &second_layer->sprite->h);
	second_layer->position->x = 0;
	second_layer->position->y = 0;
	game->entities[game->count_entities] = *second_layer;
	game->count_entities++;
	
	t_entity *third_layer;
	third_layer = malloc(sizeof(t_entity));
	third_layer->position = malloc(sizeof(t_position));
	third_layer->sprite = malloc(sizeof(t_sprite));
	third_layer->sprite->img = mlx_xpm_file_to_image(game->mlx, "assets/background/back-4.xpm", &third_layer->sprite->w, &third_layer->sprite->h);
	third_layer->position->x = 0;
	third_layer->position->y = 0;
	game->entities[game->count_entities] = *third_layer;
	game->count_entities++;
	
	t_entity *fourth_layer;
	fourth_layer = malloc(sizeof(t_entity));
	fourth_layer->position = malloc(sizeof(t_position));
	fourth_layer->sprite = malloc(sizeof(t_sprite));
	fourth_layer->sprite->img = mlx_xpm_file_to_image(game->mlx, "assets/background/back-5.xpm", &fourth_layer->sprite->w, &fourth_layer->sprite->h);
	fourth_layer->position->x = 0;
	fourth_layer->position->y = 0;
	game->entities[game->count_entities] = *fourth_layer;
	game->count_entities++;
	return (fourth_layer);
}
