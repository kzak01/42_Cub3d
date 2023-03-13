#include "key.h"

void	rotate_right(t_game *game)
{
	double	oldDirX;
	double	oldPlane_x;

	oldDirX = game->player.dir_x;
	oldPlane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(-game->player.rotation_s) -
			game->player.dir_y * sin(-game->player.rotation_s);
	game->player.dir_y = oldDirX * sin(-game->player.rotation_s) +
			game->player.dir_y * cos(-game->player.rotation_s);

	game->player.plane_x = game->player.plane_x * cos(-game->player.rotation_s) -
			game->player.plane_y * sin(-game->player.rotation_s);
	game->player.plane_y = oldPlane_x * sin(-game->player.rotation_s) +
			game->player.plane_y * cos(-game->player.rotation_s);
}

void	rotate_left(t_game *game)
{
	double	oldDirX;
	double	oldPlane_x;

	oldDirX = game->player.dir_x;
	oldPlane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(game->player.rotation_s) -
			game->player.dir_y * sin(game->player.rotation_s);
	game->player.dir_y = oldDirX * sin(game->player.rotation_s) +
			game->player.dir_y * cos(game->player.rotation_s);

	game->player.plane_x = game->player.plane_x * cos(game->player.rotation_s) -
			game->player.plane_y * sin(game->player.rotation_s);
	game->player.plane_y = oldPlane_x * sin(game->player.rotation_s) +
			game->player.plane_y * cos(game->player.rotation_s);
}
