/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:48:08 by devjorginho       #+#    #+#             */
/*   Updated: 2025/10/20 13:07:03 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_player(t_game *game)
{
	t_entity	*player;

	player = calloc(1, sizeof(t_entity));
	player->position = calloc(1, sizeof(t_position));
	player->position->x = 32;
	player->position->y = 256;
	player->velocity = calloc(1, sizeof(t_velocity));
	player->gravity = calloc(1, sizeof(t_gravity));
	player->keyboard = calloc(1, sizeof(t_keyboard));
	player->image = calloc(1, sizeof(t_image));
	player->animation = calloc(1, sizeof(t_animation));
	player->collider = calloc(1, sizeof(t_collider));
	player->collider->width = 32;
	player->collider->height = 48;
	game->entities->active = 1;
	player->collider->solid = 0;
	load_idler_image(game, player);
	load_idlel_image(game, player);
	load_rright_image(game, player);
	load_rleft_image(game, player);
	load_jumpr_image(game, player);
	load_jumpl_image(game, player);
	load_landingr_image(game, player);
	load_landingl_image(game, player);
	game->entities[game->count_entities] = *player;
	game->count_entities++;
}

