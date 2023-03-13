/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:08:46 by kzak              #+#    #+#             */
/*   Updated: 2023/03/13 14:12:33 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void	move_up(t_game *game)
{
	if (!game->map.map_int[(int)(game->player.pos_x + game->player.dir_x
			* game->player.movement_s)][(int)game->player.pos_y])
		game->player.pos_x += game->player.dir_x * game->player.movement_s;
	if (!game->map.map_int[(int)game->player.pos_x]
		[(int)(game->player.pos_y + game->player.dir_y
			* game->player.movement_s)])
		game->player.pos_y += game->player.dir_y * game->player.movement_s;
}

void	move_behind(t_game *game)
{
	if (!game->map.map_int[(int)(game->player.pos_x - game->player.dir_x
			* game->player.movement_s)][(int)game->player.pos_y])
		game->player.pos_x -= game->player.dir_x * game->player.movement_s;
	if (!game->map.map_int[(int)game->player.pos_x]
		[(int)(game->player.pos_y - game->player.dir_y
			* game->player.movement_s)])
		game->player.pos_y -= game->player.dir_y * game->player.movement_s;
}

void	move_right(t_game *game)
{
	double	dirx;
	double	diry;

	dirx = -game->player.dir_y;
	diry = game->player.dir_x;
	if (!game->map.map_int[(int)(game->player.pos_x - dirx
			* game->player.movement_s)][(int)game->player.pos_y])
		game->player.pos_x -= dirx * game->player.movement_s;
	if (!game->map.map_int[(int)game->player.pos_x]
		[(int)(game->player.pos_y - diry * game->player.movement_s)])
		game->player.pos_y -= diry * game->player.movement_s;
}

void	move_left(t_game *game)
{
	double	dirx;
	double	diry;

	dirx = game->player.dir_y;
	diry = -game->player.dir_x;
	if (!game->map.map_int[(int)(game->player.pos_x - dirx
			* game->player.movement_s)][(int)game->player.pos_y])
		game->player.pos_x -= dirx * game->player.movement_s;
	if (!game->map.map_int[(int)game->player.pos_x]
		[(int)(game->player.pos_y - diry * game->player.movement_s)])
		game->player.pos_y -= diry * game->player.movement_s;
}
