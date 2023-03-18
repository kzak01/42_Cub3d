/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:40 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 14:19:27 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	step_side(t_math *math, t_game *game)
{
	if (math->ray_dir_x < 0)
	{
		math->step_x = -1;
		math->side_dist_x = (game->player.pos_x - math->map_x)
			* math->delta_dist_x;
	}
	else
	{
		math->step_x = 1;
		math->side_dist_x = (math->map_x + 1.0 - game->player.pos_x)
			* math->delta_dist_x;
	}
	if (math->ray_dir_y < 0)
	{
		math->step_y = -1;
		math->side_dist_y = (game->player.pos_y - math->map_y)
			* math->delta_dist_y;
	}
	else
	{
		math->step_y = 1;
		math->side_dist_y = (math->map_y + 1.0 - game->player.pos_y)
			* math->delta_dist_y;
	}
}

void	distance_ray(t_math *math, t_game *game)
{
	if (math->side == 0)
		math->perp_wall_dist = (math->map_x - game->player.pos_x
				+ (1 - math->step_x) / 2) / math->ray_dir_x;
	else
		math->perp_wall_dist = (math->map_y - game->player.pos_y
				+ (1 - math->step_y) / 2) / math->ray_dir_y;
}

void	side_wall(t_math *math, t_game *game)
{
	if (math->side == 0)
		math->wall_x = game->player.pos_y + math->perp_wall_dist
			* math->ray_dir_y;
	else
		math->wall_x = game->player.pos_x + math->perp_wall_dist
			* math->ray_dir_x;
}

int	find_texture(t_math *math, t_game *game)
{
	int	tex_n;

	(void)game;
	if (game->map.map_int[math->map_x][math->map_y] == 2)
		tex_n = 4;
	else if (math->side == 0 && math->ray_dir_x < 0
		&& game->map.map_int[math->map_x][math->map_y] == 1)
		tex_n = NORTH;
	else if (math->side == 0 && math->ray_dir_x >= 0
		&& game->map.map_int[math->map_x][math->map_y] == 1)
		tex_n = SOUTH;
	else if (math->side == 1 && math->ray_dir_y < 0)
		tex_n = WEST;
	else
		tex_n = EAST;
	return (tex_n);
}

void	calculate_pixel(t_math *math, t_game *game)
{
	math->line_h = (int)(W_HEIGHT / math->perp_wall_dist);
	math->draw_start = -math->line_h / 2 + W_HEIGHT / 2;
	if (math->draw_start < 0)
		math->draw_start = 0;
	math->draw_end = math->line_h / 2 + W_HEIGHT / 2;
	if (math->draw_end >= W_HEIGHT)
		math->draw_end = W_HEIGHT - 1;
	math->tex_n = find_texture(math, game);
	side_wall(math, game);
	math->wall_x -= floor((math->wall_x));
	math->tex_x = (int)(math->wall_x * (double)TEXTURE_SIZE);
	if (math->side == 0 && math->ray_dir_x > 0)
		math->tex_x = TEXTURE_SIZE - math->tex_x - 1;
	if (math->side == 1 && math->ray_dir_y < 0)
		math->tex_x = TEXTURE_SIZE - math->tex_x - 1;
	math->step = 1.0 * TEXTURE_SIZE / math->line_h;
	math->tex_pos = (math->draw_start - W_HEIGHT / 2 + math->line_h / 2)
		* math->step;
}
