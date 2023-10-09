/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:32:26 by seoson            #+#    #+#             */
/*   Updated: 2023/10/03 16:37:02 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	bigger(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	smaller(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double	get_max_map(t_map *map)
{
	int		i;
	int		j;
	double	max_x;
	double	max_y;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			max_x = bigger(max_x, map->point[i][j].x);
			max_y = bigger(max_y, map->point[i][j].y);
			j++;
		}
		i++;
	}
	return (smaller(max_x / IMG_WIDTH, max_y / IMG_HEIGHT));
}
