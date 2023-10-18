/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:20:01 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/10/06 00:23:11 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_init(t_ray *data)
{
	ft_bzero(data, sizeof(t_ray));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	data->img.img = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
		&data->img.bits_per_pixel, \
		&data->img.line_length, \
		&data->img.endian);
	data->pos_x = -1;
	data->pos_y = -1;
	data->floor_color = -1;
	data->ceiling_color = -1;
}

void	run(t_ray *data)
{
	raycasting(data);
	mlx_hook(data->win, 2, 0, key, data);
	mlx_hook(data->win, 17, 0, close_win, 0);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_ray	data;

	if (ac != 2)
		error("arguments error");
	data_init(&data);
	parse(&data, av[1]);
	run(&data);
	return (0);
}
