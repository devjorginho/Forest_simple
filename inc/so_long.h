/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:03:04 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/17 12:47:43 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "game.h"
# include "player.h"


// Systems

t_game		*init_game(void);
t_player	init_player(t_game *game);
void		render_player(t_game *game);
int			game_loop(void *param);
int			keydown(int keycode, t_game *game);
int			keyup(int keycode, t_game *game);

#endif