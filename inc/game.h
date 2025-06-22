/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:41:57 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/22 23:24:46 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "so_long.h"
#include <stdlib.h>

#define MAX_KEY_MAP 0x10000

typedef struct s_game
{
	t_entity	entities[10];
	void		*mlx;
	void		*window;
	int			keymap[MAX_KEY_MAP];
	int			count_entities;
	size_t		n_frames;
} t_game;

#endif