/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:50:54 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/10/18 15:47:08 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_img(t_ray *data, t_img *img, char *texture_path)
{
	if (img->img)
		prs_err(PRS_FORMAT);
	img->img = mlx_xpm_file_to_image(data->mlx, texture_path, \
	&img->width, &img->height);
	if (!img->img)
		prs_err(PRS_TEXTURE_PATH);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}

static int	set_color(int color, char **codes)
{
	int	ret;

	if (!codes)
		prs_err(PRS_DYNAMIC);
	if (color != -1 || codes[3])
	{
		free_ppc(codes);
		return (-1);
	}
	ret = get_color_code(codes);
	free_ppc(codes);
	return (ret);
}

static char	**chk_line(char *str_c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = -1;
	while (str_c[++i])
	{
		if (str_c[i] == ',')
			cnt++;
	}
	if (cnt != 2)
		prs_err(PRS_FORMAT);
	return (ft_split(str_c, ','));
}

void	set_id(t_ray *data, char *line)
{
	char	**sp_line;

	sp_line = ft_split(line, ' ');
	if (!sp_line)
		prs_err(PRS_DYNAMIC);
	if (!sp_line[1] || sp_line[2])
		prs_err(PRS_FORMAT);
	sp_line[1][ft_strlen(sp_line[1]) - 1] = 0;
	if (!ft_strncmp("NO", sp_line[0], 3))
		set_img(data, &data->texture[0], sp_line[1]);
	else if (!ft_strncmp("SO", sp_line[0], 3))
		set_img(data, &data->texture[1], sp_line[1]);
	else if (!ft_strncmp("WE", sp_line[0], 3))
		set_img(data, &data->texture[2], sp_line[1]);
	else if (!ft_strncmp("EA", sp_line[0], 3))
		set_img(data, &data->texture[3], sp_line[1]);
	else if (!ft_strncmp("F", sp_line[0], 2))
		data->floor_color = \
			set_color(data->floor_color, chk_line(sp_line[1]));
	else if (!ft_strncmp("C", sp_line[0], 2))
		data->ceiling_color = \
			set_color(data->ceiling_color, chk_line(sp_line[1]));
	else
		prs_err(PRS_FORMAT);
	free_ppc(sp_line);
}
