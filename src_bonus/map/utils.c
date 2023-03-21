/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:32 by kzak              #+#    #+#             */
/*   Updated: 2023/03/21 15:48:09 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	read_texture_path(char *line, char **texture_path_ptr)
{
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

static int	_check_color_validity(char *color)
{
	int	i;
	int	comma;

	i = 1;
	comma = 0;
	while (color[++i])
	{
		if (color[i] == ',')
			comma++;
		if (!ft_isdigit(color[i]) && color[i] != ',')
			return (error("only number in color!"));
		if (color[i] == ' ')
			return (error("space in color!"));
	}
	if (comma != 2)
		return (error("why so many ','?"));
	return (0);
}

int	convert_color_to_int(char *color)
{
	char	**split;
	int		r;
	int		g;
	int		b;
	int		color_int;

	if (_check_color_validity(color))
		return (1);
	split = ft_split(color + 2, ',');
	if (split == NULL || ft_str_array_len(split) != 3)
	{
		ft_free_char_array(split, ft_str_array_len(split));
		return (error("something wrong in color!"));
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_free_char_array(split, ft_str_array_len(split));
		return (error("something wrong in color!"));
	}
	color_int = (r << 16) | (g << 8) | b;
	ft_free_char_array(split, ft_str_array_len(split));
	return (color_int);
}

void	read_map_line(char *line, t_game *game, int line_index,
	int map_width_ptr)
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
