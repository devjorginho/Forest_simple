/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:41:57 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/21 16:58:34 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "so_long.h"
#define MAX_KEY_MAP 0x10000

typedef struct s_game
{
	t_entity	entities[10];
	void		*mlx;
	void		*window;
	int			keymap[MAX_KEY_MAP];
	int			count_entities;
} t_game;

#endif