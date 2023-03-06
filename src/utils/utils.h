#ifndef UTILS_H
# define UTILS_H

# include "../main.h"

typedef struct s_game t_game;

int		error(char *str);

void	end_program(t_game *game);
void	free_exit(t_game *game);

void	init_player(t_game *game);
int	init_struct(t_game *game);


#endif
