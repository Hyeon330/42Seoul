/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:51:52 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/20 00:36:07 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**make_2p_int_memory(int x, int y)
{
	int	i;
	int	j;
	int	**ppi;

	ppi = (int **)malloc(sizeof(int *) * y);
	i = 0;
	while (i < y)
	{
		ppi[i] = (int *)malloc(sizeof(int) * x);
		j = 0;
		while (j < x)
		{
			ppi[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ppi);
}

char	**make_2p_char_memory(int x, int y)
{
	int		i;
	int		j;
	char	**ppc;

	ppc = (char **)malloc(sizeof(char *) * (y + 1));
	i = 0;
	while (i <= y)
	{
		ppc[i] = (char *)malloc(sizeof(char) * (x + 1));
		j = 0;
		while (j <= x)
		{
			ppc[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ppc);
}
