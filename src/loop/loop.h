/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:34 by kzak              #+#    #+#             */
/*   Updated: 2023/03/20 10:40:08 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "../main.h"

typedef struct s_game	t_game;

typedef struct s_math
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_n;
	int		tex_x;
	int		tex_y;
	int		color;
}	t_math;

//loop.c
int		game_loop(t_game *game);

//ray_cast.c
void	ray_cast(t_game *game);

//raycast_utils.c
void	step_side(t_math *math, t_game *game);
void	distance_ray(t_math *math, t_game *game);
void	side_wall(t_math *math, t_game *game);
int		find_texture(t_math *math, t_game *game);
void	calculate_pixel(t_math *math, t_game *game);

#endif
