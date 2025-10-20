/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/06/17 17:16:08 by jde-carv          #+#    #+#             */
/* Updated: 2025/10/20 13:02:15 by devjorginho      ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "so_long.h"

int game_loop(t_game *game)
{
    if (game->joke_cooldown > 0)
        game->joke_cooldown--;
    bg_sound(game);
    clear_framebuffer(game);
    float_item_system(game);
    
    gravity_system(game);
    
    movement_system(game);
    
    collision_system(game); 
    
    tell_a_joke(game);
    draw_system(game);
    //usleep(7000);
    game->n_frames++;
    mlx_put_image_to_window(game->mlx, game->window, game->framebuffer, 0, 0);
    return (0);
}

void    load_level(t_game *game)
{
   game->count_entities = 0;
   game->collected_count = 0;
   game->total_collectables = 2;
    e_background(game);
    second_background(game);
    third_background(game);
    e_platform(game, 100, 300, 1);
    e_platform(game, 400, 250, 3); 
    e_platform(game, 700, 180, 1); 
    e_collect_at(game, 700, 148); 
    e_collect(game);
    e_floor(game);
    new_player(game);
}

int main(void)
{
    static t_game   game;

    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, 768, 432, "So_long");
    game.framebuffer = mlx_new_image(game.mlx, (768 * 3), (432 * 3));
    load_level(&game);
    game.parallax = 0;
    game.joke_cooldown = 0;
    game.n_frames = 0;
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_hook(game.window, 2, 1L << 0, keydown, &game);
    mlx_hook(game.window, 3, 1L << 1, keyup, &game);
    mlx_loop(game.mlx);
}