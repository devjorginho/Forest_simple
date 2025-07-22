/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:44:11 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/22 18:59:56 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//int	collision_checker(t_entity *a, t_entity *b)
//{
//	float	ax;
//	float	ay;
//	float	awidth;
//	float	aheight;
//	float	bx;
//	float	by;
//	float	bwidth;
//	float	bheight;

//	if (!a->position || !a->collision || !b->position || !b->collision)
//		return (0);
//	ax = a->position->x;
//	ay = a->position->y;
//	awidth = a->collision->width;
//	aheight = a->collision->height;
//	bx = b->position->x;
//	by = b->position->y;
//	bwidth = b->collision->width;
//	bheight = b->collision->height;
//	if (ax < bx + bwidth && ax + awidth > bx && ay < by + bheight && ay
//		+ aheight > by)
//		return (1);
//	return (0);
//}
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
char    **alloc_map(char **map, char *line)
{
    int     i;
    int     j;
    char    **new;

    i = 0;
    j = 0;
    while (map && map[i])
        i++;
    new = malloc(sizeof(char *) * (i + 2));
    if (!new)
        return (NULL);
    while(j < i)
    {
        new[j] = map[j];
        j++;
    }
    new[i] = line;
    new[i + 1] = NULL;
    free(map);
    return (new);
}
char    **read_map(char *path)
{
    int     fd;
    char    *line;
    char    **map = NULL;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    while ((line = get_next_line(fd)))
        map = alloc_map(map, line);
    close(fd);
    return (map);
}


