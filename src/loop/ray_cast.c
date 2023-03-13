#include "loop.h"

void	background(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < w_height)
	{
		x = -1;
		while (++x < w_width)
		{
			if (y < (w_height / 2))
				game->buff[y][x] = game->map.ceiling_color;
			else
				game->buff[y][x] = game->map.floor_color;;
		}
	}
}

void	init_math(t_math *math, t_game *game, int x)
{
	math->cameraX = 2 * x / (double)w_width - 1;
	math->rayDirX = game->player.dirX + game->player.planeX * math->cameraX;
	math->rayDirY = game->player.dirY + game->player.planeY * math->cameraX;
	math->mapX = (int)game->player.posX;
	math->mapY = (int)game->player.posY;
	math->deltaDistX = fabs(1 / math->rayDirX);
	math->deltaDistY = fabs(1 / math->rayDirY);
	math->hit = 0;
}

//Digital Differential Analysis
void	dda(t_math *math, t_game *game)
{
	while (math->hit == 0)
	{
		if(math->sideDistX < math->sideDistY)
		{
			math->sideDistX += math->deltaDistX;
			math->mapX += math->stepX;
			math->side = 0;
		}
		else
		{
			math->sideDistY += math->deltaDistY;
			math->mapY += math->stepY;
			math->side = 1;
		}
		if(game->map.map_int[math->mapX][math->mapY] > 0) math->hit = 1;
	}
}

void	wall_cast(t_game *game)
{
	t_math	math;
	int	x;
	int	y;

	// ft_bzero(&math, sizeof(t_math));
	x = -1;
	while (++x < w_width)
	{
		init_math(&math, game, x);
		step_side(&math, game);
		dda(&math, game);
		distance_ray(&math, game);
		calculate_pixel(&math, game);
		y = math.draw_start ;
		while (y < math.draw_end)
		{
			math.texY = (int)math.texPos & (texture_size - 1);
			math.texPos += math.step;
			math.color = game->text[math.tex_n][texture_size * math.texY + math.texX];
			game->buff[y][x] = math.color;
			y++;
		}
	}
}

void	ray_cast(t_game *game)
{
	background(game);
	wall_cast(game);
}
