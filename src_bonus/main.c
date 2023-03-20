/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:16:13 by kzak              #+#    #+#             */
/*   Updated: 2023/03/20 12:18:03 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	print_int_map(int **map_int, t_game *game)
// {
// 	for(int i = 0; i < game->map.map_height; i++)
// 	{
// 		for(int j = 0; j < game->map.map_width; j++)
// 		{
// 			printf("%d", map_int[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

static int	play_game(t_game *game)
{
	game->z_buff = (double *)malloc(sizeof(double) * W_WIDTH);
	game->mlx = mlx_init();
	if (load_textures(game))
		return (1);
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "Cub3d");
	game->img.img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_size, &game->img.endian);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, KEY_EXIT, 0, end_program, game);
	mlx_hook(game->win, KEY_PRESS, 0, key_press, game);
	mlx_hook(game->win, KEY_RELEASE, 0, key_release, game);
	mlx_hook(game->win, MOUSE_MOVE, 0, mouse_move, game);
	mlx_loop(game->mlx);
	return (0);
}

	// printf("n={%s}\ns={%s}\nw={%s}\ne={%s}\n"
	// 		"flor={%d}\nceil={%d}\nmap w={%d}\nmap h={%d}\n"
	// 		"posX={%f}\nposY={%f}\ndirection={%d}\n",
	// 		game.map.north_texture_path, game.map.south_texture_path,
	// 		game.map.west_texture_path, game.map.east_texture_path,
	// 		game.map.floor_color, game.map.ceiling_color,
	// 		game.map.map_width, game.map.map_height,
	// 		game.player.pos_x, game.player.pos_y, game.player.direction);

	// printf("-----------------char------------------------\n");
	// ft_print_str_array(game.map.map);
	// printf("-----------------cont------------------------\n");
	// ft_print_str_array(game.map.control_map);
	// printf("-----------------int-------------------------\n");
	// print_int_map(game.map.map_int, &game);

int	main(int argc, char **argv)
{
	t_game	game;

	if (init_struct(&game))
		return (error("can't init game struct!"));
	if (get_check_map(&game, argc, argv))
		end_program(&game);
	init_player(&game);
	if (play_game(&game))
		end_program(&game);
	end_program(&game);
	return (0);
}
