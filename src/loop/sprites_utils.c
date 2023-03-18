/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:37:35 by kzak              #+#    #+#             */
/*   Updated: 2023/03/18 11:20:57 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	sort_far_close(t_game *game, int *sprite_order, double *sprite_dist)
{
	int	i;

	i = -1;
	while (++i < game->util_sprt.sprites_n)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((game->player.pos_x - game->sprites[i]->x)
				* (game->player.pos_x - game->sprites[i]->x)
				+ (game->player.pos_y - game->sprites[i]->y)
				* (game->player.pos_y - game->sprites[i]->y));
	}
}

static void	_sort_order(t_swap *orders, int amount)
{
	t_swap	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < amount)
	{
		j = -1;
		while (++j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
		}
	}
}

void	sort_sprites(int *order, double *dist, int amount)
{
	t_swap	*sprites;
	int		i;

	i = -1;
	sprites = (t_swap *)malloc(sizeof(t_swap) * amount);
	while (++i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	_sort_order(sprites, amount);
	i = -1;
	while (++i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}
