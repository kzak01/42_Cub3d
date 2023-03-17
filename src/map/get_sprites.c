/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:56:24 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 16:31:20 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	get_sprites_number(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			if (game->map.map[y][x] == 'B'
				|| game->map.map[y][x] == 'A'
				|| game->map.map[y][x] == 'C')
				game->util_sprt.sprites_n++;
		}
	}
	return (game->util_sprt.sprites_n);
}

void	alloc_sprites(t_game *game)
{
	int	i;

	i = -1;
	game->sprites = (t_sprites **)malloc(sizeof(t_sprites *)
			* game->util_sprt.sprites_n);
	while (++i < game->util_sprt.sprites_n)
	{
		game->sprites[i] = (t_sprites *)malloc(sizeof(t_sprites));
	}
}

int	check_sprites_type(t_game *game, int y, int x, int s)
{
	if (game->map.map[y][x] == 'B')
	{
		game->sprites[s]->x = y + 0.5;
		game->sprites[s]->y = x + 0.5;
		game->sprites[s]->texture_n = 5;
		game->sprites[s]->sprite_tipe = game->map.map[y][x];
		s++;
	}
	if (game->map.map[y][x] == 'A')
	{
		game->sprites[s]->x = y + 0.5;
		game->sprites[s]->y = x + 0.5;
		game->sprites[s]->texture_n = 7;
		game->sprites[s]->sprite_tipe = game->map.map[y][x];
		s++;
	}
	if (game->map.map[y][x] == 'C')
	{
		game->sprites[s]->x = y + 0.5;
		game->sprites[s]->y = x + 0.5;
		game->sprites[s]->texture_n = 9;
		game->sprites[s]->sprite_tipe = game->map.map[y][x];
		s++;
	}
	return (s);
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
			s = check_sprites_type(game, y, x, s);
		}
	}
}

void	get_sprites_pos(t_game *game)
{
	if (!get_sprites_number(game))
		return ;
	alloc_sprites(game);
	get_sprites_x_y(game);
}
