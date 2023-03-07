#ifndef MAP_H
# define MAP_H

# include "../main.h"

typedef struct s_game t_game;

//check_map.c
int		check_map(t_game *game);
int		**char_to_int_map(t_game *game);

//check_player.c
int		check_player(t_game *game);

//map.c
int		get_check_map(t_game *game, int ac, char **av);

//utils.c
void	read_texture_path(char *line, char **texture_path_ptr);
int		convertColorToInt(char* color);
void	read_map_line(char *line, t_game *game, int line_index, int map_width_ptr);
int		get_info(char *line, t_game *game);

//varius_check.c
int		check_rule(t_game *game);
int		check_other(t_game *game);
int		check_texture(char *line, t_game *game);
int		check_color(char *line, t_game *game);

#endif
