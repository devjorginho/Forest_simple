/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:35:47 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/17 11:55:52 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_game	*init_game(void)
{
	t_game *game;
	
	game = malloc(sizeof(t_game));
	if(!game)
		return (NULL);
	game->mlx = mlx_init();
	if(!game->mlx)
	{
		free (game);
		return (NULL);
	}
	game->window = mlx_new_window(game->mlx, 640, 342, "jogo do jorginho!");
	if(!game->window)
	{
		free (game);
		return (NULL);
	}
	game->player = init_player(game);
	return (game);
}
