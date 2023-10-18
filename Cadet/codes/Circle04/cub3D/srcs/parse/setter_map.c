/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:26:57 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/10/08 17:40:08 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir(t_ray *data, char dir)
{
	if (dir == 'N')
		data->dir_y = 1;
	if (dir == 'S')
		data->dir_y = -1;
	if (dir == 'E')
		data->dir_x = 1;
	if (dir == 'W')
		data->dir_x = -1;
}

static void	set_plane(t_ray *data, char dir)
{
	if (dir == 'N')
		data->plane_x = PLANE;
	if (dir == 'S')
		data->plane_x = -PLANE;
	if (dir == 'E')
		data->plane_y = -PLANE;
	if (dir == 'W')
		data->plane_y = PLANE;
}

static void	set_line(t_ray *data, char *line, int height)
{
	int	width;

	width = -1;
	while (line[++width] && line[width] != '\n')
	{
		if (width >= MAX_WIDTH || !(line[width] == ' ' || \
			line[width] == '1' || line[width] == '0' || \
			line[width] == 'N' || line[width] == 'S' || \
			line[width] == 'W' || line[width] == 'E'))
			prs_err(PRS_FORMAT);
		if (line[width] == '1' || line[width] == '0' || line[width] == ' ')
			data->map[height][width] = line[width];
		else
		{
			if (data->pos_x >= 0 || data->pos_y >= 0)
				prs_err(PRS_FORMAT);
			set_dir(data, line[width]);
			set_plane(data, line[width]);
			data->map[height][width] = '0';
			data->pos_x = width;
			data->pos_y = height;
		}
	}
}

static void	sw_map(t_ray *data, int max_height)
{
	char	tmp[MAX_WIDTH];
	int		i;

	i = -1;
	while (++i <= max_height / 2)
	{
		ft_memcpy(tmp, data->map[i], MAX_WIDTH);
		ft_memcpy(data->map[i], data->map[max_height - i], MAX_WIDTH);
		ft_memcpy(data->map[max_height - i], tmp, MAX_WIDTH);
	}
	data->pos_y = max_height - data->pos_y;
}

void	set_map(t_ray *data, int fd, char *line)
{
	int	height;

	height = -1;
	set_line(data, line, ++height);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '1' && line[0] != ' ' && line[0] != '\n')
			prs_err(PRS_FORMAT);
		set_line(data, line, ++height);
		free(line);
	}
	sw_map(data, height);
	data->pos_x += 0.500003;
	data->pos_y += 0.500003;
}
