/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:33:06 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/22 23:12:12 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COMPONENTS_H
# define COMPONENTS_H

#include "so_long.h"

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
	void	**img;
	int		width;
	int		height;
} t_image;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct	s_gravity
{
	int		is_jumping;
	float	velocity;
}	t_gravity;


#endif