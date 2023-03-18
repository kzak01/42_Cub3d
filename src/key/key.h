/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:08:43 by kzak              #+#    #+#             */
/*   Updated: 2023/03/13 14:09:33 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "../main.h"

typedef struct s_game	t_game;

//key.c
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
void	key_used(t_game *game);

//movement.c
void	move_up(t_game *game);
void	move_behind(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);

//rotate.c
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);

#endif
