/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:37:20 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 14:17:48 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

static void	door_up_down(t_game *game)
{
	if (game->map.map[(int)game->player.pos_x + 1]
		[(int)game->player.pos_y] == '2')
	{
		if (game->map.map_int[(int)game->player.pos_x + 1]
			[(int)game->player.pos_y] == 2)
			game->map.map_int[(int)game->player.pos_x + 1]
			[(int)game->player.pos_y] = 0;
		else
			game->map.map_int[(int)game->player.pos_x + 1]
			[(int)game->player.pos_y] = 2;
		game->key.door_press = 1;
	}
	if (game->map.map[(int)game->player.pos_x - 1]
		[(int)game->player.pos_y] == '2')
	{
		if (game->map.map_int[(int)game->player.pos_x - 1]
			[(int)game->player.pos_y] == 2)
			game->map.map_int[(int)game->player.pos_x - 1]
			[(int)game->player.pos_y] = 0;
		else
			game->map.map_int[(int)game->player.pos_x - 1]
			[(int)game->player.pos_y] = 2;
		game->key.door_press = 1;
	}
}

static void	door_right_left(t_game *game)
{
	if (game->map.map[(int)game->player.pos_x]
		[(int)game->player.pos_y + 1] == '2')
	{
		if (game->map.map_int[(int)game->player.pos_x]
			[(int)game->player.pos_y + 1] == 2)
			game->map.map_int[(int)game->player.pos_x]
			[(int)game->player.pos_y + 1] = 0;
		else
			game->map.map_int[(int)game->player.pos_x]
			[(int)game->player.pos_y + 1] = 2;
		game->key.door_press = 1;
	}
	if (game->map.map[(int)game->player.pos_x]
		[(int)game->player.pos_y - 1] == '2')
	{
		if (game->map.map_int[(int)game->player.pos_x]
			[(int)game->player.pos_y - 1] == 2)
			game->map.map_int[(int)game->player.pos_x]
			[(int)game->player.pos_y - 1] = 0;
		else
			game->map.map_int[(int)game->player.pos_x]
			[(int)game->player.pos_y - 1] = 2;
		game->key.door_press = 1;
	}
}

void	door_o_c(t_game *game)
{
	if (!game->key.door_press)
	{
		door_up_down(game);
		door_right_left(game);
	}
}
