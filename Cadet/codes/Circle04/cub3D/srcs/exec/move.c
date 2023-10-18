/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:30:24 by hoseoson          #+#    #+#             */
/*   Updated: 2023/10/06 02:09:09 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_a(t_ray *data)
{
	double	dir_left_x;
	double	dir_left_y;

	dir_left_x = data->dir_x * cos(M_PI / 2) - data->dir_y * sin(M_PI / 2);
	dir_left_y = data->dir_x * sin(M_PI / 2) + data->dir_y * cos(M_PI / 2);
	if (data->map[(int)data->pos_y]
		[(int)(data->pos_x + dir_left_x * MOVE)] == '0')
		data->pos_x += dir_left_x * MOVE;
	if (data->map[(int)(data->pos_y + dir_left_y * MOVE)]
		[(int)data->pos_x] == '0')
		data->pos_y += dir_left_y * MOVE;
}

void	key_d(t_ray *data)
{
	double	dir_right_x;
	double	dir_right_y;

	dir_right_x = data->dir_x * cos(-M_PI / 2) - data->dir_y * sin(-M_PI / 2);
	dir_right_y = data->dir_x * sin(-M_PI / 2) + data->dir_y * cos(-M_PI / 2);
	if (data->map[(int)data->pos_y]
		[(int)(data->pos_x + dir_right_x * MOVE)] == '0')
		data->pos_x += dir_right_x * MOVE;
	if (data->map[(int)(data->pos_y + dir_right_y * MOVE)]
		[(int)data->pos_x] == '0')
		data->pos_y += dir_right_y * MOVE;
}

void	key_w(t_ray *data)
{
	if (data->map[(int)data->pos_y]
		[(int)(data->pos_x + data->dir_x * MOVE)] == '0')
		data->pos_x += data->dir_x * MOVE;
	if (data->map[(int)(data->pos_y + data->dir_y * MOVE)]
		[(int)data->pos_x] == '0')
		data->pos_y += data->dir_y * MOVE;
}

void	key_s(t_ray *data)
{
	if (data->map[(int)data->pos_y]
		[(int)(data->pos_x - data->dir_x * MOVE)] == '0')
		data->pos_x -= data->dir_x * MOVE;
	if (data->map[(int)(data->pos_y - data->dir_y * MOVE)]
		[(int)data->pos_x] == '0')
		data->pos_y -= data->dir_y * MOVE;
}
