/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:44:11 by devjorginho       #+#    #+#             */
/*   Updated: 2025/10/20 13:45:13 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
        const char *jokes[] = {
            "paplay game_sounds/joke1.wav &",
            "paplay game_sounds/joke2.wav &",
            "paplay game_sounds/joke3.wav &",
            "paplay game_sounds/joke4.wav &"
        };

        int i = rand() % 4;
        system(jokes[i]);
        game->joke_cooldown = 400;
        game->keymap['z'] = 0;
    }
}

void bg_sound(t_game *game)
{
    if (!game->bg_sound_playing)
    {
		system("paplay game_sounds/background_sound.wav &");
        game->bg_sound_playing = 1;
    }
}


