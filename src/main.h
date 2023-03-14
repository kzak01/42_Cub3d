/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:19 by kzak              #+#    #+#             */
/*   Updated: 2023/03/14 12:42:29 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "../libft/h_file/libft.h"
# include "../mlx/mlx.h"
# include "../minilibx/mlx.h"
// # include <mlx.h>

# include "map/map.h"
# include "img/img.h"
# include "utils/utils.h"
# include "key/key.h"
# include "loop/loop.h"

# define MAP_CHARS "012NEWS \n"
// # define w_width 1920
// # define w_height 1080
# define W_WIDTH 1280
# define W_HEIGHT 1024
// # define w_width 640
// # define w_height 480
# define TEXTURE_SIZE 64

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_MOVE 6
# define KEY_EXIT 17

//Keyboard ARROWS
# define K_AR_L 123
# define K_AR_R 124
# define K_AR_U 126
# define K_AR_D 125
//ESC key
# define K_ESC 53
//Key keyboard
# define K_K_A 0
# define K_K_D 2
# define K_K_S 1
# define K_K_Z 6
# define K_K_W 13
# define K_K_E 14

enum	e_cardinal
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	DOOR_C,
	DOOR_O
};

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

typedef struct s_key
{
	int	key_up;
	int	key_down;
	int	key_right;
	int	key_left;
	int	key_rotate_r;
	int	key_rotate_l;
	int	key_esc;
	int	key_door;
	// int	door_press;
}	t_key;

typedef struct s_immage
{
	void	*img;
	int		*data;
	int		img_w;
	int		img_h;
	int		bpp;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	char	**map;
	char	**control_map;
	int		**map_int;
	int		floor_color;
	int		ceiling_color;
	int		map_width;
	int		map_height;
	int		north;
	int		south;
	int		west;
	int		east;
	int		ceil;
	int		floor;
	int		cardinal;
	int		read_line;
}	t_map;

typedef struct s_player
{
	int			direction;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		movement_s;
	double		rotation_s;
}	t_player;

typedef struct s_mouse
{
	int	mouse_active;
	int	mouse_x;
	int	mouse_y;
}	t_mouse;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			**text;
	int			**buff;
	t_img		img;
	t_key		key;
	t_map		map;
	t_mouse		mouse;
	t_player	player;
}	t_game;

#endif
