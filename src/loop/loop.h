/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:34 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 14:25:49 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "../main.h"

# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0

typedef struct s_game	t_game;

typedef struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

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

typedef struct s_math_sprite
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		v_move_screen;
	int		sprite_h;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		stripe;
	int		tex_x;
	int		d;
	int		tex_y;
	int		color;
	int		i;
	int		y;
}	t_math_sprite;

//frame_animation.c
void	frame_animation(t_game *game);

//loop.c
int		game_loop(t_game *game);

//minimap.c
void	minimap(t_game *game);

//ray_cast.c
void	ray_cast(t_game *game);

//raycast_utils.c
void	step_side(t_math *math, t_game *game);
void	distance_ray(t_math *math, t_game *game);
void	side_wall(t_math *math, t_game *game);
int		find_texture(t_math *math, t_game *game);
void	calculate_pixel(t_math *math, t_game *game);

//sprites.c
void	sprites(t_game *game);

#endif
