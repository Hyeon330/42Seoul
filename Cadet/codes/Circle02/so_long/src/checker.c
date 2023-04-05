/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:43:14 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/05 22:51:26 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	basic_chk(t_vars *vars, t_img *bg)
{
	// 테두리 전부 1로 되어있는지 정확히 직사각형인지 체크
}

int	chk_map(t_vars *vars, t_img *bg)
{
	int	x;
	int	y;

	if (bg->height == bg->width || \
		1920 < vars->x_width || 1080 < vars->x_height)
		return (0);
	y = -1;
	while (++y < bg->height)
	{
		x = -1;
		while (++x < bg->width)
		{
			if (vars->map[y][x] == 'P')
				return (bfs(vars, bg, x, y));
		}
	}
	return (0);
}