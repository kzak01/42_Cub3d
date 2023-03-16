/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:08:41 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 15:29:09 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static void	change_sprite(t_game *game)
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

void	frame_animation(t_game *game)
{
	game->util_sprt.bubble_frame++;
	if (game->util_sprt.bubble_frame == 20)
	{
		change_sprite(game);
		game->util_sprt.bubble_frame = 0;
	}
}
