/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:37:16 by kzak              #+#    #+#             */
/*   Updated: 2023/03/16 19:19:10 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

static int	_alloc_it(t_game *tex)
{
	int	i;
	int	j;

	i = -1;
	tex->text = (int **)malloc(sizeof(int *) * 9);
	if (!tex->text)
		return (error("error in malloc texture!"));
	while (++i < 9)
	{
		tex->text[i] = (int *)malloc(sizeof(int)
				* (TEXTURE_SIZE * TEXTURE_SIZE));
		if (!tex->text[i])
			return (error("error in malloc texture!"));
	}
	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < TEXTURE_SIZE * TEXTURE_SIZE)
			tex->text[i][j] = 0;
	}
	return (0);
}

static int	_load_img(t_game *tex, int *n_texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(tex->mlx, path, &img->img_w, &img->img_h);
	if (!img->img)
		return (error("texture not found!"));
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_size,
			&img->endian);
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
		{
			n_texture[img->img_w * y + x] = img->data[img->img_w * y + x];
		}
	}
	mlx_destroy_image(tex->mlx, img->img);
	return (0);
}

static int _load_wall(t_game *tex, t_img *img)
{
	if (_load_img(tex, tex->text[0], tex->map.north_texture_path, img))
		return (1);
	if (_load_img(tex, tex->text[1], tex->map.south_texture_path, img))
		return (1);
	if (_load_img(tex, tex->text[2], tex->map.west_texture_path, img))
		return (1);
	if (_load_img(tex, tex->text[3], tex->map.east_texture_path, img))
		return (1);
	return (0);
}

static int	_load_it(t_game *tex)
{
	t_img	img;

	if (_load_wall(tex, &img))
		return (1);
	if (_load_img(tex, tex->text[4], "textures/Door1.xpm", &img))
		return (1);
	if (_load_img(tex, tex->text[5], "textures/Buble.xpm", &img))
		return (1);
	if (_load_img(tex, tex->text[6], "textures/Buble1.xpm", &img))
		return (1);
	if (_load_img(tex, tex->text[7], "textures/Player1.xpm", &img))
		return (1);
	if (_load_img(tex, tex->text[8], "textures/Player2.xpm", &img))
		return (1);
	return (0);
}

int	load_textures(t_game *tex)
{
	if (_alloc_it(tex))
		return (1);
	if (_load_it(tex))
		return (1);
	return (0);
}
