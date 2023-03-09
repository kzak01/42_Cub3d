#include "key.h"

void	move_up(t_game *game)
{
	if (!game->map.map_int[(int)(game->player.posX + game->player.dirX *
			game->player.movementS)][(int)game->player.posY])
		game->player.posX += game->player.dirX * game->player.movementS;
	if (!game->map.map_int[(int)game->player.posX]
			[(int)(game->player.posY + game->player.dirY * game->player.movementS)])
		game->player.posY += game->player.dirY * game->player.movementS;
}

void	move_behind(t_game *game)
{
	if (!game->map.map_int[(int)(game->player.posX - game->player.dirX *
			game->player.movementS)][(int)game->player.posY])
		game->player.posX -= game->player.dirX * game->player.movementS;
	if (!game->map.map_int[(int)game->player.posX]
			[(int)(game->player.posY - game->player.dirY * game->player.movementS)])
		game->player.posY -= game->player.dirY * game->player.movementS;
}

void move_right(t_game *game)
{
	double dirX;
	double dirY;

	dirX = -game->player.dirY;
	dirY = game->player.dirX;
	if (!game->map.map_int[(int)(game->player.posX - dirX *
			game->player.movementS)][(int)game->player.posY])
		game->player.posX -= dirX * game->player.movementS;
	if (!game->map.map_int[(int)game->player.posX]
			[(int)(game->player.posY - dirY * game->player.movementS)])
		game->player.posY -= dirY * game->player.movementS;
}

void move_left(t_game *game)
{
	double dirX;
	double dirY;

	dirX = game->player.dirY;
	dirY = -game->player.dirX;
	if (!game->map.map_int[(int)(game->player.posX - dirX *
			game->player.movementS)][(int)game->player.posY])
		game->player.posX -= dirX * game->player.movementS;
	if (!game->map.map_int[(int)game->player.posX]
			[(int)(game->player.posY - dirY * game->player.movementS)])
		game->player.posY -= dirY * game->player.movementS;
}

