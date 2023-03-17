/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varius_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:35 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 11:58:33 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_rule(t_game *game)
{
	if (game->map.north != 1
		|| game->map.south != 1
		|| game->map.west != 1
		|| game->map.east != 1
		|| game->map.floor != 1
		|| game->map.ceil != 1
		|| game->map.map_width == 0
		|| game->map.map_height == 0)
		return (error("Missing or invalid map data"));
	return (0);
}

int	check_other(t_game *game)
{
	if (game->map.north != 1
		|| game->map.south != 1
		|| game->map.west != 1
		|| game->map.east != 1
		|| game->map.floor != 1
		|| game->map.ceil != 1
		|| game->map.ceiling_color == 1
		|| game->map.floor_color == 1)
		return (error("some rule are wrong!"));
	return (0);
}

int	check_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		read_texture_path(line, &game->map.north_texture_path);
		game->map.north++;
		return (1);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		read_texture_path(line, &game->map.south_texture_path);
		game->map.south++;
		return (1);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		read_texture_path(line, &game->map.west_texture_path);
		game->map.west++;
		return (1);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		read_texture_path(line, &game->map.east_texture_path);
		game->map.east++;
		return (1);
	}
	return (0);
}

int	check_color(char *line, t_game *game)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		game->map.floor_color = convert_color_to_int(line);
		game->map.floor++;
		return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		game->map.ceiling_color = convert_color_to_int(line);
		game->map.ceil++;
		return (1);
	}
	return (0);
}
