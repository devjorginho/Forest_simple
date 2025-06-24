/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:44:11 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/25 00:31:09 by devjorginho      ###   ########.fr       */
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
	if (keycode >= 0 && keycode < MAX_KEY_MAP)
		game->keymap[keycode] = 1;
	return (0);
}

int	keyup(int keycode, t_game *game)
{
	game->keymap[keycode] = 0;
	return (0);
}
void tell_a_joke(t_game *game)
{
    if (game->keymap['z'] && game->joke_cooldown == 0)
    {
        system("aplay sounds/joke1.wav &");
        game->joke_cooldown = 400;
        game->keymap['z'] = 0;
    }
}
void bg_sound(t_game *game)
{
    if (!game->bg_sound_playing)
    {
		system("aplay sounds/background_low.wav &");
        game->bg_sound_playing = 1;
    }
}


