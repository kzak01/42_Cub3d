#include "map.h"

int	check_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map.control_map[++y] && y < game->map.map_height - 1)
	{
		x = -1;
		// printf("%s\n", game->map.control_map[y]);
		while (game->map.control_map[y][++x])
		{
			if (game->map.control_map[y][x] != '1'
				&& game->map.control_map[y][x] != ' '
				&& (y == 0 || x == 0
				|| !game->map.control_map[y][x + 1]
				|| game->map.control_map[y + 1] == NULL
				|| game->map.control_map[y - 1][x] == ' '
				|| game->map.control_map[y + 1][x] == ' '
				|| game->map.control_map[y][x - 1] == ' '
				|| game->map.control_map[y][x + 1] == ' '))
				return (error("map must be close!"));
		}
	}
	if (ft_strspn(game->map.control_map[y], "1 ") != ft_strlen(game->map.control_map[y]))
		return (error("map must be close!"));
	return (0);
}

int	**char_to_int_map(t_game *game)
{
	int	**map_int;
	int	x;
	int	y;

	map_int = (int **)malloc(sizeof(int *) * game->map.map_height);
	y = -1;
	while (++y < game->map.map_height)
	{
		x = -1;
		map_int[y] = (int *)malloc(sizeof(int) * game->map.map_width);
		while (++x < game->map.map_width)
		{
			if (game->map.map[y][x] == '1')
				map_int[y][x] = 1;
			else
				map_int[y][x] = 0;
		}
	}
	return (map_int);
}
