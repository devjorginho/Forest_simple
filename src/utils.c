/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:44:11 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/21 17:16:12 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	collision_checker(t_entity *a, t_entity *b)
{
	if(!a->position || !a->collision || !b->position || !b->collision)
		return (0);
	float ax = a->position->x;
	float ay = a->position->y;
	float awidth = a->collision->width;
	float aheight = a->collision->height;
	
	float bx = b->position->x;
	float by = b->position->y;
	float bwidth = b->collision->width;
	float bheight = b->collision->height;

	if (ax < bx + bwidth && ax + awidth > bx &&
		ay < by + bheight && ay + aheight > by)
		return (1);
	return (0);
}

int	keydown(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < MAX_KEY_MAP)
		game->keymap[keycode] = 1;

	// Só seta jump_request se a entidade 0 for o player
	if (keycode == 119) // 'w'
	{
		t_entity *player = &game->entities[0];
		if (player->keyboard && player->gravity)
			player->gravity->jump_request = 1;
	}
	return (0);
}


int	keyup(int keycode, t_game *game)
{
	game->keymap[keycode] = 0;

	(void) game;
	return (0);
}