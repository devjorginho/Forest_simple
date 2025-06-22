/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:58:48 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/22 17:18:02 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "components.h"
#include "entity.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Systems
void	collision_system(t_game *game, t_entity *entity);
void	draw_system(t_game *game, t_entity *entity);
void	gravity_system(t_game *game, t_entity *entity);
void	jump_system(t_game *game, t_entity *entity);
void	movement_system(t_game *game, t_entity *entity);

// Utility functions
int	keydown(int keycode, t_game *game);
int	keyup(int keycode, t_game *game);
int	collision_checker(t_entity *a, t_entity *b);

t_entity	*new_player(t_game *game);
t_entity	*new_player2(t_game *game);

#endif
