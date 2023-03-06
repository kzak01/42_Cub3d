#ifndef LOOP_H
# define LOOP_H

# include "../main.h"

typedef struct s_game t_game;

int		game_loop(t_game *game);
void	ray_cast(t_game *game);

#endif
