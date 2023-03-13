/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:16:13 by kzak              #+#    #+#             */
/*   Updated: 2023/03/13 13:31:56 by kzak             ###   ########.fr       */
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
