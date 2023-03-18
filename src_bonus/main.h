/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:19 by kzak              #+#    #+#             */
/*   Updated: 2023/03/18 16:28:41 by kzak             ###   ########.fr       */
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

# include "img/img.h"
# include "key/key.h"
# include "loop/loop.h"
# include "map/map.h"
# include "utils/utils.h"

# define MAP_CHARS "012NEWSABC \n"
// # define W_WIDTH 1920
// # define W_HEIGHT 1080
# define W_WIDTH 1280
# define W_HEIGHT 1024
// # define W_WIDTH 640
// # define W_HEIGHT 480
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
	EAST
};

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
	int	door_press;
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

typedef struct s_sprites
{
	double	x;
	double	y;
	int		texture_n;
	char	sprite_tipe;
}	t_sprites;

typedef struct s_utilsprite
{
	int			sprites_n;
	int			bubble_frame;
	int			siren_frame;
	int			coll_frame;
}	t_utilsprite;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	double			*z_buff;
	int				**text;
	int				**buff;
	t_img			img;
	t_key			key;
	t_map			map;
	t_mouse			mouse;
	t_player		player;
	t_sprites		**sprites;
	t_utilsprite	util_sprt;
}	t_game;

#endif
