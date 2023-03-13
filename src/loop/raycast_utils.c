#include "loop.h"

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

void	distance_ray(t_math *math, t_game *game)
{
	if(math->side == 0)
		math->perpWallDist = (math->mapX - game->player.posX +
			(1 - math->stepX) / 2) / math->rayDirX;
	else
		math->perpWallDist = (math->mapY - game->player.posY +
			(1 - math->stepY) / 2) / math->rayDirY;
}

void	side_wall(t_math *math, t_game *game)
{
	if (math->side == 0)
		math->wall_x = game->player.posY + math->perpWallDist * math->rayDirY;
	else
		math->wall_x = game->player.posX + math->perpWallDist * math->rayDirX;
}

int	find_texture(t_math *math, t_game *game)
{
	int tex_n;

	(void)game;
	if (math->side == 0 && math->rayDirX < 0)
		tex_n = NORTH;
	else if (math->side == 0 && math->rayDirX >= 0)
		tex_n = SOUTH;
	else if (math->side == 1 && math->rayDirY < 0)
		tex_n = WEST;
	else
		tex_n = EAST;
	return (tex_n);
}

void	calculate_pixel(t_math *math, t_game *game)
{
	math->lineH = (int)(w_height / math->perpWallDist);
	math->draw_start = -math->lineH / 2 + w_height / 2;
	if(math->draw_start < 0)
		math->draw_start = 0;
	math->draw_end = math->lineH / 2 + w_height / 2;
	if(math->draw_end >= w_height)
		math->draw_end = w_height - 1;
	math->tex_n = find_texture(math, game);
	side_wall(math, game);
	math->wall_x -= floor((math->wall_x));
	math->texX = (int)(math->wall_x * (double)texture_size);
	if(math->side == 0 && math->rayDirX > 0) 
		math->texX = texture_size - math->texX - 1;
	if(math->side == 1 && math->rayDirY < 0)
		math->texX = texture_size - math->texX - 1;
	math->step = 1.0 * texture_size / math->lineH;
	math->texPos = (math->draw_start  - w_height / 2 + math->lineH / 2) * math->step;
}
