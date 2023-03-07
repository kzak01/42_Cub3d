#ifndef LOOP_H
# define LOOP_H

# include "../main.h"

typedef struct s_game t_game;

//loop.c
int		game_loop(t_game *game);

//ray_cast.c
void	ray_cast(t_game *game);

#endif
