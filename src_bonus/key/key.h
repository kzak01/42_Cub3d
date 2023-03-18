/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:08:43 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 10:39:09 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "../main.h"

typedef struct s_game	t_game;

//door.c
void	door_o_c(t_game *game);

//key.c
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
void	key_used(t_game *game);

//mouse_move.c
int		mouse_move(int x, int y, t_game *game);
void	mouse_toggle(t_game *game);

//movement.c
void	move_up(t_game *game);
void	move_behind(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);

//rotate.c
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);

#endif
