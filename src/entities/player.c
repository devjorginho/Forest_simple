/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:48:08 by devjorginho       #+#    #+#             */
/*   Updated: 2025/08/04 13:47:22 by jde-carv         ###   ########.fr       */
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
	player->image = calloc(1, sizeof(t_image));
	player->animation = calloc(1, sizeof(t_animation));
	load_idler_image(game, player);
	load_idlel_image(game, player);
	load_rright_image(game, player);
	load_rleft_image(game, player);
	load_jumpr_image(game, player);
	load_jumpl_image(game, player);
	load_landingr_image(game, player);
	load_landingl_image(game, player);
	player->gravity = calloc(1, sizeof(t_gravity));
	player->velocity = calloc(1, sizeof(t_velocity));
	player->keyboard = calloc(1, sizeof(t_keyboard));
	game->entities[game->count_entities] = *player;
	game->count_entities++;
}
