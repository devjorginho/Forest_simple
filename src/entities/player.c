
#include "so_long.h"

t_entity *new_player(t_game *game)
{
	t_entity *player;

	player = malloc(sizeof(t_entity));
	player->position = malloc(sizeof(t_position));
	player->position->x = 64;
	player->position->y = 64;
	player->image = malloc(sizeof(t_image));
	player->image->img = malloc(sizeof(void *) * 12);
	player->image->img[0] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle01.xpm", &player->image->width, &player->image->height);
	player->image->img[1] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle02.xpm", &player->image->width, &player->image->height);
	player->image->img[2] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle03.xpm", &player->image->width, &player->image->height);
	player->image->img[3] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle04.xpm", &player->image->width, &player->image->height);
	player->image->img[4] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle05.xpm", &player->image->width, &player->image->height);
	player->image->img[5] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle06.xpm", &player->image->width, &player->image->height);
	player->image->img[6] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle07.xpm", &player->image->width, &player->image->height);
	player->image->img[7] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle08.xpm", &player->image->width, &player->image->height);
	player->image->img[8] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle09.xpm", &player->image->width, &player->image->height);
	player->image->img[9] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle10.xpm", &player->image->width, &player->image->height);
	player->image->img[10] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle11.xpm", &player->image->width, &player->image->height);
	player->image->img[11] = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle12.xpm", &player->image->width, &player->image->height);
	player->gravity = malloc(sizeof(t_gravity));
	player->gravity->is_jumping = 0;
	player->gravity->velocity = 0.0f;
	player->velocity = malloc(sizeof(t_velocity));
	player->velocity->x = 0;
	player->velocity->y = 0;
	player->collision = malloc(sizeof(t_collision));
	player->collision->width = 32;  // ou o tamanho que quiser
	player->collision->height = 32;
	player->keyboard = malloc(sizeof(t_keyboard));
	game->entities[game->count_entities] = *player;
	game->count_entities++;
	return (player);
}
