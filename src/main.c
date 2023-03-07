#include "main.h"

void	print_int_map(int **map_int, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d", map_int[i][j]);
		}
		printf("\n");
	}
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
	printf("n={%s}\ns={%s}\nw={%s}\ne={%s}\n"
			"flor={%d}\nceil={%d}\nmap w={%d}\nmap h={%d}\n"
			"posX={%f}\nposY={%f}\ndirection={%d}\n",
			game.map.north_texture_path, game.map.south_texture_path,
			game.map.west_texture_path, game.map.east_texture_path,
			game.map.floor_color, game.map.ceiling_color,
			game.map.map_width, game.map.map_height,
			game.player.posX, game.player.posY, game.player.direction);

	printf("-----------------char------------------------\n");
	ft_print_str_array(game.map.map);
	printf("-----------------int-------------------------\n");
	print_int_map(game.map.map_int, game.map.map_height, game.map.map_width);
	// ft_print_str_array(game.map.control_map);

	if (load_textures(&game))
		return (1);

	game.win = mlx_new_window(game.mlx, w_width, w_height, "Cub3d");
	game.img.img = mlx_new_image(game.mlx, w_width, w_height);
	game.img.data = (int *)mlx_get_data_addr(game.img.img, &game.img.bpp,
						&game.img.line_size, &game.img.endian);

	// game.player.posX = 3.0;
	// game.player.posY = 3.0;
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, KEY_EXIT, 0, end_program, &game);
	mlx_hook(game.win, KEY_PRESS, 0, key_press, &game);
	mlx_hook(game.win, KEY_RELEASE, 0, key_release, &game);
	mlx_loop(game.mlx);
	// free_exit(&game);
	return(0);
}
