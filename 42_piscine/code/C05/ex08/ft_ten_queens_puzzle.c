/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 02:26:05 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/12 18:32:03 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_queens_coord(int *coord)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = coord[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	absolute(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	ck_queen(int *coord, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (coord[col] == coord[i])
			return (0);
		if (absolute(coord[i] - coord[col]) == absolute(i - col))
			return (0);
		i++;
	}
	return (1);
}

void	recursive_ten_queens(int *coord, int col, int *result)
{
	int	i;

	i = 0;
	if (col == 10)
	{
		print_queens_coord(coord);
		*result += 1;
	}
	else
	{
		while (i < 10)
		{
			coord[col] = i;
			if (ck_queen(coord, col))
				recursive_ten_queens(coord, col + 1, result);
			i++;
		}
		coord[col] = -1;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	coord[10];
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < 10)
	{
		coord[i] = 0;
		i++;
	}
	recursive_ten_queens(coord, 0, &result);
	return (result);
}
