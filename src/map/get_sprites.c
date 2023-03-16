/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:56:24 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 15:33:32 by kzak             ###   ########.fr       */
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
				game->util_sprt.sprites_n++;
		}
	}
}

void	alloc_sprites(t_game *game)
{
	int	i;

	i = -1;
	game->sprites = (t_sprites **)malloc(sizeof(t_sprites *) * game->util_sprt.sprites_n);
	while (++i < game->util_sprt.sprites_n)
	{
		game->sprites[i] = (t_sprites *)malloc(sizeof(t_sprites));
	}
}

void	get_sprites_x_y(t_game *game)
{
	int	y;
	int	x;
	int	s;

	s = 0;
	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == 'B')
			{
				game->sprites[s]->x = y + 0.5;
				game->sprites[s]->y = x + 0.5;
				game->sprites[s]->texture_n = 5;
				game->sprites[s]->sprite_tipe = game->map.map[y][x];
				// printf("x = %f, y = %f, t_n = %d\n", game->sprites[s]->x, game->sprites[s]->y, game->sprites[s]->texture_n);
				s++;
			}
		}
	}
}

void	get_sprites_pos(t_game *game)
{
	get_sprites_number(game);
	alloc_sprites(game);
	get_sprites_x_y(game);
	// printf("x    1 %f, 2 %f, 3 %f\n", game->sprites[0]->x, game->sprites[1]->x, game->sprites[2]->x);
	// printf("y    1 %f, 2 %f, 3 %f\n", game->sprites[0]->y, game->sprites[1]->y, game->sprites[2]->y);

}
