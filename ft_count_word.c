/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:11:27 by seoson            #+#    #+#             */
/*   Updated: 2023/10/02 15:00:22 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_word(char const *s, char c)
{
	int		i;
	int		save;
	int		flag;

	i = 0;
	save = 0;
	flag = 1;
	while (s[i])
	{
		if (i != (int)ft_strlen(s) - 1 && s[i] != c && flag)
		{
			flag = 0;
			save++;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (save);
}
