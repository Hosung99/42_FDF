/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:05:43 by seoson            #+#    #+#             */
/*   Updated: 2023/10/07 12:08:06 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_WIDTH 1980
# define MAX_HEIGHT 1080
# define PI 3.14159265
# define IMG_WIDTH 400
# define IMG_HEIGHT 400
# define ESC_CODE 53

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}		t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**point;
	t_data	img;
	void	*mlx;
	void	*mlx_win;
}	t_map;

void	ft_error(char *str);
int		ft_count_word(char const *s, char c);
void	ft_free_ptr(char **ptr);
void	ft_free_map(t_map *map);
void	read_map(t_map *map, char *argv);
void	set_x_y(t_map *map);
void	set_z(t_map *map, char *argv);
void	draw(t_map *map);
void	dda(t_point point1, t_point point2, t_map *map);
void	rotate_x(t_map *map);
void	rotate_z(t_map *map);
void	check_argument(int argc, char *argv);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
double	bigger(double a, double b);
double	smaller(double a, double b);
double	get_max_map(t_map *map);

#endif