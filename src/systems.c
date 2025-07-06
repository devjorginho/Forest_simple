/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:35:42 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/06 01:45:17 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collision_system(t_game *game)
{
	int			i;
	t_entity	*b_entity;

	i = 0;
	while (i < game->count_entities)
	{
		if (!game->entities[i].position || game->entities[i].collision)
			return ;
		b_entity = &game->entities[i];
		if (&game->entities[i] != b_entity && b_entity->position && b_entity->collision)
		{
			if (collision_checker(&game->entities[i], b_entity))
				printf("Colidindo");
		}
		i++;
	}
}
void	draw_system(t_game *game)
{
	t_dataimg dataimg;
	int i;

	i = 0;
	while(i < game->count_entities)
	{
		if ((game->entities[i].sprite) && game->entities[i].position)
		{
			dataimg.image = game->entities[i].sprite->img;
			dataimg.width = game->entities[i].sprite->w;
			dataimg.height = game->entities[i].sprite->h;
			if(i == 4)
				game->entities[i].position->x = game->entities[i].position->x - game->segredo;
			if(i == 3)
				game->entities[i].position->x = game->entities[i].position->x - game->segredo * 0.35;
			if(i == 2)
				game->entities[i].position->x = game->entities[i].position->x - game->segredo * 0.18;
			if(i == 1)
				game->entities[i].position->x = game->entities[i].position->x - game->segredo * 0.10;
			draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
		}
		else if(game->entities[i].image && game->entities[i].position)
		{
			if (game->entities[i].gravity->is_jumping && game->entities[i].animation->last_direction == 0 && game->entities[i].velocity->y < 0)
			{
				dataimg.image = game->entities[i].image->jumpr_img[0];
				dataimg.width = 34;
				dataimg.height = 68;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else if (game->entities[i].gravity->is_jumping && game->entities[i].animation->last_direction == 1 && game->entities[i].velocity->y < 0)
			{
				dataimg.image = game->entities[i].image->jumpl_img[0];
				dataimg.width = 34;
				dataimg.height = 68;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else if (game->entities[i].velocity->y > 0 && game->entities[i].animation->last_direction == 0)
			{
				dataimg.image = game->entities[i].image->landingl_img[0];
				dataimg.width = 15;
				dataimg.height = 15;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else if (game->entities[i].velocity->y > 0 && game->entities[i].animation->last_direction == 1)
			{
				dataimg.image = game->entities[i].image->landingr_img[0];
				dataimg.width = 15;
				dataimg.height = 15;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else if (game->entities[i].animation->p_runing_r)
			{
				dataimg.image = game->entities[i].image->rr_img[(game->n_frames) % 8];
				dataimg.width = 42;
				dataimg.height = 66;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else if (game->entities[i].animation->p_runing_l)
			{
				dataimg.image = game->entities[i].image->rl_img[(game->n_frames) % 8];
				dataimg.width = 42;
				dataimg.height = 66;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else if (game->entities[i].animation->last_direction == 0)
			{
				dataimg.image = game->entities[i].image->idler_img[(game->n_frames) % 12];
				dataimg.width = 38;
				dataimg.height = 68;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else
			{
				dataimg.image = game->entities[i].image->idlel_img[(game->n_frames) % 12];
				dataimg.width = 38;
				dataimg.height = 68;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
		}
		i++;
	}
}
	
//void	gravity_system(t_game *game)
//{
//	int i;

//	i = 0;
//	while(i < game->count_entities)
//	{
//		if (game->entities[i].gravity && game->entities[i].position && game->entities[i].velocity)
//		{
//			if (game->entities[i].gravity->is_jumping)
//				game->entities[i].velocity->y += 0.35f;
//			else if (game->keymap['w'] && !game->entities[i].gravity->is_jumping)
//			{
//				game->entities[i].velocity->y = -9.f;
//				game->entities[i].gravity->is_jumping = 1;
//			}
//			game->entities[i].position->y += game->entities[i].velocity->y;
//			if (game->entities[i].position->y >= 400)
//			{
//				game->entities[i].position->y = 400;
//				game->entities[i].velocity->y = 0;
//				game->entities[i].gravity->is_jumping = 0;
//			}
//		}
//		printf("oi");
//		i++;
//	}
//}
void	gravity_system(t_game *game)
{
	int i = 0;
	while(i < game->count_entities)
	{
		if(game->entities[i].gravity && game->entities[i].position)
			game->entities[i].position->y += 3;
		i++;
	}
}
void movement_system(t_game *game)
{
	int i;

	i = 0;
	while(i < game->count_entities)
	{
		if (game->entities[i].velocity && game->entities[i].keyboard && game->entities[i].position)
		{
			if (game->keymap['d'])
			{
				game->entities[i].animation->p_runing_r = 1;
				game->entities[i].animation->p_runing_l = 0;
				game->entities[i].animation->last_direction = 0;
				game->entities[i].velocity->x = 3.2f;
				if(game->keymap[65505])
					game->entities[i].velocity->x += 4.2f;
			}
			else if (game->keymap['a'])
			{
				game->entities[i].animation->p_runing_l = 1;
				game->entities[i].animation->p_runing_r = 0;
				game->entities[i].animation->last_direction = 1;
				game->entities[i].velocity->x = -3.2f;
				if(game->keymap[65505])
					game->entities[i].velocity->x -= 4.2f;
			}
			else
			{
				game->entities[i].animation->p_runing_r = 0;
				game->entities[i].animation->p_runing_l = 0;
				game->entities[i].velocity->x = 0;
			}
			game->segredo = game->entities[i].velocity->x;
			game->entities[i].position->x += game->entities[i].velocity->x;
		}		
		i++;
	}
}
