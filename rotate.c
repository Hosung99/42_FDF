/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:23:13 by seoson            #+#    #+#             */
/*   Updated: 2023/10/07 11:56:21 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *map)
{
	int		y;
	int		x;
	double	temp;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			temp = map->point[y][x].y;
			map->point[y][x].y = map->point[y][x].y * cos(PI / 5.104) \
				- map->point[y][x].z * sin(PI / 5.104);
			map->point[y][x].z = temp * sin(PI / 5.104) \
				+ map->point[y][x].z * cos(PI / 5.104);
			x++;
		}
		y++;
	}
}

void	rotate_z(t_map *map)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			temp = map->point[i][j].y;
			map->point[i][j].y = map->point[i][j].y * cos(PI / 4) \
				+ map->point[i][j].x * sin(PI / 4);
			map->point[i][j].x = map->point[i][j].x * cos(PI / 4) \
				- temp * sin(PI / 4);
			j++;
		}
		i++;
	}
}
