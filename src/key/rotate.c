/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:08:51 by kzak              #+#    #+#             */
/*   Updated: 2023/03/13 14:14:14 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void	rotate_right(t_game *game)
{
	double	old_dirx;
	double	oldplane_x;

	old_dirx = game->player.dir_x;
	oldplane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(-game->player.rotation_s)
		- game->player.dir_y * sin(-game->player.rotation_s);
	game->player.dir_y = old_dirx * sin(-game->player.rotation_s)
		+ game->player.dir_y * cos(-game->player.rotation_s);
	game->player.plane_x = game->player.plane_x * cos(-game->player.rotation_s)
		- game->player.plane_y * sin(-game->player.rotation_s);
	game->player.plane_y = oldplane_x * sin(-game->player.rotation_s)
		+ game->player.plane_y * cos(-game->player.rotation_s);
}

void	rotate_left(t_game *game)
{
	double	old_dirx;
	double	oldplane_x;

	old_dirx = game->player.dir_x;
	oldplane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(game->player.rotation_s)
		- game->player.dir_y * sin(game->player.rotation_s);
	game->player.dir_y = old_dirx * sin(game->player.rotation_s)
		+ game->player.dir_y * cos(game->player.rotation_s);
	game->player.plane_x = game->player.plane_x * cos(game->player.rotation_s)
		- game->player.plane_y * sin(game->player.rotation_s);
	game->player.plane_y = oldplane_x * sin(game->player.rotation_s)
		+ game->player.plane_y * cos(game->player.rotation_s);
}
