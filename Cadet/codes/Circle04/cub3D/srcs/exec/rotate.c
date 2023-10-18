/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:30:22 by hoseoson          #+#    #+#             */
/*   Updated: 2023/10/05 23:03:32 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_right(t_ray *data)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = data->dir_x;
	oldplane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(-M_PI / 180 * ROTATE) - data->dir_y
		* sin(-M_PI / 180 * ROTATE);
	data->dir_y = olddir_x * sin(-M_PI / 180 * ROTATE) + data->dir_y * cos(-M_PI
			/ 180 * ROTATE);
	data->plane_x = data->plane_x * cos(-M_PI / 180 * ROTATE) - data->plane_y
		* sin(-M_PI / 180 * ROTATE);
	data->plane_y = oldplane_x * sin(-M_PI / 180 * ROTATE) + data->plane_y
		* cos(-M_PI / 180 * ROTATE);
}

void	key_left(t_ray *data)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = data->dir_x;
	oldplane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(M_PI / 180 * ROTATE) - data->dir_y
		* sin(M_PI / 180 * ROTATE);
	data->dir_y = olddir_x * sin(M_PI / 180 * ROTATE) + data->dir_y * cos(M_PI
			/ 180 * ROTATE);
	data->plane_x = data->plane_x * cos(M_PI / 180 * ROTATE) - data->plane_y
		* sin(M_PI / 180 * ROTATE);
	data->plane_y = oldplane_x * sin(M_PI / 180 * ROTATE) + data->plane_y
		* cos(M_PI / 180 * ROTATE);
}
