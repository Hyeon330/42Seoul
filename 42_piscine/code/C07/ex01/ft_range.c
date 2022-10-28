/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:03:43 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/15 17:51:56 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	i;
	int	*pi;

	if (min >= max)
		return ((void *) 0);
	range = max - min;
	pi = (int *)malloc(sizeof(int) * range);
	i = 0;
	while (i < range)
		pi[i++] = min++;
	return (pi);
}

/*int main(void)
{
	int *pi;
	int i;
	int n1;
	int n2;

	n1 = 3;
	n2 = 6;
	pi = ft_range(n1, n2);
	i = 0;
	while (i < n2 - n1)
		printf("%d\n", pi[i++]);
	return 0;
}*/
