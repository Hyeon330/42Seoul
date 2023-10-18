/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:19:08 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/10/05 23:03:24 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	chk_extension(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (!extension || ft_strncmp(extension, ".cub", 5))
		prs_err(PRS_EXTENSION);
}

void	chk_id(t_ray *data)
{
	if (data->pos_x < 0 || data->pos_y < 0 || \
		!data->texture[0].img || !data->texture[1].img || \
		!data->texture[2].img || !data->texture[3].img || \
		data->ceiling_color < 0 || data->floor_color < 0)
		prs_err(PRS_FORMAT);
}

static void	chk_map_recursive(t_ray *data, int height, int width, \
	char (*flag)[MAX_WIDTH])
{
	const int	ud[4] = {1, 0, -1, 0};
	const int	lr[4] = {0, 1, 0, -1};
	int			i;

	if (height == 0 || height == MAX_HEIGHT - 1 || \
		width == 0 || width == MAX_WIDTH - 1)
		prs_err(PRS_FORMAT);
	flag[height][width] = 1;
	i = -1;
	while (++i < 4)
	{
		if (data->map[height + ud[i]][width + lr[i]] == ' ' || \
			data->map[height + ud[i]][width + lr[i]] == 0)
			prs_err(PRS_FORMAT);
		if (flag[height + ud[i]][width + lr[i]] == 0 && \
			data->map[height + ud[i]][width + lr[i]] == '0')
			chk_map_recursive(data, height + ud[i], width + lr[i], flag);
	}
}

void	chk_map(t_ray *data)
{
	int		height;
	int		width;
	char	flag[MAX_HEIGHT][MAX_WIDTH];

	ft_memset(flag, 0, MAX_HEIGHT * MAX_WIDTH);
	height = -1;
	while (++height < MAX_HEIGHT)
	{
		width = -1;
		while (++width < MAX_WIDTH)
		{
			if (flag[height][width] == 0 && data->map[height][width] == '0')
				chk_map_recursive(data, height, width, flag);
		}
	}
}
