#include "map.h"

static int	in_while(char *line, t_game *game)
{
	if (line == NULL)
		return (1);
	else if (ft_strncmp(line, "NO ", 3) == 0
			|| ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "EA ", 3) == 0
			|| ft_strncmp(line, "F ", 2) == 0
			|| ft_strncmp(line, "C ", 2) == 0)
	{
		free(line);
		return (0);
	}
	else
		if (get_info(line, game))
			return (2);
	free(line);
	return (0);
}

static int	take_w_h(const char *file_path, t_game *game)
{
	int		fd;
	char	*line;
	int		er;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (error("Failed to open file"));
	while (get_next_line(fd, &line) > 0)
	{
		er = in_while(line, game);
		if (er == 1)
			break;
		else if (er == 2)
		{
			free(line);
			return (1);
		}
	}
	free(line);
	if (close(fd) == -1)
		return (error("Failed to close file"));
	return (0);
}

static int	in_while2(char *line, t_game *game, int *line_num)
{
	if (line == NULL)
		return (0);
	if (check_texture(line, game))
		return (0);
	else if (check_color(line, game))
		return (0);
	else
	{
		if (ft_strlen(line) == 0 && game->map.map[0] != NULL)
			return (error("empty line in map!"));
		if (ft_strlen(line) == 0)
			return (0);
		if (check_other(game))
			return (1);
		read_map_line(line, game, ++*line_num, game->map.map_width);
		// printf("{%d}    %s\n", *line_num, game->map.control_map[*line_num]);
	}
	return (0);
}

static int	read_map(const char *file_path, t_game *game)
{
	int		fd;
	char	*line;
	int		line_num;
	int		err;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (error("Failed to open file"));
	line_num = -1;
	game->map.map = (char **)malloc(sizeof(char *) * game->map.map_height);
	game->map.map[0] = NULL;
	game->map.control_map = (char **)malloc(sizeof(char *) * game->map.map_height);
	game->map.control_map[0] = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		err = in_while2(line, game, &line_num);

		if (err == 1)
		{
			free(line);
			return (1);
		}
		else if (err == 2)
			break;
		free(line);
	}
	game->map.map[game->map.map_height] = NULL;
	game->map.control_map[game->map.map_height] = NULL;
	// printf("\nprima map%s\n", game->map.map[0]);
	// printf("prima con %s\n", game->map.control_map[0]);
	// printf("prima map%s\n", game->map.map[1]);
	// printf("prima con%s\n", game->map.control_map[1]);
	// ft_print_str_array(game->map.map);
	// ft_print_str_array(game->map.control_map);
	free(line);
	if (close(fd) == -1)
		return (error("Failed to close file"));
	return (0);
}

int	get_check_map(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (error("invalid number of argument"));
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4))
		return(error("file must have .cub extension"));
	if (take_w_h(av[1], game))
		return (1);
	if (read_map(av[1], game))
		return (1);
	if (check_rule(game))
		return (1);
	// if (check_map(game))
	// 	return (1);
	if (check_player(game) != 1)
		return (error("only 1 player allowed!"));
	game->map.map_int = char_to_int_map(game);
	return (0);
}
