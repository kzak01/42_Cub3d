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

typedef struct s_math
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;

	int		lineH;
	int		draw_start;
	int		draw_end;
	int		tex_n;
	double	wall_x;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
	int		color;
}	t_math;

void	init_math(t_math *math, t_game *game, int x)
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

void	step_side(t_math *math, t_game *game)
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

//Digital Differential Analysis
void	dda(t_math *math, t_game *game)
{
	while (math->hit == 0)
	{
		if (math->sideDistX < math->sideDistY)
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
		if (game->map.map_int[math->mapX][math->mapY] > 0)
			math->hit = 1;
	}
}

void	distance_ray(t_math *math, t_game *game)
{
	if (math->side == 0)
	{
		math->perpWallDist = (math->mapX - game->player.posX +
				(1 - math->stepX) / 2) / math->rayDirX;
	}
	else
	{
		math->perpWallDist = (math->mapY - game->player.posY +
				(1 - math->stepY) / 2) / math->rayDirY;
	}
}

int	side_wall(t_math *math, t_game *game)
{
	if (math->side == 0)
		return (game->player.posY + math->perpWallDist * math->rayDirY);
	else
		return (game->player.posX + math->perpWallDist * math->rayDirX);
}

void	calculate_pixel(t_math *math, t_game *game)
{
	math->lineH = (int)(w_height / math->perpWallDist);
	math->draw_start = -math->lineH / 2 + w_height / 2;
	if (math->draw_start < 0)
		math->draw_start = 0;
	math->draw_end = math->lineH / 2 + w_height / 2;
	if (math->draw_end >= w_height)
		math->draw_end = w_height - 1;
	math->tex_n = game->map.map_int[math->mapX][math->mapY] - 1;
	math->wall_x = side_wall(math, game);
	//La funzione floor() della libreria math.h in C restituisce il più 
	//grande numero intero non superiore al valore passato come argomento. 
	//In altre parole, arrotonda un numero decimale verso il basso per
	//ottenere il numero intero più vicino alla radice inferiore. 
	//Ad esempio, floor(2.8) restituisce 2, floor(-2.8) restituisce -3
	math->wall_x -= floor(math->wall_x);
	math->texX = (int)(math->wall_x * (double)texture_size);
	if (math->side == 0 && math->rayDirX > 0)
		math->texX = texture_size - math->texX - 1;
	if (math->side == 1 && math->rayDirY < 0)
		math->texX = texture_size - math->texX - 1;
	math->step = 1.0 * texture_size / math->lineH;
	math->texPos = (math->draw_start - w_height / 2 + math->lineH / 2) * math->step;
}

void	wall_cast(t_game *game)
{
	t_math	math;
	int	x;
	int	y;

	ft_bzero(&math, sizeof(t_math));
	x = -1;
	while (++x < w_width)
	{
		init_math(&math, game, x);
		step_side(&math, game);
		dda(&math, game);
		distance_ray(&math, game);
		calculate_pixel(&math, game);
		y = math.draw_start;
		while (y < math.draw_end)
		{
			math.texY = (int)math.texPos & (texture_size - 1);
			math.texPos += math.step;
			// math.color = game->text[math.tex_n][texture_size * math.texY + math.texX];
			math.color = 0xFF0000;
			if (math.side == 1)
				math.color = (math.color >> 1) & 8355711;
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
