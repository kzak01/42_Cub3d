/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:45:22 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 15:32:57 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

typedef struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - 1; j++)
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

	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	for (int i = 0; i < amount; i++)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, amount);
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}


void	sprites(t_game *game)
{
	// (void)game;
	int		spriteOrder[game->util_sprt.sprites_n];
	double	spriteDistance[game->util_sprt.sprites_n];
	for(int i = 0; i < game->util_sprt.sprites_n; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((game->player.pos_x - game->sprites[i]->x) * (game->player.pos_x - game->sprites[i]->x)
			+ (game->player.pos_y - game->sprites[i]->y) * (game->player.pos_y - game->sprites[i]->y));
	}
	sortSprites(spriteOrder, spriteDistance, game->util_sprt.sprites_n);
	for(int i = 0; i < game->util_sprt.sprites_n; i++)
	{
		double spriteX = game->sprites[spriteOrder[i]]->x - game->player.pos_x;
		double spriteY = game->sprites[spriteOrder[i]]->y - game->player.pos_y;
		double invDet = 1.0 / (game->player.plane_x * game->player.dir_y - game->player.dir_x * game->player.plane_y);
		double transformX = invDet * (game->player.dir_y * spriteX - game->player.dir_x * spriteY);
		double transformY = invDet * (-game->player.plane_y * spriteX + game->player.plane_x * spriteY);
		int spriteScreenX = (int)((W_WIDTH / 2) * (1 + transformX / transformY));
		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0
		int vMoveScreen = (int)(vMove / transformY);
		int spriteHeight = (int)fabs((W_HEIGHT / transformY) / vDiv);
		int drawStartY = -spriteHeight / 2 + W_HEIGHT / 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + W_HEIGHT / 2 + vMoveScreen;
		if(drawEndY >= W_HEIGHT) drawEndY = W_HEIGHT - 1;
		int spriteWidth = (int)fabs((W_HEIGHT / transformY) / uDiv);
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= W_WIDTH) drawEndX = W_WIDTH - 1;
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX))
				* TEXTURE_SIZE / spriteWidth) / 256);
			if(transformY > 0 && stripe > 0 && stripe < W_WIDTH && transformY < game->z_buff[stripe])
			for(int y = drawStartY; y < drawEndY; y++)
			{
				int d = (y-vMoveScreen) * 256 - W_HEIGHT * 128 + spriteHeight * 128;
				int texY = ((d * TEXTURE_SIZE) / spriteHeight) / 256;
				int color = game->text[game->sprites[spriteOrder[i]]->texture_n][TEXTURE_SIZE * texY + texX];
				if((color & 0x00FFFFFF) != 0) game->buff[y][stripe] = color;
			}
		}
	}
}
