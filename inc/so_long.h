/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:58:48 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/18 18:40:37 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "components.h"
# include "entity.h"
# include "game.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define FRAME_BUFFER_Y 768
# define FRAME_BUFFER_X 432

// Systems
void	draw_system(t_game *game);
void	gravity_system(t_game *game);
void	jump_system(t_game *game, t_entity *entity);
void	movement_system(t_game *game);
void	float_item_system(t_game *game);
void	collision_system(t_game *game);
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
void	draw_img_to_framebuffer(t_game *game, t_dataimg *source,
			t_position position);
void	draw_pixel_to_framebuffer(t_game *game, t_dataimg *dataimg,
			t_position position, int color);
void	clear_framebuffer(t_game *game);
void	tell_a_joke(t_game *game);
void	bg_sound(t_game *game);

void	load_landingl_image(t_game *game, t_entity *player);
void	load_landingr_image(t_game *game, t_entity *player);

// Entities
void	new_player(t_game *game);
void	e_background(t_game *game);
void	second_background(t_game *game);
void	third_background(t_game *game);
void	e_collect(t_game *game);
void	e_floor(t_game *game);

#endif
