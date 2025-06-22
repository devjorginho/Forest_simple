/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:15:18 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/22 18:58:25 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"

//t_entity *new_player2(t_game *game)
//{
//	t_entity *player2;

//	player2 = malloc(sizeof(t_entity));
//	player2->position = malloc(sizeof(t_position));
//	player2->position->x = 64;
//	player2->position->y = 86;
//	player2->image = malloc(sizeof(t_image));
//	player2->image->img = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle01.xpm", &player2->image->width, &player2->image->height);
//	player2->gravity = malloc(sizeof(t_gravity));
//	player2->collision = malloc(sizeof(t_collision));
//	player2->collision->width = 32;  // ou o tamanho que quiser
//	player2->collision->height = 32;
//	game->entities[game->count_entities] = *player2;
//	game->count_entities++;
//	return (player2);
//}