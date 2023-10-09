/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:35 by seoson            #+#    #+#             */
/*   Updated: 2023/10/03 13:34:58 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda(t_point point1, t_point point2, t_map *map)
{
	double	dx;
	double	dy;
	double	xinc;
	double	yinc;
	double	step;

	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	xinc = dx / step;
	yinc = dy / step;
	while (0 < step)
	{
		my_mlx_pixel_put(&(map->img), point1.x, point1.y, 0x00FFFFFF);
		point1.x += xinc;
		point1.y += yinc;
		step--;
	}
}
