/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:38 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 10:45:07 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	background(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			if (y < (W_HEIGHT / 2))
			{
				game->buff[y][x] = game->map.ceiling_color;
			}
			else
			{
				game->buff[y][x] = game->map.floor_color;
			}
		}
	}
}

void	init_math(t_math *math, t_game *game, int x)
{
	math->camera_x = 2 * x / (double)W_WIDTH - 1;
	math->ray_dir_x = game->player.dir_x + game->player.plane_x
		* math->camera_x;
	math->ray_dir_y = game->player.dir_y + game->player.plane_y
		* math->camera_x;
	math->map_x = (int)game->player.pos_x;
	math->map_y = (int)game->player.pos_y;
	math->delta_dist_x = fabs(1 / math->ray_dir_x);
	math->delta_dist_y = fabs(1 / math->ray_dir_y);
	math->hit = 0;
}

//Digital Differential Analysis
void	dda(t_math *math, t_game *game)
{
	while (math->hit == 0)
	{
		if (math->side_dist_x < math->side_dist_y)
		{
			math->side_dist_x += math->delta_dist_x;
			math->map_x += math->step_x;
			math->side = 0;
		}
		else
		{
			math->side_dist_y += math->delta_dist_y;
			math->map_y += math->step_y;
			math->side = 1;
		}
		if (game->map.map_int[math->map_x][math->map_y] > 0)
			math->hit = 1;
	}
}

	// ft_bzero(&math, sizeof(t_math));
void	wall_cast(t_game *game)
{
	t_math	math;
	int		x;
	int		y;

	x = -1;
	while (++x < W_WIDTH)
	{
		init_math(&math, game, x);
		step_side(&math, game);
		dda(&math, game);
		distance_ray(&math, game);
		calculate_pixel(&math, game);
		y = math.draw_start ;
		while (y < math.draw_end)
		{
			math.tex_y = (int)math.tex_pos & (TEXTURE_SIZE - 1);
			math.tex_pos += math.step;
			math.color = game->text[math.tex_n]
			[TEXTURE_SIZE * math.tex_y + math.tex_x];
			game->buff[y][x] = math.color;
			y++;
		}
		game->z_buff[x] = math.perp_wall_dist;
	}
}

void	ray_cast(t_game *game)
{
	background(game);
	wall_cast(game);
	sprites(game);
}
