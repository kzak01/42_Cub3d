/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:34 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 10:47:05 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "../main.h"

typedef struct s_game	t_game;
typedef struct s_math	t_math;

//loop.c
int		game_loop(t_game *game);

//ray_cast.c
void	ray_cast(t_game *game);

//raycast_utils.c
void	step_side(t_math *math, t_game *game);
void	distance_ray(t_math *math, t_game *game);
void	side_wall(t_math *math, t_game *game);
int		find_texture(t_math *math, t_game *game);
void	calculate_pixel(t_math *math, t_game *game);

//sprites.c
void	sprites(t_game *game);

#endif
