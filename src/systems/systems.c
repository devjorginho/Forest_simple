/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:35:42 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/07 15:52:44 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
			if (game->entities[i].animation->is_jumping && game->entities[i].animation->last_direction == 0 && game->entities[i].velocity->y < 0)
			{
				dataimg.image = game->entities[i].image->jumpr_img[0];
				dataimg.width = 34;
				dataimg.height = 68;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else if (game->entities[i].animation->is_jumping && game->entities[i].animation->last_direction == 1 && game->entities[i].velocity->y < 0)
			{
				dataimg.image = game->entities[i].image->jumpl_img[0];
				dataimg.width = 34;
				dataimg.height = 68;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else if (game->entities[i].velocity->y > 0 && game->entities[i].animation->last_direction == 1)
			{
				dataimg.image = game->entities[i].image->landingl_img[0];
				dataimg.width = 40;
				dataimg.height = 70;
				draw_img_to_framebuffer(game, &dataimg, *game->entities[i].position);
			}
			else if (game->entities[i].velocity->y > 0 && game->entities[i].animation->last_direction == 0)
			{
				dataimg.image = game->entities[i].image->landingr_img[0];
				dataimg.width = 40;
				dataimg.height = 70;
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

void	gravity_system(t_game *game)
{
	int i;

	i = 0;
	while(i < game->count_entities)
	{
		if (game->entities[i].gravity && game->entities[i].position && game->entities[i].velocity)
		{
				game->entities[i].velocity->y += 2.0f;
			if (game->keymap['w'] && !game->entities[i].animation->is_jumping)
			{
				game->entities[i].velocity->y = -18.f;
				game->entities[i].animation->is_jumping = 1;
			}
			game->entities[i].position->y += game->entities[i].velocity->y;
			if (game->entities[i].position->y >= 350)
			{
				game->entities[i].position->y = 350;
				game->entities[i].velocity->y = 0;
				game->entities[i].animation->is_jumping = 0;
			}
		}
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
				game->entities[i].velocity->x = 5.2f;
				game->entities[i].position->x += game->entities[i].velocity->x;
				if(game->keymap[65505])
				{
					game->entities[i].velocity->x += 6.4f;
				}
			}
			else if (game->keymap['a'])
			{
				game->entities[i].animation->p_runing_l = 1;
				game->entities[i].animation->p_runing_r = 0;
				game->entities[i].animation->last_direction = 1;
				game->entities[i].velocity->x = -5.2f;
				game->entities[i].position->x += game->entities[i].velocity->x;
				if(game->keymap[65505])
				{
					game->entities[i].velocity->x -= 6.4f;
				}
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
