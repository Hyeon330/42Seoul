/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:45:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/03 08:41:05 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void test1()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "so_long");
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_press(int keycode, t_vars *vars)
{
	ft_printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int main()
{
	int		i;
	t_vars	vars;
	t_img	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, X_WIDTH, X_HEIGHT, "so_long");	// X-widow size

	img.img = mlx_new_image(vars.mlx, IMG_WIDTH, IMG_HEIGHT);	// img size
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	i = -1;
	while (++i < IMG_HEIGHT)
		my_mlx_pixel_put(&img, 0, i, 0x00FFFFFF - i);
	while (--i >= 0)
		my_mlx_pixel_put(&img, IMG_WIDTH - 1, i, 0x00FFFFFF - i);
	while (++i < IMG_WIDTH)
		my_mlx_pixel_put(&img, i, 0, 0x00FFFFFF - i);
	while (--i >= 0)
		my_mlx_pixel_put(&img, i, IMG_HEIGHT - 1, 0x00FFFFFF - i);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, (X_WIDTH - IMG_WIDTH) / 2, (X_HEIGHT - IMG_HEIGHT) / 2); // 출력 이미지의 첫 번째 픽셀 위치


	img.img = mlx_new_image(vars.mlx, IMG_WIDTH, IMG_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	i = -1;
	while (++i < IMG_HEIGHT)
		my_mlx_pixel_put(&img, 0, i, 0x00FFFFFF - i);
	while (--i >= 0)
		my_mlx_pixel_put(&img, IMG_WIDTH - 1, i, 0x00FFFFFF - i);
	while (++i < IMG_WIDTH)
		my_mlx_pixel_put(&img, i, 0, 0x00FFFFFF - i);
	while (--i >= 0)
		my_mlx_pixel_put(&img, i, IMG_HEIGHT - 1, 0x00FFFFFF - i);
	
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, (X_WIDTH - IMG_WIDTH) / 3, (X_HEIGHT - IMG_HEIGHT) / 3);

	char	*relative_path = "./img/wall.xpm";
	int		wall_height;
	int		wall_width;
	
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &wall_width, &wall_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 50, 0);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 50);
	
	mlx_hook(vars.win, 2, 1L<<0, key_press, &img);
	
	mlx_loop(vars.mlx);
}