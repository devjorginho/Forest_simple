/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:35:42 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/22 23:42:59 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collision_system(t_game *game, t_entity *entity)
{
	int			i;
	t_entity	*b_entity;

	i = 0;
	if (!entity->position || !entity->collision)
		return ;
	while (i < game->count_entities)
	{
		b_entity = &game->entities[i];
		if (entity != b_entity && b_entity->position && b_entity->collision)
		{
			if (collision_checker(entity, b_entity))
				printf("Colidindo");
		}
		i++;
	}
}
void	draw_system(t_game *game, t_entity *entity)
{
	if (!entity->image || !entity->position)
		return ;
	mlx_put_image_to_window(game->mlx, game->window, entity->image->img[(game->n_frames / 6 ) % 11],
		(int)entity->position->x, (int)entity->position->y);
}
void	gravity_system(t_game *game, t_entity *entity)
{
	(void) game;
	if(!entity->gravity || !entity->position)
		return;
	if (entity->gravity->is_jumping)
		entity->velocity->y += 0.35f;
	if (game->keymap['w'] && !entity->gravity->is_jumping)
	{
		entity->velocity->y = -8.f;
		entity->gravity->is_jumping = 1;
	}
	entity->position->y += entity->velocity->y;
	if (entity->position->y >= 600)
	{
		entity->position->y = 600;
		entity->velocity->y = 0;
		entity->gravity->is_jumping = 0;
	}
}

void	movement_system(t_game *game, t_entity *entity)
{
	(void) game;

	if (!entity->velocity || !entity->keyboard || !entity->position)
		return ;
	if (game->keymap['d'])
		entity->velocity->x = 1.7f;
	else if (game->keymap['a'])
		entity->velocity->x = -1.7f;
	if (!game->keymap['d'] && !game->keymap['a'])
		entity->velocity->x = 0;
	entity->position->x += entity->velocity->x;
}
