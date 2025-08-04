/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:48:43 by devjorginho       #+#    #+#             */
/*   Updated: 2025/08/04 13:47:32 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_entity	*new_background(t_game *game, char *image_path, float x,
		float y)
{
	t_entity	*background;

	background = calloc(1, sizeof(t_entity));
	background->position = calloc(1, sizeof(t_position));
	background->sprite = calloc(1, sizeof(t_sprite));
	background->sprite->img = mlx_xpm_file_to_image(game->mlx, image_path,
			&background->sprite->w, &background->sprite->h);
	background->position->x = x;
	background->position->y = y;
	return (background);
}

void	e_background(t_game *game)
{
	t_entity	*list[5];
	int			index;
	char		*image_path;

	image_path = strdup("assets/background/back-1.xpm");
	index = 0;
	while (index < 5)
	{
		image_path[23] = index + '0' + 1;
		list[index] = new_background(game, image_path, 0, 0);
		game->entities[game->count_entities] = *list[index];
		game->count_entities++;
		index++;
	}
	free(image_path);
}

void	second_background(t_game *game)
{
	t_entity	*list[5];
	int			index;
	char		*image_path;

	image_path = strdup("assets/background/back-1.xpm");
	index = 1;
	while (index < 5)
	{
		image_path[23] = index + '0' + 1;
		list[index] = new_background(game, image_path, 768, 0);
		game->entities[game->count_entities] = *list[index];
		game->count_entities++;
		index++;
	}
}

void	third_background(t_game *game)
{
	t_entity	*list[5];
	int			index;
	char		*image_path;

	image_path = strdup("assets/background/back-1.xpm");
	index = 1;
	while (index < 5)
	{
		image_path[23] = index + '0' + 1;
		list[index] = new_background(game, image_path, -768, 0);
		game->entities[game->count_entities] = *list[index];
		game->count_entities++;
		index++;
	}
}
