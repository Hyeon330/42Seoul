/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:22:02 by hoseoson          #+#    #+#             */
/*   Updated: 2023/10/08 14:23:24 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_back(t_ray *data)
{
	int	width;
	int	height;

	width = -1;
	while (++width < SCREENWIDTH)
	{
		height = -1;
		while (++height < SCREENHEIGHT / 2)
			my_mlx_pixel_put(&data->img, width, height, data->ceiling_color);
		while (height < SCREENHEIGHT)
			my_mlx_pixel_put(&data->img, width, height++, data->floor_color);
	}
	return (1);
}

int	key(int keycode, t_ray *data)
{
	if (keycode == K_ESC)
		exit(0);
	if (keycode == K_AR_L)
		key_left(data);
	else if (keycode == K_AR_R)
		key_right(data);
	else if (keycode == K_W)
		key_w(data);
	else if (keycode == K_A)
		key_a(data);
	else if (keycode == K_S)
		key_s(data);
	else if (keycode == K_D)
		key_d(data);
	raycasting(data);
	return (0);
}

static void	get_perpwalldist(t_ray *data)
{
	if (data->side == 0)
	{
		data->perpwalldist = (data->map_x - data->pos_x
				+ (1 - data->step_x) / 2) / data->raydir_x;
	}
	else
	{
		data->perpwalldist = (data->map_y - data->pos_y
				+ (1 - data->step_y) / 2) / data->raydir_y;
	}
}

int	raycasting(t_ray *data)
{
	data->x = -1;
	set_back(data);
	while (++data->x < SCREENWIDTH)
	{
		data->camera_x = 2 * data->x / (double)SCREENWIDTH - 1;
		data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
		data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
		data->map_x = (int)data->pos_x;
		data->map_y = (int)data->pos_y;
		data->deltadist_x = sqrt(1 + (data->raydir_y * data->raydir_y)
				/ (data->raydir_x * data->raydir_x));
		data->deltadist_y = sqrt(1 + (data->raydir_x * data->raydir_x)
				/ (data->raydir_y * data->raydir_y));
		sidedist(data);
		dda(data);
		get_perpwalldist(data);
		line_height(data);
		wall_color(data);
		draw_wall(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
