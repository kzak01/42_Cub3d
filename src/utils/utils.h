#ifndef UTILS_H
# define UTILS_H

# include "../main.h"

typedef struct s_game t_game;

//error.c
int		error(char *str);

//free_exit.c
void	free_exit(t_game *game);
int		end_program(t_game *game);

//init.c
int		init_struct(t_game *game);
void	init_player(t_game *game);


#endif
