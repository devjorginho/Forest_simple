/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:58:48 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/23 21:00:57 by jde-carv         ###   ########.fr       */
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
#include <string.h>

// Systems
void	collision_system(t_game *game, t_entity *entity);
void	draw_system(t_game *game, t_entity *entity);
void	gravity_system(t_game *game, t_entity *entity);
void	jump_system(t_game *game, t_entity *entity);
void	movement_system(t_game *game, t_entity *entity);
void	*scale_frame_buffer(t_game *game, t_image *image, int scale);

// Utility functions
int		keydown(int keycode, t_game *game);
int		keyup(int keycode, t_game *game);
int		collision_checker(t_entity *a, t_entity *b);
void	load_idler_image(t_game *game, t_entity *player);
void	load_idlel_image(t_game *game, t_entity *player);
void	load_rright_image(t_game *game, t_entity *player);
void	load_rleft_image(t_game *game, t_entity *player);
void	load_jumpr_image(t_game *game, t_entity *player);
void	load_jumpl_image(t_game *game, t_entity *player);

void	load_landingl_image(t_game *game, t_entity *player);
void	load_landingr_image(t_game *game, t_entity *player);

void	load_background(t_game *game);

//Entities
t_entity	*new_player(t_game *game);


#endif
