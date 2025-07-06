/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:33:06 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/06 00:59:27 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COMPONENTS_H
# define COMPONENTS_H

#include "so_long.h"

typedef struct s_animation
{
	int	p_runing_r;
	int	p_runing_l;
	int	last_direction;
} t_animation;
typedef struct s_collision
{
	float 	width;
	float 	height;
} t_collision;

typedef struct	s_velocity
{
	float x;
	float y;
} t_velocity;

typedef struct s_position
{
	float	x;
	float	y;
} t_position;

typedef struct s_keyboard
{
} t_keyboard;

typedef struct	s_image
{
	void	*idler_img[12];
	void	*idlel_img[12];
	void	*rr_img[8];
	void	*rl_img[8];
	void	*jumpr_img[1];
	void	*jumpl_img[1];
	void	*landingr_img[1];
	void	*landingl_img[1];
	int		width;
	int		height;
} t_image;

typedef struct s_sprite
{
	void	*img;
	int		w;
	int		h;
} t_sprite;

typedef struct s_dataimg
{
	char 	*addr;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
	void	*image;
} t_dataimg;
typedef struct	s_gravity
{
	int		is_jumping;
	float	velocity;
}	t_gravity;


#endif