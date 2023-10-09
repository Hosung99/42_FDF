/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:17:25 by seoson            #+#    #+#             */
/*   Updated: 2023/10/02 16:28:32 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_length(t_map *map, char *argv)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(argv, O_RDONLY);
	height = 0;
	if (fd == -1)
		ft_error("Error: open error");
	line = get_next_line(fd);
	map->width = ft_count_word(line, 32);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	map->height = height;
	free(line);
	close(fd);
}

void	read_map(t_map *map, char *argv)
{
	get_length(map, argv);
	set_z(map, argv);
	set_x_y(map);
}
