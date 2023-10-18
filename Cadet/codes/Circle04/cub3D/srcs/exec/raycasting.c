/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:40:07 by hoseoson          #+#    #+#             */
/*   Updated: 2023/10/13 14:24:48 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sidedist(t_ray *data)
{
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->sidedist_x = (data->pos_x - data->map_x) * data->deltadist_x;
	}
	else
	{
		data->step_x = 1;
		data->sidedist_x = (data->map_x + 1.0 - data->pos_x)
			* data->deltadist_x;
	}
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->sidedist_y = (data->pos_y - data->map_y) * data->deltadist_y;
	}
	else
	{
		data->step_y = 1;
		data->sidedist_y = (data->map_y + 1.0 - data->pos_y)
			* data->deltadist_y;
	}
}

void	dda(t_ray *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->sidedist_x < data->sidedist_y)
		{
			data->sidedist_x += data->deltadist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->sidedist_y += data->deltadist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_y][data->map_x] == '1')
			hit = 1;
	}
}

void	line_height(t_ray *data)
{
	data->line_height = (int)(SCREENHEIGHT / data->perpwalldist);
	data->draw_start = -data->line_height / 2 + SCREENHEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + SCREENHEIGHT / 2;
	if (data->draw_end >= SCREENHEIGHT)
		data->draw_end = SCREENHEIGHT - 1;
}

void	wall_color(t_ray *data)
{
	if (data->step_x < 0 && data->side == 0)
		data->texnum = WE;
	else if (data->step_x > 0 && data->side == 0)
		data->texnum = EA;
	else if (data->step_y < 0 && data->side == 1)
		data->texnum = SO;
	else
		data->texnum = NO;
	if (data->side == 0)
		data->wallx = data->pos_y + data->perpwalldist * data->raydir_y;
	else
		data->wallx = data->pos_x + data->perpwalldist * data->raydir_x;
	data->wallx -= floor(data->wallx);
	data->tex_x = (int)(data->wallx * (double)TEXWIDTH);
	if (data->side == 0 && data->raydir_x > 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	if (data->side == 1 && data->raydir_y < 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
}

void	draw_wall(t_ray *data)
{
	int	y;

	data->step = 1.0 * TEXHEIGHT / data->line_height;
	data->texpos = (data->draw_start - SCREENHEIGHT / 2 + data->line_height / 2)
		* data->step;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->texpos;
		data->texpos += data->step;
		data->color = *(unsigned int *)
			&data->texture[data->texnum].addr[(data->tex_y
				* data->texture[data->texnum].line_length + data->tex_x
				* (data->texture[data->texnum].bits_per_pixel / 8))];
		my_mlx_pixel_put(&data->img, data->x, y, data->color);
		y++;
	}
}
