/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:28 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 11:55:39 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	fd = open_file(file_path);
	if (fd == -1)
		return (1);
	while (get_next_line(fd, &line) > 0)
	{
		er = in_while(line, game);
		if (er == 1)
			break ;
		else if (er == 2)
		{
			free(line);
			return (1);
		}
	}
	free(line);
	if (close_file(fd))
		return (1);
	return (0);
}

int	get_check_map(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (error("invalid number of argument"));
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4))
		return (error("file must have .cub extension"));
	if (take_w_h(av[1], game))
		return (1);
	if (read_map(av[1], game))
		return (1);
	if (check_rule(game))
		return (1);
	if (check_map(game))
		return (1);
	if (check_player(game) != 1)
		return (error("only 1 player allowed!"));
	get_sprites_pos(game);
	game->map.map_int = char_to_int_map(game);
	return (0);
}
