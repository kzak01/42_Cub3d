/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:08:41 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 20:32:56 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static void	change_buble(t_game *game)
{
	int i;
	
	i = -1;
	while (++i < game->util_sprt.sprites_n)
	{
		if (game->sprites[i]->sprite_tipe == 'B' && game->sprites[i]->texture_n == 5)
			game->sprites[i]->texture_n = 6;
		else if (game->sprites[i]->sprite_tipe == 'B' && game->sprites[i]->texture_n == 6)
			game->sprites[i]->texture_n = 5;
	}
}

void	change_siren(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->util_sprt.sprites_n)
	{
		if (game->sprites[i]->sprite_tipe == 'A' && game->sprites[i]->texture_n == 7)
			game->sprites[i]->texture_n = 8;
		else if (game->sprites[i]->sprite_tipe == 'A' && game->sprites[i]->texture_n == 8)
			game->sprites[i]->texture_n = 7;
	}
}

void	frame_animation(t_game *game)
{
	game->util_sprt.bubble_frame++;
	game->util_sprt.siren_frame++;
	if (game->util_sprt.bubble_frame == 20)
	{
		change_buble(game);
		game->util_sprt.bubble_frame = 0;
	}
	if (game->util_sprt.siren_frame == 30)
	{
		change_siren(game);
		game->util_sprt.siren_frame = 0;
	}
}
