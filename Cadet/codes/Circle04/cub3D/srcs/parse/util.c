/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:18:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/10/05 23:03:13 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_ppc(char **ppc)
{
	int	i;

	i = -1;
	while (ppc[++i])
		free(ppc[i]);
	free(ppc);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_num(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = -1;
	while (++i < 4 && *str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str)
		return (-1);
	return (result);
}

int	get_color_code(char **codes)
{
	int		ret;
	int		tmp;
	int		i;

	ret = 0;
	i = -1;
	while (codes[++i])
	{
		tmp = get_num(codes[i]);
		if (tmp & ~0xFF)
			return (-1);
		ret = ret << 8 | tmp;
	}
	return (ret);
}
