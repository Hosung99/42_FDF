/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:13:53 by seoson            #+#    #+#             */
/*   Updated: 2023/10/03 13:43:10 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_x_y(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->point[y][x].x = x;
			map->point[y][x].y = y;
			x++;
		}
		y++;
	}
}

static void	set_z_line(t_map *map, char *line, int height_index)
{
	int		width_index;
	char	**split_line;

	width_index = 0;
	split_line = ft_split(line, 32);
	while (width_index < map->width)
	{
		map->point[height_index][width_index].z = \
			ft_atoi(split_line[width_index]);
		width_index++;
	}
	ft_free_ptr(split_line);
}

void	set_z(t_map *map, char *argv)
{
	int		height_index;
	int		fd;
	char	*line;

	height_index = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error: open error");
	map->point = (t_point **)malloc(sizeof(t_point *) * (map->height));
	while (height_index < map->height)
	{
		map->point[height_index] = (t_point *)malloc(sizeof(t_point) \
			* (map->width));
		line = get_next_line(fd);
		set_z_line(map, line, height_index);
		height_index++;
		free(line);
	}
	close(fd);
}
