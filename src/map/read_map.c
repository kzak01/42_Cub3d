/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:07:58 by kzak              #+#    #+#             */
/*   Updated: 2023/03/21 16:01:38 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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
		if (!ft_strchr(line, '1'))
			return (error("the map is not surrounded by walls!"));
		if (check_other(game))
			return (1);
		read_map_line(line, game, ++*line_num, game->map.map_width);
	}
	return (0);
}

static int	read_lines(int fd, t_game *game, int *line_num)
{
	char	*line;
	int		err;

	while (get_next_line(fd, &line) > 0)
	{
		err = in_while2(line, game, line_num);
		if (err == 1)
		{
			free(line);
			return (1);
		}
		else if (err == 2)
		{
			free(line);
			break ;
		}
		free(line);
	}
	free(line);
	return (0);
}

static int	alloc_map(t_game *game, int *line_num)
{
	*line_num = -1;
	game->map.map = (char **)malloc(sizeof(char *)
			* game->map.map_height + 1);
	if (!game->map.map)
		return (1);
	game->map.map[0] = NULL;
	game->map.control_map = (char **)malloc(sizeof(char *)
			* game->map.map_height + 1);
	if (!game->map.control_map)
		return (1);
	game->map.control_map[0] = NULL;
	return (0);
}

int	read_map(const char *file_path, t_game *game)
{
	int	fd;
	int	line_num;

	fd = open_file(file_path);
	if (alloc_map(game, &line_num))
		return (1);
	if (read_lines(fd, game, &line_num))
		return (1);
	game->map.map[game->map.map_height] = NULL;
	game->map.control_map[game->map.map_height] = NULL;
	if (close_file(fd))
		return (1);
	return (0);
}
