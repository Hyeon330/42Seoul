/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:18:28 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/20 12:22:27 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i][0])
	{
		ft_putstr(map[i++]);
		ft_putstr("\n");
	}
}

void	put_result(char **map, int *coords, char full)
{
	int	i;
	int	j;

	i = coords[0] - coords[2] + 1;
	while (i <= coords[0])
	{
		j = coords[1] - coords[2] + 1;
		while (j <= coords[1])
		{
			map[i][j] = full;
			j++;
		}
		i++;
	}
	print_map(map);
}

void	solution(t_info tif, int index)
{
	tif.map = make_2p_char_memory(tif.col, tif.row);
	tif.dp = make_2p_int_memory(tif.col, tif.row);
	tif.coords[0] = 0;
	tif.coords[1] = 0;
	tif.coords[2] = 0;
	fill_map(tif.map, tif.buf, index);
	if (!check_map(&tif))
	{
		write(2, "map error\n", 11);
		return ;
	}
	fill_dp(&tif);
	put_result(tif.map, tif.coords, (tif.info)[2]);
}
