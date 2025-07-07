/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:48:08 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/07 01:27:10 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

t_entity *new_player(t_game *game)
{
	t_entity *player;

	player = calloc(1, sizeof(t_entity));
	player->position = calloc(1, sizeof(t_position));
	player->position->x = 32;
	player->position->y = 256;
	player->image = calloc(1, sizeof(t_image));
	player->animation = calloc(1, sizeof(t_animation));
	player->animation->last_direction = 0;
	player->animation->p_runing_r = 0;
	player->animation->p_runing_l = 0;
	load_idler_image(game, player);
	load_idlel_image(game, player);
	load_rright_image(game, player);
	load_rleft_image(game,player);
	load_jumpr_image(game,player);
	load_jumpl_image(game,player);
	load_landingr_image(game,player);
	load_landingl_image(game,player);

	player->gravity = calloc(1, sizeof(t_gravity));
	player->animation->is_jumping = 0;
	player->gravity->velocity = 0.0f;
	player->velocity = calloc(1, sizeof(t_velocity));
	player->velocity->x = 0;
	player->velocity->y = 0;
	player->collision = calloc(1, sizeof(t_collision));
	player->collision->width = 32;
	player->collision->height = 32;
	player->keyboard = calloc(1, sizeof(t_keyboard));
	game->entities[game->count_entities] = *player;
	game->count_entities++;
	return (player);
}
