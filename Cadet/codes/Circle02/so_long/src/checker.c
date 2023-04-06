/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:43:14 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/06 19:53:40 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	chk_border(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->x_width)
	{
		if (vars->map[0][i] != '1')
			return (0);
		if (vars->map[vars->x_height - 1][i] != '1')
			return (0);
		if (i < vars->x_height && vars->map[i][0] != '1')
			return (0);
		if (i < vars->x_height && vars->map[i][vars->x_width - 1] != '1')
			return (0);
	}
	return (1);
}

int	chk_map1(t_vars *vars)
{
	int	base_width;

	base_width = ft_strlen(vars->map[0]);
	vars->count_C = 0;
	vars->x_height = -1;
	while (vars->map[++vars->x_height])
	{
		vars->x_width = -1;
		while (vars->map[vars->x_height][++vars->x_width])
		{
			if (vars->map[vars->x_height][vars->x_width] == 'C')
				vars->count_C++;
		}
		if (base_width != vars->x_width)
			return (0);
	}
	return (chk_border(vars));
}

int	chk_map2(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->x_height == vars->x_width || \
		MAX_RESOL_WIDTH / BLOCK_WIDTH < vars->x_width || \
		MAX_RESOL_HEIGHT / BLOCK_HEIGHT < vars->x_height)
		return (0);
	y = -1;
	while (++y < vars->x_height)
	{
		x = -1;
		while (++x < vars->x_width)
		{
			if (vars->map[y][x] == 'P')
				return (bfs(vars, x, y));
		}
	}
	return (0);
}