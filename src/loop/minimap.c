/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:19:10 by kzak              #+#    #+#             */
/*   Updated: 2023/03/17 18:14:17 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

# define MINI_OFFSET 15

typedef struct s_minimap
{
	int		side_len;
	int		tile_len;
	int		first_tile_offset_x;
	int		first_tile_offset_y;
	int		tiles_n_per_side;
	int		first_tile_x;
	int		first_tile_y;
}	t_minimap;

static void	struct_init(t_game *game, t_minimap *mini)
{

	// static int	blu;
	mini->side_len = W_WIDTH / 6;
	mini->tile_len = mini->side_len / 8;
	mini->first_tile_offset_x = (int)(((game->player.pos_y
			- floor(game->player.pos_y)) * 10) * mini->tile_len / 10);
	mini->first_tile_offset_y = (int)(((game->player.pos_x
			- floor(game->player.pos_x)) * 10) * mini->tile_len / 10);
	mini->tiles_n_per_side = mini->side_len / mini->tile_len / 2;
	// mini->first_tile_x = mini->tile_len - mini->first_tile_offset_x;
	// mini->first_tile_y = mini->tile_len - mini->first_tile_offset_y;
	mini->first_tile_x = floor(game->player.pos_y) - mini->tiles_n_per_side;
	mini->first_tile_y = floor(game->player.pos_x) - mini->tiles_n_per_side;
	// if (!blu)
	// printf("off_x = %d, off_y = %d\n", mini->first_tile_offset_x, mini->first_tile_offset_y);
	// blu = 1;
}

static int	chose_color(t_game *game, t_minimap *mini, int x, int y)
{
	int	map_x;
	int	map_y;
	static int	asd_x = 1;
	static int	asd_y = 1;

	x -= MINI_OFFSET;
	y -= MINI_OFFSET;
	map_x = floor(game->player.pos_y) - mini->tiles_n_per_side + x / mini->tile_len;
	map_y = floor(game->player.pos_x) - mini->tiles_n_per_side + y / mini->tile_len;
	
	if (map_x == mini->first_tile_x && asd_x > mini->tile_len - mini->first_tile_offset_x)
	{
		map_x++;
	}
	if (map_y == mini->first_tile_y && asd_y > mini->tile_len - mini->first_tile_offset_y)
	{
		map_y++;
	}
	// printf("x = %d, y = %d p_y = %f, p_x = %f\n", map_x, map_y, game->player.pos_y, game->player.pos_x);
	if (map_y < game->map.map_height && map_x < game->map.map_width
		&& map_y >= 0 && map_x >= 0)
	{
		// printf("qui\n");
		if (game->map.map_int[map_y][map_x] == 1)
			return (0x00BFFF);
		if (game->map.map_int[map_y][map_x] == 2)
			return (0x8B4513);
		if (game->map.map_int[map_y][map_x] == 0)
			return (0xC9B797);
	}
	return (0x000000);
}

static void draw_map(t_game *game, t_minimap *mini)
{
	int	x;
	int	y;

	y = MINI_OFFSET - 1;
	while (++y < mini->side_len + MINI_OFFSET)
	{
		x = MINI_OFFSET - 1;
		while (++x < mini->side_len + MINI_OFFSET)
		{
			game->buff[y][x] = chose_color(game, mini, x, y);
		}
	}
}

static void	draw_player(t_game *game, t_minimap *mini)
{
	int	i;
	int	j;

	i = mini->side_len / 2 + MINI_OFFSET - 4;
	while (++i < mini->side_len / 2 + MINI_OFFSET + 4)
	{
		j = mini->side_len / 2 + MINI_OFFSET - 4;
		while (++j < mini->side_len / 2 + MINI_OFFSET + 4)
			game->buff[i][j] = 0xFF0000;
	}
}

void	minimap(t_game *game)
{
	t_minimap mini;

	struct_init(game, &mini);
	draw_map(game, &mini);
	draw_player(game, &mini);
}
