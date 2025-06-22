
#include "so_long.h"

t_entity *new_player(t_game *game)
{
	t_entity *player;

	player = malloc(sizeof(t_entity));
	player->position = malloc(sizeof(t_position));
	player->position->x = 64;
	player->position->y = 64;
	player->image = malloc(sizeof(t_image));
	player->image->img = mlx_xpm_file_to_image(game->mlx, "assets/idle/idle01.xpm", &player->image->width, &player->image->height);
	player->gravity = malloc(sizeof(t_gravity));
	player->gravity->can_jump = 1;
	player->gravity->is_jumping = 0;
	player->gravity->velocity = 0.0f;
	player->gravity->jump_request = 0;
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