/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:30:58 by devjorginho       #+#    #+#             */
/*   Updated: 2025/10/20 13:54:46 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "so_long.h"

typedef struct s_entity
{
	t_position	*position;
	t_velocity	*velocity;
	t_sprite	*sprite;
	t_gravity	*gravity;
	t_keyboard	*keyboard;
	t_image		*image;
	t_animation	*animation;
	t_float_item *float_item;
	t_collider	*collider;
	int			active;
}	t_entity;


#endif