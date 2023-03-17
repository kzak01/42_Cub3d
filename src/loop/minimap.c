/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:19:10 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 14:12:44 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

# define MINI_OFFSET 15

typedef struct s_minimap
{
	int		side_len;
	int		tile_len;
	int		offset_tile_x;
	int		offset_tile_y;
}	t_minimap;

static void	struct_init(t_game *game, t_minimap *mini)
{

	static int	blu;
	mini->side_len = W_WIDTH / 6;
	mini->tile_len = mini->side_len / 8;
	mini->offset_tile_x = (int)(((game->player.pos_x
			- floor(game->player.pos_x)) * 10) * mini->tile_len / 10);
	mini->offset_tile_y = (int)(((game->player.pos_y
			- floor(game->player.pos_y)) * 10) * mini->tile_len / 10);
	if (!blu)
		printf("side_len = %d\n", mini->side_len);
	blu = 1;
}

static int	chose_color(t_game *game, t_minimap *mini, int x, int y)
{
	int	map_x;
	int	map_y;

	x -= MINI_OFFSET;
	y -= MINI_OFFSET;
	map_x = x / mini->tile_len - mini->offset_tile_x + (mini->side_len / 2);
	map_y = y / mini->tile_len - mini->offset_tile_y + (mini->side_len / 2);
			// printf("x = %d, y = %d\n", map_x, map_y);

	if (map_y < game->map.map_height && map_x < game->map.map_width
		&& map_y >= 0 && map_x >= 0)
	{
		if (game->map.map_int[map_y][map_x] == 1)
			return (0x0000FF);
		if (game->map.map_int[map_y][map_x] == 2)
			return (0x00FF00);
		if (game->map.map_int[map_y][map_x] == 0)
			return (0xFFFFFF);
	}
	return (0x000000);
}

static void draw_canvas(t_game *game, t_minimap *mini)
{
	int	x;
	int	y;

	y = MINI_OFFSET;
	while (++y < mini->side_len + MINI_OFFSET)
	{
		x = MINI_OFFSET;
		while (++x < mini->side_len + MINI_OFFSET)
		{
			game->buff[y][x] = chose_color(game, mini, x, y);
		}
			// game->buff[y][x] = 0x000000;
	}
}

// void	draw_tiles(t_game *game, t_minimap *mini)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < )
// }

void	minimap(t_game *game)
{
	t_minimap mini;

	struct_init(game, &mini);
	draw_canvas(game, &mini);
	// draw_tiles(game, &mini);
}
