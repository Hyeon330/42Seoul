/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:53:02 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/20 12:25:32 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	max_y_len(t_info *tif, int *i)
{
	int	j;
	int	k;
	int	cnt;

	while ((tif -> buf)[*i] != '\n')
		(*i)++;
	cnt = 0;
	j = 0;
	while (j < *i - 3)
	{
		cnt *= 10;
		cnt += (tif -> buf)[j] - '0';
		j++;
	}
	k = 0;
	while (j < *i)
		(tif -> info)[k++] = (tif -> buf)[j++];
	return (cnt);
}

int	max_x_len(t_info *tif, int i)
{
	int	cnt;
	int	max;
	int	j;

	j = 0;
	max = 0;
	cnt = 0;
	while (j < tif -> row)
	{
		cnt = 0;
		while ((tif -> buf)[i++] != '\n')
			cnt++;
		if (max < cnt)
			max = cnt;
		j++;
	}
	return (max);
}
