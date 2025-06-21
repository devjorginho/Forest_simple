/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:30:58 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/21 16:57:55 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

#include "so_long.h"

typedef	struct s_entity
{
	t_position	*position;
	t_image		*image;
	t_gravity	*gravity;
	t_keyboard	*keyboard;
	t_collision	*collision;
} t_entity;

#endif