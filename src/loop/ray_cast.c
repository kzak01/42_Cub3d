#include "loop.h"

static void	_background(t_game *game)
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

static void	_init_math(t_math *math, t_game *game, int x)
{
	math->cameraX = 2 * x / (double)w_width - 1;
	math->rayDirX = game->player.dirX + game->player.planeX * math->cameraX;
	math->rayDirY = game->player.dirY + game->player.planeY * math->cameraX;
	math->mapX = (int)game->player.posX;
	math->mapY = (int)game->player.posY;
//La funzione fabs() della libreria math restituisce il valore assoluto
//(cioè il valore senza il segno) di un numero in virgola mobile, indipendentemente
//dal fatto che questo sia negativo o positivo. Ad esempio, fabs(-3.14) restituirebbe
//il valore 3.14, mentre fabs(2.71) restituirebbe il valore 2.71.
	math->deltaDistX = fabs(1 / math->rayDirX);
	math->deltaDistY = fabs(1 / math->rayDirY);
	math->hit = 0;
}

static void	_step_side(t_math *math, t_game *game)
{
	if(math->rayDirX < 0)
	{
		math->stepX = -1;
		math->sideDistX = (game->player.posX - math->mapX) * math->deltaDistX;
	}
	else
	{
		math->stepX = 1;
		math->sideDistX = (math->mapX + 1.0 - game->player.posX) * math->deltaDistX;
	}
	if(math->rayDirY < 0)
	{
		math->stepY = -1;
		math->sideDistY = (game->player.posY - math->mapY) * math->deltaDistY;
	}
	else
	{
		math->stepY = 1;
		math->sideDistY = (math->mapY + 1.0 - game->player.posY) * math->deltaDistY;
	}
}

static void	_wall_cast(t_game *game)
{
	t_math	math;
	int	x;
	int	y;

	// ft_bzero(&math, sizeof(t_math));
	x = -1;
	while (++x < w_width)
	{
		_init_math(&math, game, x);
		_step_side(&math, game);
		dda(&math, game);
		distance_ray(&math, game);
		calculate_pixel(&math, game);
		y = math.draw_start;
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
	_background(game);
	_wall_cast(game);
}
