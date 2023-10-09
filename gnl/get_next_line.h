/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:22:37 by shson1217         #+#    #+#             */
/*   Updated: 2023/10/02 13:58:47 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*init_s(char *s, int fd);
int		init_b(char *temp, char **buff, int *check, int fd);
int		do_read(char *buff, int fd);
int		has_newline(char *temp);
int		ft_strlen2(char *s);
void	ft_strlcpy2(char *dst, char *src, int dstsize);
char	*ft_strjoin2(char *s1, char *s2, int index);

#endif
