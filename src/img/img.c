#include "img.h"

static int	_alloc_it(t_game *tex)
{
	int	i;
	int	j;

	i = -1;
	if (!(tex->text = (int **)malloc(sizeof(int *) * 4)))
		return (error("error in malloc texture!"));
	while (++i < 4)
	{
		if (!(tex->text[i] = (int *)malloc(sizeof(int) * (texture_size * texture_size))))
			return (error("error in malloc texture!"));
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < texture_size * texture_size)
			tex->text[i][j] = 0;
	}
	return (0);
}

static void	_load_img(t_game *tex, int *n_texture, char *path, t_img *img)
{
	int	x;
	int	y;

	y = -1;
	img->img = mlx_xpm_file_to_image(tex->mlx, path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_size, &img->endian);
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			n_texture[img->img_w * y + x] = img->data[img->img_w * y + x];
	}
	mlx_destroy_image(tex->mlx, img->img);
}

static void	_load_it(t_game *tex)
{
	t_img	img;

	_load_img(tex, tex->text[0], tex->map.north_texture_path, &img);
	_load_img(tex, tex->text[1], tex->map.south_texture_path, &img);
	_load_img(tex, tex->text[2], tex->map.west_texture_path, &img);
	_load_img(tex, tex->text[3], tex->map.east_texture_path, &img);
}

int	load_textures(t_game *tex)
{
	if (_alloc_it(tex))
		return (1);
	_load_it(tex);
	return (0);
}
