/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:24:05 by seoson            #+#    #+#             */
/*   Updated: 2023/10/04 13:32:25 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->point[i]);
		i++;
	}
	free(map->point);
}
