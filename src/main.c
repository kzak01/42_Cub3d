/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:16:13 by kzak              #+#    #+#             */
/*   Updated: 2023/03/14 11:27:27 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (game->mouse.mouse_active)
	{
		int diff_x = x - game->mouse.mouse_x;
		game->mouse.mouse_x = x;
		double rot_speed = (diff_x * game->player.rotation_s) / 900;
		double old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
		game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y * cos(rot_speed);
		double old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
		game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (init_struct(&game))
		return (error("can't init game struct!"));
	if (get_check_map(&game, argc, argv))
	{
		free_exit(&game);
		return (1);
	}
	init_player(&game);
	game.mlx = mlx_init();
	if (load_textures(&game))
		return (1);
	game.win = mlx_new_window(game.mlx, W_WIDTH, W_HEIGHT, "Cub3d");
	game.img.img = mlx_new_image(game.mlx, W_WIDTH, W_HEIGHT);
	game.img.data = (int *)mlx_get_data_addr(game.img.img, &game.img.bpp,
			&game.img.line_size, &game.img.endian);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, KEY_EXIT, 0, end_program, &game);
	mlx_hook(game.win, KEY_PRESS, 0, key_press, &game);
	mlx_hook(game.win, KEY_RELEASE, 0, key_release, &game);
	mlx_hook(game.win, 6, 0, mouse_move, &game);
	mlx_loop(game.mlx);
	free_exit(&game);
	return (0);
}
