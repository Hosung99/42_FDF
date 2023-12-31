/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:30:20 by seoson            #+#    #+#             */
/*   Updated: 2023/09/30 15:20:50 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *temp)
{
	int	index;

	index = 0;
	while (temp[index])
	{
		if (temp[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

int	ft_strlen2(char *s)
{
	int	cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (*s)
	{
		cnt++;
		if (*s == '\n')
			break ;
		s++;
	}
	return (cnt);
}

void	ft_strlcpy2(char *dst, char *src, int dstsize)
{
	int	i;
	int	length_src;

	i = 0;
	length_src = 0;
	if (src && dst)
	{
		if (dstsize != 0)
		{
			while (i + 1 < dstsize && src[i])
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
	}
}

char	*ft_strjoin2(char *s1, char *s2, int index)
{
	char	*str;
	int		i;
	int		save;

	str = (char *)malloc(sizeof(char) * (ft_strlen2(s1) + index + 1));
	if (!str)
	{
		free(s1);
		return (0);
	}
	i = 0;
	save = 0;
	if (s1)
	{
		while (s1[i])
			str[save++] = s1[i++];
	}
	i = 0;
	while (s2[i] && i < index)
		str[save++] = s2[i++];
	str[save] = '\0';
	free(s1);
	return (str);
}
