/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:02:22 by kzak              #+#    #+#             */
/*   Updated: 2023/03/15 10:34:10 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int	mouse_move(int x, int y, t_game *game)
{
	int		diff_x;
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	(void)y;
	if (game->mouse.mouse_active)
	{
		diff_x = x - game->mouse.mouse_x;
		old_dir_x = game->player.dir_x;
		old_plane_x = game->player.plane_x;
		rot_speed = (diff_x * game->player.rotation_s) / 900;
		game->mouse.mouse_x = x;
		game->player.dir_x = game->player.dir_x * cos(rot_speed)
			- game->player.dir_y * sin(rot_speed);
		game->player.dir_y = old_dir_x * sin(rot_speed)
			+ game->player.dir_y * cos(rot_speed);
		game->player.plane_x = game->player.plane_x * cos(rot_speed)
			- game->player.plane_y * sin(rot_speed);
		game->player.plane_y = old_plane_x * sin(rot_speed)
			+ game->player.plane_y * cos(rot_speed);
	}
	return (0);
}

static void	_unlock_mouse(t_game *game)
{
	mlx_mouse_show(game->mlx, game->win);
}

	// mlx_mouse_hide(game->mlx, game->win);
	// mlx_mouse_move(game->mlx, game->win, game->mouse.mouse_x, game->mouse.mouse_y);
static void	_lock_mouse(t_game *game)
{
	game->mouse.mouse_x = W_WIDTH / 2;
	game->mouse.mouse_y = W_HEIGHT / 2;
}

void	mouse_toggle(t_game *game)
{
	if (game->mouse.mouse_active)
		_lock_mouse(game);
	else
		_unlock_mouse(game);
}
