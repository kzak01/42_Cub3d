#include "utils.h"

// void	free_map(t_game *game)
// {
// 	int	i;
// 	if (game->map.map && game->map.map[0] == NULL)
// 		return ;
// 	else if (game->map.map && game->map.map[0] != NULL)
// 	{
// 		i = -1;
// 		while (++i < game->map.read_line)
// 			free(game->map.map[i]);
// 	}
// }

// void	free_map2(t_game *game)
// {
// 	int	i;

// 	if (game->map.control_map && game->map.control_map[0] == NULL)
// 		return ;
// 	else if (game->map.control_map && game->map.control_map[0] != NULL)
// 	{
// 		i = -1;
// 		while (++i < game->map.read_line)
// 			free(game->map.control_map[i]);
// 	}
// }

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map.map_int)
		return ;
	while (i < game->map.read_line)
	{
		if (game->map.map_int[i])
			free(game->map.map_int[i]);
		i++;
	}
	free(game->map.map_int);
}

void	free_exit(t_game *game)
{
	int i;

	i = -1;
	while (++i < w_height)
		free(game->buff[i]);
	free(game->buff);
	ft_free_char_array(game->map.map, game->map.read_line);
	ft_free_char_array(game->map.control_map, game->map.read_line);
	free_map(game);
	free(game->map.east_texture_path);
	free(game->map.north_texture_path);
	free(game->map.south_texture_path);
	free(game->map.west_texture_path);
}

void	end_program(t_game *game)
{
	free_exit(game);
	exit(0);
}
