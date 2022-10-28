/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:18:08 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/15 17:55:22 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	_range;
	int	i;

	if (min >= max)
		return (0);
	_range = max - min;
	*range = (int *)malloc(sizeof(int) * _range);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < _range)
		range[0][i++] = min++;
	return (_range);
}

/*int main(void)
{
	int *range;
	int min;
	int max;
	int i;

	min = 3;
	max = 6;
	
	printf("return %d\n", ft_ultimate_range(&range, min, max));
	i = 0;
	while (i < max - min)
		printf("%d\n", range[i++]);
	return 0;
}*/
