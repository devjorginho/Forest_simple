/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:44:11 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/22 19:58:42 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	collision_checker(t_entity *a, t_entity *b)
{
	float	ax;
	float	ay;
	float	awidth;
	float	aheight;
	float	bx;
	float	by;
	float	bwidth;
	float	bheight;

	if (!a->position || !a->collision || !b->position || !b->collision)
		return (0);
	ax = a->position->x;
	ay = a->position->y;
	awidth = a->collision->width;
	aheight = a->collision->height;
	bx = b->position->x;
	by = b->position->y;
	bwidth = b->collision->width;
	bheight = b->collision->height;
	if (ax < bx + bwidth && ax + awidth > bx && ay < by + bheight && ay
		+ aheight > by)
		return (1);
	return (0);
}

int	keydown(int keycode, t_game *game)
{
	t_entity	*player;

	player = &game->entities[0];
	if (keycode >= 0 && keycode < MAX_KEY_MAP)
		game->keymap[keycode] = 1;
	if (keycode == 119 && !player->gravity->is_jumping)
			player->gravity->is_jumping = 1;
	return (0);
}

int	keyup(int keycode, t_game *game)
{
	t_entity *player;

	player = &game->entities[0];
	game->keymap[keycode] = 0;
	//if (keycode == 119)
	//	player->velocity->y = 0;	
	return (0);
}