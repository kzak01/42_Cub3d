/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:37:35 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 15:42:57 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	sort_far_close(t_game *game, int *sprite_order, double *sprite_dist)
{
	int	i;

	i = -1;
	while(++i < game->util_sprt.sprites_n)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((game->player.pos_x - game->sprites[i]->x)
			* (game->player.pos_x - game->sprites[i]->x)
			+ (game->player.pos_y - game->sprites[i]->y)
			* (game->player.pos_y - game->sprites[i]->y));
	}
}

static void	_sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
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
	t_pair	*sprites;
	int		i;

	i = -1;
	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
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

void	sprite_condition(t_game *game, t_math_sprite *m_sprite)
{
	m_sprite->tex_x = (int)((256 * (m_sprite->stripe
		- (-m_sprite->sprite_width / 2 + m_sprite->sprite_screen_x))
		* TEXTURE_SIZE / m_sprite->sprite_width) / 256);
	if(m_sprite->transform_y > 0 && m_sprite->stripe > 0
		&& m_sprite->stripe < W_WIDTH
		&& m_sprite->transform_y < game->z_buff[m_sprite->stripe])
	m_sprite->y = m_sprite->draw_start_y;
}
