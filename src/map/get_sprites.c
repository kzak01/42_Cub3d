/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:56:24 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 12:08:52 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	get_sprites_number(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == 'B')
				game->sprites_n++;
		}
	}
}

void	alloc_sprites(t_game *game)
{
	game->sprites = (t_sprites *)malloc(sizeof(t_sprites) * game->sprites_n);
}

void	get_sprites_x_y(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == 'B')
			{
				game->sprites->x = x + 0.5;
				game->sprites->y = y + 0.5;
				game->sprites->texture_n = 5;
			}
		}
	}
}

void	get_sprites_pos(t_game *game)
{
	get_sprites_number(game);
	alloc_sprites(game);
	get_sprites_x_y(game);
}
