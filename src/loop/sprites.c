/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:45:22 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 15:40:19 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

//translate sprite position to relative to camera
//transform sprite with the inverse camera matrix
//parameters for scaling and moving the sprites
void	sprite_camera_calc(t_game *game,
			t_math_sprite *m_sprite, int *sprite_order)
{
	m_sprite->sprite_x = game->sprites[sprite_order[m_sprite->i]]->x
		- game->player.pos_x;
	m_sprite->sprite_y = game->sprites[sprite_order[m_sprite->i]]->y
		- game->player.pos_y;
	m_sprite->inv_det = 1.0 / (game->player.plane_x * game->player.dir_y
		- game->player.dir_x * game->player.plane_y);
	m_sprite->transform_x = m_sprite->inv_det * (game->player.dir_y
		* m_sprite->sprite_x - game->player.dir_x * m_sprite->sprite_y);
	m_sprite->transform_y = m_sprite->inv_det * (-game->player.plane_y
		* m_sprite->sprite_x + game->player.plane_x * m_sprite->sprite_y);
	m_sprite->sprite_screen_x = (int)((W_WIDTH / 2)
		* (1 + m_sprite->transform_x / m_sprite->transform_y));
	m_sprite->v_move_screen = (int)(V_MOVE / m_sprite->transform_y);
}

//calculate height of the sprite on screen
//calculate lowest and highest pixel to fill in current stripe
//calculate width of the sprite
void	sprite_draw_calc(t_math_sprite *m_sprite)
{
	m_sprite->sprite_h = (int)fabs((W_HEIGHT / m_sprite->transform_y) / V_DIV);
	m_sprite->draw_start_y = -m_sprite->sprite_h / 2
		+ W_HEIGHT / 2 + m_sprite->v_move_screen;
	if(m_sprite->draw_start_y < 0)
		m_sprite->draw_start_y = 0;
	m_sprite->draw_end_y = m_sprite->sprite_h / 2
		+ W_HEIGHT / 2 + m_sprite->v_move_screen;
	if(m_sprite->draw_end_y >= W_HEIGHT)
		m_sprite->draw_end_y = W_HEIGHT - 1;
	m_sprite->sprite_width = (int)fabs((W_HEIGHT / m_sprite->transform_y)
		/ U_DIV);
	m_sprite->draw_start_x = -m_sprite->sprite_width / 2
		+ m_sprite->sprite_screen_x;
	if(m_sprite->draw_start_x < 0)
		m_sprite->draw_start_x = 0;
	m_sprite->draw_end_x = m_sprite->sprite_width / 2
		+ m_sprite->sprite_screen_x;
	if(m_sprite->draw_end_x >= W_WIDTH)
		m_sprite->draw_end_x = W_WIDTH - 1;
}

void	print_the_stripe(t_game *game, t_math_sprite *m_sprite,
				int *sprite_order)
{
	m_sprite->d = (m_sprite->y - m_sprite->v_move_screen) * 256 - W_HEIGHT
		* 128 + m_sprite->sprite_h * 128; 
	m_sprite->tex_y = ((m_sprite->d * TEXTURE_SIZE)
		/ m_sprite->sprite_h) / 256;
	m_sprite->color = game->text[game->sprites[sprite_order
		[m_sprite->i]]->texture_n]
		[TEXTURE_SIZE * m_sprite->tex_y + m_sprite->tex_x];
	if((m_sprite->color & 0x00FFFFFF) != 0)
	game->buff[m_sprite->y][m_sprite->stripe] = m_sprite->color;
	m_sprite->y++;
}

void	in_while(t_game *game, t_math_sprite *m_sprite,
			int	*sprite_order)
{
		sprite_camera_calc(game, m_sprite, sprite_order);
		sprite_draw_calc(m_sprite);
		m_sprite->stripe = m_sprite->draw_start_x;
		while(m_sprite->stripe < m_sprite->draw_end_x)
		{
			sprite_condition(game, m_sprite);
			while(m_sprite->y < m_sprite->draw_end_y)
				print_the_stripe(game, m_sprite, sprite_order);
			m_sprite->stripe++;
		}
		m_sprite->i++;
}

void	sprites(t_game *game)
{
	int				*sprite_order;
	double			*sprite_dist;
	t_math_sprite	m_sprite;

	ft_bzero(&m_sprite, sizeof(t_math_sprite));
	sprite_order = (int *)malloc(sizeof(int) * game->util_sprt.sprites_n);
	sprite_dist = (double *)malloc(sizeof(double) * game->util_sprt.sprites_n);
	sort_far_close(game, sprite_order, sprite_dist);
	sort_sprites(sprite_order, sprite_dist, game->util_sprt.sprites_n);
	m_sprite.i = 0;
	while(m_sprite.i < game->util_sprt.sprites_n)
	{
		in_while(game, &m_sprite, sprite_order);
	}
	free(sprite_order);
	free(sprite_dist);
}
