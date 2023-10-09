/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:05:02 by seoson            #+#    #+#             */
/*   Updated: 2023/10/07 12:16:13 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	before_exit(t_map *map)
{
	ft_free_map(map);
	mlx_destroy_image(map->mlx, map->img.img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= MAX_WIDTH || y < 0 || y >= MAX_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC_CODE)
		before_exit(map);
	return (0);
}
void	foo(void)
{
	system("leaks fdf");
}

int	main(int argc, char *argv[])
{
	t_map	map;

	check_argument(argc, argv[1]);
	atexit(foo);
	map.mlx = mlx_init();
	if (map.mlx == NULL)
		ft_error("Error: mlx_init error");
	map.mlx_win = mlx_new_window(map.mlx, MAX_WIDTH, MAX_HEIGHT, "FDF");
	map.img.img = mlx_new_image(map.mlx, MAX_WIDTH, MAX_HEIGHT);
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_per_pixel, \
		&map.img.line_length, &map.img.endian);
	read_map(&map, argv[1]);
	draw(&map);
	mlx_put_image_to_window(map.mlx, map.mlx_win, map.img.img, 0, 0);
	mlx_key_hook(map.mlx_win, key_hook, &map);
	mlx_hook(map.mlx_win, 17, 0, before_exit, &map);
	mlx_loop(map.mlx);
	return (0);
}
