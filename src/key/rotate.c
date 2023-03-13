#include "key.h"

void	rotate_right(t_game *game)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = game->player.dirX;
	oldPlaneX = game->player.planeX;
	game->player.dirX = game->player.dirX * cos(-game->player.rotationS) -
			game->player.dirY * sin(-game->player.rotationS);
	game->player.dirY = oldDirX * sin(-game->player.rotationS) +
			game->player.dirY * cos(-game->player.rotationS);

	game->player.planeX = game->player.planeX * cos(-game->player.rotationS) -
			game->player.planeY * sin(-game->player.rotationS);
	game->player.planeY = oldPlaneX * sin(-game->player.rotationS) +
			game->player.planeY * cos(-game->player.rotationS);
}

void	rotate_left(t_game *game)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = game->player.dirX;
	oldPlaneX = game->player.planeX;
	game->player.dirX = game->player.dirX * cos(game->player.rotationS) -
			game->player.dirY * sin(game->player.rotationS);
	game->player.dirY = oldDirX * sin(game->player.rotationS) +
			game->player.dirY * cos(game->player.rotationS);

	game->player.planeX = game->player.planeX * cos(game->player.rotationS) -
			game->player.planeY * sin(game->player.rotationS);
	game->player.planeY = oldPlaneX * sin(game->player.rotationS) +
			game->player.planeY * cos(game->player.rotationS);
}