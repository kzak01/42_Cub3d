/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:08:40 by kzak              #+#    #+#             */
/*   Updated: 2023/03/14 11:45:06 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int	key_press(int key, t_game *game)
{
	if (key == K_ESC)
		game->key.key_esc = 1;
	else if (key == K_K_W)
		game->key.key_up = 1;
	else if (key == K_K_S)
		game->key.key_down = 1;
	else if (key == K_K_A)
		game->key.key_left = 1;
	else if (key == K_K_D)
		game->key.key_right = 1;
	else if (key == K_AR_R)
		game->key.key_rotate_r = 1;
	else if (key == K_AR_L)
		game->key.key_rotate_l = 1;
	else if (key == K_K_Z)
		game->mouse.mouse_active = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == K_ESC)
		game->key.key_esc = 0;
	else if (key == K_K_W)
		game->key.key_up = 0;
	else if (key == K_K_S)
		game->key.key_down = 0;
	else if (key == K_K_A)
		game->key.key_left = 0;
	else if (key == K_K_D)
		game->key.key_right = 0;
	else if (key == K_AR_R)
		game->key.key_rotate_r = 0;
	else if (key == K_AR_L)
		game->key.key_rotate_l = 0;
	else if (key == K_K_Z)
		game->mouse.mouse_active = 0;
	return (0);
}

void	unlock_mouse(t_game *game)
{
	mlx_mouse_show(game->mlx, game->win);
}

void	lock_mouse(t_game *game)
{
	// mlx_mouse_hide(game->mlx, game->win);
	game->mouse.mouse_x = W_WIDTH / 2;
	game->mouse.mouse_y = W_HEIGHT / 2;
	// mlx_mouse_move(game->mlx, game->win, game->mouse.mouse_x, game->mouse.mouse_y);
}

void	mouse_toggle(t_game *game)
{
	if (game->mouse.mouse_active)
		lock_mouse(game);
	else
		unlock_mouse(game);
}

void	key_used(t_game *game)
{
	if (game->key.key_up)
		move_up(game);
	if (game->key.key_down)
		move_behind(game);
	if (game->key.key_right)
		move_right(game);
	if (game->key.key_left)
		move_left(game);
	if (game->key.key_rotate_r)
		rotate_right(game);
	if (game->key.key_rotate_l)
		rotate_left(game);
	if (game->key.key_esc)
	{
		free_exit(game);
		exit(0);
	}
	mouse_toggle(game);
}
