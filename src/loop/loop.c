#include "loop.h"

static void	_draw_img(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < w_height)
	{
		x = -1;
		while (++x < w_width)
			game->img.data[y * w_width + x] = game->buff[y][x];
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int	game_loop(t_game *game)
{
	ray_cast(game);
	_draw_img(game);
	key_used(game);
	return (0);
}
