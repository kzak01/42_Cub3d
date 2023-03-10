#include "loop.h"

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

static int	_side_wall(t_math *math, t_game *game)
{
	if (math->side == 0)
		return (game->player.posY + math->perpWallDist * math->rayDirY);
	else
		return (game->player.posX + math->perpWallDist * math->rayDirX);
}

static int	_find_texture(t_math *math)
{
	int	tex_n;

	if (math->side == 0 && math->rayDirX < 0)
		tex_n = NORTH;
	else if (math->side == 0 && math->rayDirX >= 0)
		tex_n = SOUTH;
	else if (math->side == 1 && math->rayDirY < 0)
		tex_n = EAST;
	else
		tex_n = WEST;
	// if (game->map.map_int[math->mapX][math->mapY] == 2)
	// 	tex_n += 4;
	// else if (game->map.map_int[math->mapX][math->mapY] == 3)
	// 	tex_n += 8;
	// else if (game->map.map_int[math->mapX][math->mapY] == 4)
	// 	tex_n += 12;
	return (tex_n);
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
	math->tex_n = _find_texture(math);
	math->wall_x = _side_wall(math, game);
	//La funzione floor() della libreria math.h in C restituisce il più 
	//grande numero intero non superiore al valore passato come argomento. 
	//In altre parole, arrotonda un numero decimale verso il basso per
	//ottenere il numero intero più vicino alla radice inferiore. 
	//Ad esempio, floor(2.8) restituisce 2, floor(-2.8) restituisce -3
	math->wall_x -= floor(math->wall_x);
	math->texX = (int)(math->wall_x * (double)texture_size);
	math->texX = texture_size - math->texX - 1;
	math->step = 1.0 * texture_size / math->lineH;
	math->texPos = (math->draw_start - w_height / 2 + math->lineH / 2) * math->step;
}

