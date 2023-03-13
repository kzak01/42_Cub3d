/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:16:13 by kzak              #+#    #+#             */
/*   Updated: 2023/03/13 19:01:08 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_int_map(int **map_int, int rows, int cols)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (j < cols)
			printf("%d", map_int[i][j]);
		printf("\n");
	}
}

	// printf("n={%s}\ns={%s}\nw={%s}\ne={%s}\n"
	// 		"flor={%d}\nceil={%d}\nmap w={%d}\nmap h={%d}\n"
	// 		"posX={%f}\nposY={%f}\ndirection={%d}\n",
	// 		game.map.north_texture_path, game.map.south_texture_path,
	// 		game.map.west_texture_path, game.map.east_texture_path,
	// 		game.map.floor_color, game.map.ceiling_color,
	// 		game.map.map_width, game.map.map_height,
	// 		game.player_x, game.player.pos_y, game.player.direction);

	// printf("-----------------char------------------------\n");
	// ft_print_str_array(game.map.map);
	// printf("-----------------cont------------------------\n");
	// ft_print_str_array(game.map.control_map);
	// printf("-----------------int-------------------------\n");
	// print_int_map(game.map.map_int, game.map.map_height, game.map.map_width);


int	mouse_move(int x, int y, t_game *game)
{
	if (game->mouse_active)
	{
		int diff_x = x - game->player.mouse_x;
		game->player.mouse_x = x;
		double rot_speed = diff_x * game->player.rotation_s;
		double old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
		game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y * cos(rot_speed);
		double old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
		game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
	}
	return (0);
}

void	unlock_mouse(t_game *game)
{
	game->mouse_active = false;
	mlx_mouse_show();
}

void	lock_mouse(t_game *game)
{
	game->mouse_locked = true;
	mlx_mouse_hide();
	game->player.mouse_x = W_WIDTH / 2;
	game->player.mouse_y = W_HEIGHT / 2;
	mlx_mouse_move(game->win, game->player.mouse_x, game->player.mouse_y);
}

int	mouse_toggle(int keycode, t_game *game)
{
	if (keycode == KEY_Z)
	{
		game->mouse_active = !game->mouse_active;
		if (game->mouse_active)
			lock_mouse(game);
		else
			unlock_mouse(game);
	}
	return (0);
}

void	hide_mouse(t_game *game)
{
	mlx_mouse_hide();
	game->mouse_x = W_WIDTH / 2;
	game->mouse_y = W_HEIGHT / 2;
	mlx_mouse_move(game->win, mouse_x, mouse_y);
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
	mlx_loop(game.mlx);
	free_exit(&game);
	return (0);
}
