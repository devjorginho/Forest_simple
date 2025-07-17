/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:41:57 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/17 20:55:10 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "so_long.h"
#include <stdlib.h>

#define MAX_ENTITIES 300
#define	MAX_KEY_MAP	70000

typedef struct s_game
{
	t_entity	entities[MAX_ENTITIES];
	char		**map;
	int			map_width;
	int			map_height;
	void		*mlx;
	void		*window;
	void		*framebuffer;
	void		*bg_img;
	float		segredo;
	int			keymap[MAX_KEY_MAP];
	int			count_entities;
	int			bg_width;
	int			bg_height;
	int			joke_cooldown;
	int			bg_sound_playing;
	size_t		n_frames;
} t_game;

#endif