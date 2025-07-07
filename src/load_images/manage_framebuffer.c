/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_framebuffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 00:41:21 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/07 16:43:45 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel_to_framebuffer(t_game *game, t_dataimg *dataimg, t_position position, int color)
{
	(void) game;
	char	*pixel;
	
	if(position.x >= 0 && position.x < 768 && position.y > 0 && position.y < 432)
	{
    	pixel = dataimg->addr + ((int)position.y * dataimg->size_line + (int)position.x * (dataimg->bpp / 8));
		*(int *)pixel = color;
	}
}
void	draw_img_to_framebuffer(t_game *game, t_dataimg *source, t_position position)
{
	t_dataimg dataimg;
	char	*pixel;
	
	dataimg.addr =  mlx_get_data_addr(game->framebuffer, &dataimg.bpp, &dataimg.size_line, &dataimg.endian);
	source->addr =  mlx_get_data_addr(source->image, &source->bpp, &source->size_line, &source->endian);
	int x = 0;
	int y = 0;
	while(x < source->width)
	{
		y = 0;
		while(y < source->height)
		{
			pixel = source->addr + (y * source->size_line + x * (source->bpp / 8));
			if(*(int *)pixel != (int)0xFF00FF)
				draw_pixel_to_framebuffer(game, &dataimg, (t_position){position.x + x, position.y + y}, *(int *)pixel);
			y++;
		}
		x++;
	}
}
void	clear_framebuffer(t_game *game)
{
	char	*pixel;
	int		x = 0;
	int 	y = 0;
	t_dataimg dataimg;
	dataimg.addr =  mlx_get_data_addr(game->framebuffer, &dataimg.bpp, &dataimg.size_line, &dataimg.endian);

	while(x < FRAME_BUFFER_X)
	{
		y = 0;
		while(y < FRAME_BUFFER_Y)
		{
			draw_pixel_to_framebuffer(game, &dataimg, (t_position){x, y}, (int)0x0FF0);
			y++;
		}
		x++;
	}
}
