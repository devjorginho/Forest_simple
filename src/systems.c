/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:35:42 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/21 17:32:16 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collision_system(t_game *game, t_entity *entity)
{
	int i;

	i = 0;
	if(!entity->position || !entity->collision)
		return;
	while (i < game->count_entities)
	{
		t_entity *b_entity = &game->entities[i];
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
	if(!entity->image || !entity->position)
	return ;
	mlx_put_image_to_window(game->mlx, game->window, entity->image->img, (int)entity->position->x, (int)entity->position->y);
}
void	gravity_system(t_game *game, t_entity *entity)
{
	(void) game;
	if (!entity->position || !entity->gravity)
		return ;

	if (entity->gravity->is_jumping)
	{
		entity->position->y += entity->gravity->velocity;
		entity->gravity->velocity += 0.060f; // gravidade mais suave

		if (entity->gravity->velocity >= 0.0f)
			entity->gravity->is_jumping = 0;
	}
	else
	{
		if (entity->position->y < 300)
			entity->position->y += 0.08f;
		else
			entity->gravity->can_jump = 1;
	}
}






void	jump_system(t_game *game, t_entity *entity)
{
	(void) game;

	if (!entity->keyboard || !entity->gravity || !entity->position)
		return ;

	if (entity->gravity->jump_request && entity->gravity->can_jump)
	{
		entity->gravity->is_jumping = 1;
		entity->gravity->can_jump = 0;
		entity->gravity->velocity = -3.2f; // aumento suave na força do pulo
	}
	entity->gravity->jump_request = 0;
}







void movement_system(t_game *game, t_entity *entity)
{
    float new_x;

    if (!entity->keyboard || !entity->position)
        return ;

    new_x = entity->position->x;

    if (game->keymap['d'])
        new_x += 0.07f;
    else if (game->keymap['a'])
        new_x -= 0.07f;
    t_entity temp = *entity;
    temp.position = malloc(sizeof(t_position));
    temp.position->x = new_x;
    temp.position->y = entity->position->y;
    temp.collision = entity->collision;

    int can_move = 1;
    for (int i = 0; i < game->count_entities; i++)
    {
        if (&game->entities[i] != entity)
        {
            if (collision_checker(&temp, &game->entities[i]))
            {
                can_move = 0;
                break;
            }
        }
    }

    free(temp.position);

    if (can_move)
        entity->position->x = new_x;
}
