/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:05:02 by seoson            #+#    #+#             */
/*   Updated: 2023/09/27 20:47:21 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char *argv[])
{
    void *mlx;
	void *mlx_win;
	t_data	img;

	check_argument(argc, argv[1]);
	mlx = mlx_init();
	if (mlx == NULL)
		ft_error("Error: mlx_init error");
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT); // 이미지 객체 생성
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian); // 이미지 주소 할당
	for (int i = 0 ; i < 500 ; i++)
	{
		for (int j = 0 ; j < 500 ; j++)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		}	
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, WIDTH / 3, HEIGHT / 3); //화면 가운데에 위치하도록 수정필요
	mlx_loop(mlx);
	read_map(argv[1]);
}