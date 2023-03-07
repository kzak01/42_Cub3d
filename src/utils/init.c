#include "utils.h"

int	init_struct(t_game *game)
{
	int	i;
	int j;

	i = -1;
	game->mlx = mlx_init();
	game->text = NULL;
	game->buff = (int **)malloc(sizeof(int *) * w_height);
	if (!game->buff)
		return (error("malloc buff problem!"));
	while (++i < w_height)
	{
		game->buff[i] = (int *)malloc(sizeof(int) * w_width);
		j = -1;
		while (++j < w_width)
			game->buff[i][j] = 0;
	}
	ft_bzero(&game->map, sizeof(t_map));
	ft_bzero(&game->img, sizeof(t_img));
	ft_bzero(&game->key, sizeof(t_key));
	ft_bzero(&game->player, sizeof(t_player));
	return (0);
}

static void	_buff_init(t_game *game)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while(++i < w_height)
	{
		while(++j < w_width)
			game->buff[i][j] = 0;
	}
}

static void	_direction_init1(t_game *game)
{
	if (game->player.direction == NORTH)
	{
		game->player.dirX = -1.0;
		game->player.dirY = 0.0;
		game->player.planeX = 0.0;
		game->player.planeY = 0.66;
	}
	else if (game->player.direction == SOUTH)
	{
		game->player.dirX = 1.0;
		game->player.dirY = 0.0;
		game->player.planeX = 0.0;
		game->player.planeY = -0.66;
	}
}

static void	_direction_init2(t_game *game)
{
	if (game->player.direction == WEST)
	{
		game->player.dirX = 0.0;
		game->player.dirY = -1.0;
		game->player.planeX = -0.66;
		game->player.planeY = 0.0;
	}
	else if (game->player.direction == EAST)
	{
		game->player.dirX = 0.0;
		game->player.dirY = 1.0;
		game->player.planeX = 0.66;
		game->player.planeY = 0.0;
	}
}

void	init_player(t_game *game)
{
	_buff_init(game);
	_direction_init1(game);
	_direction_init2(game);
	game->player.movementS = 0.07;
	game->player.rotationS = 0.07;
}
