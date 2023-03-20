/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:22 by kzak              #+#    #+#             */
/*   Updated: 2023/03/20 11:47:09 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	init_struct(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->buff = (int **)malloc(sizeof(int *) * W_HEIGHT);
	if (!game->buff)
		return (error("malloc buff problem!"));
	while (++i < W_HEIGHT)
	{
		game->buff[i] = (int *)malloc(sizeof(int) * W_WIDTH);
		j = -1;
		while (++j < W_WIDTH)
			game->buff[i][j] = 0;
	}
	ft_bzero(&game->map, sizeof(t_map));
	ft_bzero(&game->img, sizeof(t_img));
	ft_bzero(&game->key, sizeof(t_key));
	ft_bzero(&game->player, sizeof(t_player));
	return (0);
}

static void	_buff_init(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < W_HEIGHT)
	{
		j = -1;
		while (++j < W_WIDTH)
			game->buff[i][j] = 0;
	}
}

static void	_direction_init1(t_game *game)
{
	if (game->player.direction == NORTH)
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
	else if (game->player.direction == SOUTH)
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
}

static void	_direction_init2(t_game *game)
{
	if (game->player.direction == WEST)
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->player.direction == EAST)
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
}

void	init_player(t_game *game)
{
	_buff_init(game);
	_direction_init1(game);
	_direction_init2(game);
	game->player.movement_s = 0.05;
	game->player.rotation_s = 0.04;
}
