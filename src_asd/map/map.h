/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:30 by kzak              #+#    #+#             */
/*   Updated: 2023/03/13 15:24:36 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../main.h"

typedef struct s_game	t_game;

//check_map.c
int		check_map(t_game *game);
int		**char_to_int_map(t_game *game);

//check_player.c
int		check_player(t_game *game);

//map.c
int		get_check_map(t_game *game, int ac, char **av);

//open_close_fd.c
int		open_file(const char *file_path);
int		close_file(int fd);

//read_map.c
int		read_map(const char *file_path, t_game *game);

//utils.c
void	read_texture_path(char *line, char **texture_path_ptr);
int		convert_color_to_int(char *color);
void	read_map_line(char *line, t_game *game, int line_index,
			int map_width_ptr);
int		get_info(char *line, t_game *game);

//varius_check.c
int		check_rule(t_game *game);
int		check_other(t_game *game);
int		check_texture(char *line, t_game *game);
int		check_color(char *line, t_game *game);

#endif
