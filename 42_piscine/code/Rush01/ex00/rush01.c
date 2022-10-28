/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:05:14 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/09 20:19:24 by chajung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		valid_chk(int map[4][5], int row, int col);
void	map_chk(int map[4][5], char *view);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	init_arr(int map[4][5])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			map[i][j] = '0';
			j++;
		}
		i++;
	}	
}

void	fill_map(int map[4][5], int row, int col, char *view)
{
	int	arr[4];
	int	i;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	i = 0;
	if (row == 4)
		map_chk(map, view);
	else
	{
		while (i < 4 && col < 4)
		{
			map[row][col] = arr[i];
			if (valid_chk(map, row, col) && col != 3)
				fill_map(map, row, col + 1, view);
			if (valid_chk(map, row, col) && col == 3)
				fill_map(map, row + 1, 0, view);
			map[row][col] = 0;
			i++;
		}
	}
}
