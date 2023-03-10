#ifndef LOOP_H
# define LOOP_H

# include "../main.h"

typedef struct s_game t_game;
typedef struct s_math t_math;

//loop.c
int		game_loop(t_game *game);

//ray_cast.c
void	ray_cast(t_game *game);

//wall_cast.c
void	dda(t_math *math, t_game *game);
void	distance_ray(t_math *math, t_game *game);
void	calculate_pixel(t_math *math, t_game *game);

#endif
