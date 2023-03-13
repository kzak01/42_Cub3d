#include "key.h"

void	move_up(t_game *game)
{
	if (!game->map.map_int[(int)(game->player.pos_x + game->player.dir_x *
			game->player.movement_s)][(int)game->player.pos_y])
		game->player.pos_x += game->player.dir_x * game->player.movement_s;
	if (!game->map.map_int[(int)game->player.pos_x]
			[(int)(game->player.pos_y + game->player.dir_y * game->player.movement_s)])
		game->player.pos_y += game->player.dir_y * game->player.movement_s;
}

void	move_behind(t_game *game)
{
	if (!game->map.map_int[(int)(game->player.pos_x - game->player.dir_x *
			game->player.movement_s)][(int)game->player.pos_y])
		game->player.pos_x -= game->player.dir_x * game->player.movement_s;
	if (!game->map.map_int[(int)game->player.pos_x]
			[(int)(game->player.pos_y - game->player.dir_y * game->player.movement_s)])
		game->player.pos_y -= game->player.dir_y * game->player.movement_s;
}

void move_right(t_game *game)
{
	double dirX;
	double dirY;

	dirX = -game->player.dir_y;
	dirY = game->player.dir_x;
	if (!game->map.map_int[(int)(game->player.pos_x - dirX *
			game->player.movement_s)][(int)game->player.pos_y])
		game->player.pos_x -= dirX * game->player.movement_s;
	if (!game->map.map_int[(int)game->player.pos_x]
			[(int)(game->player.pos_y - dirY * game->player.movement_s)])
		game->player.pos_y -= dirY * game->player.movement_s;
}

void move_left(t_game *game)
{
	double dirX;
	double dirY;

	dirX = game->player.dir_y;
	dirY = -game->player.dir_x;
	if (!game->map.map_int[(int)(game->player.pos_x - dirX *
			game->player.movement_s)][(int)game->player.pos_y])
		game->player.pos_x -= dirX * game->player.movement_s;
	if (!game->map.map_int[(int)game->player.pos_x]
			[(int)(game->player.pos_y - dirY * game->player.movement_s)])
		game->player.pos_y -= dirY * game->player.movement_s;
}

