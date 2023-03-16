/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:31 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 15:27:41 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	draw_img(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
			game->img.data[y * W_WIDTH + x] = game->buff[y][x];
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

// void	change_sprite(t_game *game)
// {
// 	int i;
	
// 	i = -1;
// 	while (++i < game->sprites_n)
// 	{
// 		if (game->sprites[i]->sprite_tipe == 'B' && game->sprites[i]->texture_n == 5)
// 			game->sprites[i]->texture_n = 6;
// 		else if (game->sprites[i]->sprite_tipe == 'B' && game->sprites[i]->texture_n == 6)
// 			game->sprites[i]->texture_n = 5;
// 	}
// }

// void	frame_animation(t_game *game)
// {
// 	game->frame++;
// 	if (game->frame == 20)
// 	{
// 		change_sprite(game);
// 		game->frame = 0;
// 	}
// }

int	game_loop(t_game *game)
{
	ray_cast(game);
	draw_img(game);
	key_used(game);
	frame_animation(game);

	return (0);
}
