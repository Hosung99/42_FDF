/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:01:41 by seoson            #+#    #+#             */
/*   Updated: 2023/10/07 11:59:31 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	change_isometric(t_map *map)
{
	rotate_z(map);
	rotate_x(map);
}

static void	zoom(t_map *map)
{
	int		x;
	int		y;
	double	zoom;

	y = 0;
	zoom = get_max_map(map);
	while (map->width * zoom < IMG_WIDTH || map->height * zoom < IMG_HEIGHT)
		zoom++;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->point[y][x].x = (map->point[y][x].x * zoom) \
				+ (MAX_WIDTH / 2);
			map->point[y][x].y = (map->point[y][x].y * zoom) \
				+ (MAX_HEIGHT / 3);
			x++;
		}
		y++;
	}
}

void	draw(t_map *map)
{
	int	x;
	int	y;

	change_isometric(map);
	zoom(map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				dda(map->point[y][x], map->point[y][x + 1], map);
			if (y < map->height - 1)
				dda(map->point[y][x], map->point[y + 1][x], map);
			x++;
		}
		y++;
	}
}
