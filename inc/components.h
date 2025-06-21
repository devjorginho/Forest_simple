/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:33:06 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/21 17:15:35 by devjorginho      ###   ########.fr       */
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
	void	*img;
	int		width;
	int		height;
} t_image;

typedef struct	s_gravity
{
	int		can_jump;
	int		is_jumping;
	float	velocity;
	int		jump_request;
}	t_gravity;


#endif