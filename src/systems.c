/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:35:42 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/22 20:07:54 by jde-carv         ###   ########.fr       */
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
	mlx_put_image_to_window(game->mlx, game->window, entity->image->img,
		(int)entity->position->x, (int)entity->position->y);
}
void	gravity_system(t_game *game, t_entity *entity)
{
	(void)game;
	if (!entity->position || !entity->gravity)
		return ;
	if (entity->gravity->is_jumping)
	{
		entity->velocity->y = 1.0f;
		printf("%f\n" ,entity->velocity->y);
		if (entity->gravity->velocity >= 0.0f)
			entity->gravity->is_jumping = 0;
	}
	if (entity->position->y >= 600)
	{
		entity->velocity->y = 0;
		entity->gravity->is_jumping = 0;
	}
}

void	jump_system(t_game *game, t_entity *entity)
{
	(void)game;
	if (!entity->keyboard || !entity->gravity || !entity->position)
		return ;
	if (entity->gravity->is_jumping == 0)
	{
		entity->velocity->y = -2.0f;
		entity->gravity->is_jumping = 1;
	}
}

void	movement_system(t_game *game, t_entity *entity)
{
	(void) game;

	if (!entity->velocity || !entity->keyboard || !entity->position)
		return ;
	entity->position->y += entity->velocity->y;
	if (game->keymap['d'])
		entity->position->x += 0.03f;
	else if (game->keymap['a'])
		entity->position->x -= 0.03f;
}
