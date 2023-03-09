#include "map.h"

void	read_texture_path(char *line, char **texture_path_ptr)
{
	// printf("line ======== {%s}\n", line);
	char	*text;

	text = ft_strtrim(line + 2, " \t");
	if (!*text)
		error("Invalid texture path found");
	if (*texture_path_ptr)
	{
		free(*texture_path_ptr);
		error("Duplicate texture path found");
	}
	*texture_path_ptr = text;
}

int	convertColorToInt(char* color)
{
	char	**split;
	int		R;
	int		G;
	int		B;
	int		color_int;

	split = ft_split(color + 2, ',');
	if (split == NULL || ft_str_array_len(split) != 3)
		return (error("something wrong in color!"));
	R = ft_atoi(split[0]);
	G = ft_atoi(split[1]);
	B = ft_atoi(split[2]);
	if (R < 0 || R > 255 || G < 0 || G > 255 || B < 0 || B > 255)
	{
		ft_free_char_array(split, ft_str_array_len(split));
		return (error("something wrong in color!"));
	}
	color_int = (R << 16) | (G << 8) | B;
	ft_free_char_array(split, ft_str_array_len(split));
	return (color_int);
}

void	read_map_line(char *line, t_game *game, int line_index, int map_width_ptr)
{
	size_t	line_len;
	char	*padded_line;

	line_len = ft_strlen(line);
	game->map.control_map[line_index] = ft_strdup(line);
	if ((int)line_len < map_width_ptr)
	{
		padded_line = malloc(map_width_ptr + 1);
		if (!padded_line)
			error("Failed to allocate memory for padded line");
		ft_memcpy(padded_line, line, line_len);
		ft_memset(padded_line + line_len, '1', map_width_ptr - line_len);
		padded_line[map_width_ptr] = '\0';
		ft_strreplace(padded_line, ' ', '1');
		ft_strreplace(padded_line, '\t', '1');
		game->map.map[line_index] = padded_line;
		line = padded_line;
	}
	else
		game->map.map[line_index] = ft_strdup(line);
	game->map.read_line++;
}

int	get_info(char *line, t_game *game)
{
	int	c;
	int	column;

	c = -1;
	while (line[++c])
	{
		if (!ft_strchr(MAP_CHARS, line[c]))
			return (error("invalid char!"));
	}
	column = ft_strlen(line);
	if (column > game->map.map_width)
		game->map.map_width = column;
	if (ft_strlen(line) > 0)
		game->map.map_height++;
	return (0);
}
