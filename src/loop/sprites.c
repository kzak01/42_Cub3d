/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:45:22 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 14:26:11 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	sort_order(t_pair *orders, int amount)
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

void	sortSprites(int *order, double *dist, int amount)
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
	sort_order(sprites, amount);
	i = -1;
	while (++i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}

void	sprites(t_game *game)
{
	int		sprite_order[game->util_sprt.sprites_n];
	double	sprite_dist[game->util_sprt.sprites_n];
	t_math_sprite	m_sprite;

	ft_bzero(&m_sprite, sizeof(t_math_sprite));
	m_sprite.i = 0;
	while(m_sprite.i < game->util_sprt.sprites_n)
	{
		sprite_order[m_sprite.i] = m_sprite.i;
		sprite_dist[m_sprite.i] = ((game->player.pos_x - game->sprites[m_sprite.i]->x)
			* (game->player.pos_x - game->sprites[m_sprite.i]->x)
			+ (game->player.pos_y - game->sprites[m_sprite.i]->y)
			* (game->player.pos_y - game->sprites[m_sprite.i]->y));
		m_sprite.i++;
	}
	sortSprites(sprite_order, sprite_dist, game->util_sprt.sprites_n);
	m_sprite.i = 0;
	while(m_sprite.i < game->util_sprt.sprites_n)
	{
		m_sprite.sprite_x = game->sprites[sprite_order[m_sprite.i]]->x - game->player.pos_x;
		m_sprite.sprite_y = game->sprites[sprite_order[m_sprite.i]]->y - game->player.pos_y;

		m_sprite.inv_det = 1.0 / (game->player.plane_x * game->player.dir_y - game->player.dir_x * game->player.plane_y);
		m_sprite.transform_x = m_sprite.inv_det * (game->player.dir_y * m_sprite.sprite_x - game->player.dir_x * m_sprite.sprite_y);
		m_sprite.transform_y = m_sprite.inv_det * (-game->player.plane_y * m_sprite.sprite_x + game->player.plane_x * m_sprite.sprite_y);
		m_sprite.sprite_screen_x = (int)((W_WIDTH / 2) * (1 + m_sprite.transform_x / m_sprite.transform_y));


		m_sprite.v_move_screen = (int)(V_MOVE / m_sprite.transform_y);
		m_sprite.sprite_h = (int)fabs((W_HEIGHT / m_sprite.transform_y) / V_DIV);
		m_sprite.draw_start_y = -m_sprite.sprite_h / 2 + W_HEIGHT / 2 + m_sprite.v_move_screen;

		if(m_sprite.draw_start_y < 0) m_sprite.draw_start_y = 0;
		m_sprite.draw_end_y = m_sprite.sprite_h / 2 + W_HEIGHT / 2 + m_sprite.v_move_screen;
		if(m_sprite.draw_end_y >= W_HEIGHT) m_sprite.draw_end_y = W_HEIGHT - 1;

		m_sprite.sprite_width = (int)fabs((W_HEIGHT / m_sprite.transform_y) / U_DIV);
		m_sprite.draw_start_x = -m_sprite.sprite_width / 2 + m_sprite.sprite_screen_x;

		if(m_sprite.draw_start_x < 0) m_sprite.draw_start_x = 0;
		m_sprite.draw_end_x = m_sprite.sprite_width / 2 + m_sprite.sprite_screen_x;
		if(m_sprite.draw_end_x >= W_WIDTH) m_sprite.draw_end_x = W_WIDTH - 1;

		for(m_sprite.stripe = m_sprite.draw_start_x; m_sprite.stripe < m_sprite.draw_end_x; m_sprite.stripe++)
		{
			m_sprite.tex_x = (int)((256 * (m_sprite.stripe - (-m_sprite.sprite_width / 2 + m_sprite.sprite_screen_x))
				* TEXTURE_SIZE / m_sprite.sprite_width) / 256);
			if(m_sprite.transform_y > 0 && m_sprite.stripe > 0 && m_sprite.stripe < W_WIDTH && m_sprite.transform_y < game->z_buff[m_sprite.stripe])
			m_sprite.y = m_sprite.draw_start_y;
			while(m_sprite.y < m_sprite.draw_end_y)
			{
				m_sprite.d = (m_sprite.y-m_sprite.v_move_screen) * 256 - W_HEIGHT * 128 + m_sprite.sprite_h * 128;
				m_sprite.tex_y = ((m_sprite.d * TEXTURE_SIZE) / m_sprite.sprite_h) / 256;
				m_sprite.color = game->text[game->sprites[sprite_order[m_sprite.i]]->texture_n][TEXTURE_SIZE * m_sprite.tex_y + m_sprite.tex_x];
				if((m_sprite.color & 0x00FFFFFF) != 0) game->buff[m_sprite.y][m_sprite.stripe] = m_sprite.color;
				m_sprite.y++;
			}
		}
		m_sprite.i++;
	}
}
