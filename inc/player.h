/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:06:31 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/17 13:38:52 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#define RUN_FRAMES 16
#define IDLE_FRAMES 4

typedef	struct	s_player
{
	void	*p_idle;
	void	*run_right[RUN_FRAMES];
	void	*run_left[RUN_FRAMES];
	void	*idle[RUN_FRAMES];
	void	*img_player;
	int		p_x;
	int		p_y;
	int		width;
	int		height;
	int		is_moving_right;
	int		is_moving_left;
} t_player;

#endif