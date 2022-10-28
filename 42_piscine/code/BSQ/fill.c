/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:53:37 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/20 12:25:05 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_map(char **map, char *buf, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[index])
	{
		if (buf[index] == '\n')
		{
			i++;
			index++;
			j = 0;
		}
		map[i][j++] = buf[index++];
	}
}

void	search_sqare(int **dp, int *coords, int r, int c)
{
	if (coords[2] < dp[r][c])
	{
		coords[0] = r;
		coords[1] = c;
		coords[2] = dp[r][c];
	}
}

void	fill_one_row_col(char **map, int **dp, char *map_info, int *coords)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == map_info[0])
			dp[0][i] = 1;
		if (map[0][i] == map_info[1])
			dp[0][i] = 0;
		search_sqare(dp, coords, 0, i);
		i++;
	}
	i = 0;
	while (map[i][0])
	{
		if (map[i][0] == map_info[0])
			dp[i][0] = 1;
		if (map[i][0] == map_info[1])
			dp[i][0] = 0;
		search_sqare(dp, coords, i, 0);
		i++;
	}
}

void	inside(t_info *tif)
{
	int	r;
	int	c;
	int	min;

	r = 1;
	while (tif -> map[r][0])
	{
		c = 1;
		while (tif -> map[r][c])
		{
			min = tif -> dp[r - 1][c];
			if (min > tif -> dp[r - 1][c - 1])
				min = tif -> dp[r - 1][c - 1];
			if (min > tif -> dp[r][c - 1])
				min = tif -> dp[r][c - 1];
			if (tif -> map[r][c] == tif -> info[0])
				tif -> dp[r][c] = min + 1;
			if (tif -> map[r][c] == tif -> info[1])
				tif -> dp[r][c] = 0;
			search_sqare(tif -> dp, tif -> coords, r, c++);
		}
		r++;
	}
}

void	fill_dp(t_info *tif)
{
	fill_one_row_col(tif -> map, tif -> dp, tif -> info, tif -> coords);
	if (tif -> row <= 1 || tif -> col <= 1)
		return ;
	inside(tif);
}
