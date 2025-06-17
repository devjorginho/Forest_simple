/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_system.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:43:39 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/17 13:01:15 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keydown(int keycode, t_game *game)
{
	if (keycode == 100)
		game->player.is_moving_right = 1;
	if (keycode == 97)
		game->player.is_moving_left = 1;
	return (0);
}
int	keyup(int keycode, t_game *game)
{
	if (keycode == 100)
		game->player.is_moving_right = 0;
	if (keycode == 97)
		game->player.is_moving_left = 0;
	return (0);
}