#include "map.h"

static void	_get_direction(t_game *game, char c)
{
	if (c == 'N')
		game->player.direction = NORTH;
	else if (c == 'S')
		game->player.direction = SOUTH;
	else if (c == 'W')
		game->player.direction = WEST;
	else if (c == 'E')
		game->player.direction = EAST;
}

int	check_player(t_game *game)
{
	int	x;
	int	y;
	int	n_player;

	n_player = 0;
	y = -1;
	while (game->map.map[++y] && y < game->map.map_height)
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == 'N'
				|| game->map.map[y][x] == 'S'
				|| game->map.map[y][x] == 'W'
				|| game->map.map[y][x] == 'E')
			{
				_get_direction(game, game->map.map[y][x]);
				n_player++;
				game->player.pos_x = y + 0.5;
				game->player.pos_y = x + 0.5;
				game->map.map[y][x] = '0';
			}
		}
	}
	return (n_player);
}
