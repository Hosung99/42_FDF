/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:05:43 by seoson            #+#    #+#             */
/*   Updated: 2023/09/27 20:45:23 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1080

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h> //제거필요

void	ft_error(char *str);
void    read_map(char *argv);
void    check_argument(int argc, char *argv);

#endif