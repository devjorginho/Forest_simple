/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:35:42 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/25 00:02:08 by devjorginho      ###   ########.fr       */
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
	if (entity->gravity->is_jumping && entity->animation->last_direction == 0 && entity->velocity->y < 0)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			entity->image->jumpr_img[0],
			(int)entity->position->x, (int)entity->position->y);
	}
	else if (entity->gravity->is_jumping && entity->animation->last_direction == 1 && entity->velocity->y < 0)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			entity->image->jumpl_img[0],
			(int)entity->position->x, (int)entity->position->y);
	}
	else if (entity->velocity->y > 0 && entity->animation->last_direction == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			entity->image->landingr_img[0],
			(int)entity->position->x, (int)entity->position->y);
	}
	else if (entity->velocity->y > 0 && entity->animation->last_direction == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			entity->image->landingl_img[0],
			(int)entity->position->x, (int)entity->position->y);
	}
	else if (entity->animation->p_runing_r)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			entity->image->rr_img[(game->n_frames / 6) % 8],
			(int)entity->position->x, (int)entity->position->y);
	}
	else if (entity->animation->p_runing_l)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			entity->image->rl_img[(game->n_frames / 6) % 8],
			(int)entity->position->x, (int)entity->position->y);
	}
	else if (entity->animation->last_direction == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			entity->image->idler_img[(game->n_frames / 6) % 12],
			(int)entity->position->x, (int)entity->position->y);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->window,
			entity->image->idlel_img[(game->n_frames / 6) % 12],
			(int)entity->position->x, (int)entity->position->y);
	}
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
		entity->velocity->y = -9.f;
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

void movement_system(t_game *game, t_entity *entity)
{
    if (!entity->velocity || !entity->keyboard || !entity->position)
        return ;
   	else if (game->keymap['d'])
	{
		entity->animation->p_runing_r = 1;
		entity->animation->p_runing_l = 0;
		entity->animation->last_direction = 0;
		entity->velocity->x = 1.7f;
		if(game->keymap[65505])
			entity->velocity->x += 3.2f;
	}
	else if (game->keymap['a'])
	{
		entity->animation->p_runing_l = 1;
		entity->animation->p_runing_r = 0;
		entity->animation->last_direction = 1;
		entity->velocity->x = -1.7f;
		if(game->keymap[65505])
			entity->velocity->x -= 3.2f;
	}
	else
	{
		entity->animation->p_runing_r = 0;
		entity->animation->p_runing_l = 0;
		entity->velocity->x = 0;
	}
    entity->position->x += entity->velocity->x;
}
