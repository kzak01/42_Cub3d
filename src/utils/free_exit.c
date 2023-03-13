#include "utils.h"

void	free_exit(t_game *game)
{
	int i;

	i = -1;
	while (++i < W_HEIGHT)
		free(game->buff[i]);
	free(game->buff);
	ft_free_char_array(game->map.map, game->map.read_line);
	ft_free_char_array(game->map.control_map, game->map.read_line);
	ft_free_int_array(game->map.map_int, game->map.read_line);
	ft_free_int_array(game->text, 4);
	free(game->map.east_texture_path);
	free(game->map.north_texture_path);
	free(game->map.south_texture_path);
	free(game->map.west_texture_path);
}

int	end_program(t_game *game)
{
	free_exit(game);
	exit(0);
}
