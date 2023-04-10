/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:43:14 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/10 13:51:23 by hyeonsul         ###   ########.fr       */
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

int	chk_element(char c)
{
	char	*element;

	element = "10ECP";
	while (*element)
	{
		if (*element++ == c)
			return (1);
	}
	return (0);
}

int	chk_map1(t_vars *vars)
{
	int		base_width;
	int		count_e;

	count_e = 0;
	base_width = ft_strlen(vars->map[0]);
	vars->x_height = -1;
	while (vars->map[++vars->x_height])
	{
		vars->x_width = -1;
		while (vars->map[vars->x_height][++vars->x_width])
		{
			if (!chk_element(vars->map[vars->x_height][vars->x_width]))
				return (0);
			if (vars->map[vars->x_height][vars->x_width] == 'C')
				vars->count_c++;
			if (vars->map[vars->x_height][vars->x_width] == 'E')
				count_e++;
		}
		if (base_width != vars->x_width)
			return (0);
	}
	return (count_e == 1 && chk_border(vars));
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
			{
				vars->x = x;
				vars->y = y;
				return (bfs(vars, x, y));
			}
		}
	}
	return (0);
}
