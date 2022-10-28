/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amukhame <amukhame@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:36:54 by amukhame          #+#    #+#             */
/*   Updated: 2022/10/20 12:12:56 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_printable(char c)
{
	if ((c <= 126) && (c >= 32))
		return (1);
	else
		return (0);
}

int	is_char(char *info, char c)
{
	int	i;

	i = 0;
	while (info[i])
	{
		if (c == info[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_full(char *info, char c)
{
	if (c == info[2])
		return (1);
	return (0);
}

int	check_dup(char *info)
{
	if (info[0] == info[1] || info[0] == info[2] || info[1] == info[2])
		return (0);
	return (1);
}

int	check_map(t_info *tif)
{
	int	i;
	int	j;

	if (tif -> row < 1 || tif -> col < 1)
		return (0);
	if (!check_dup(tif -> info))
		return (0);
	i = 0;
	while (i < tif -> row)
	{
		j = 0;
		while (j < tif -> col)
		{
			if (!is_char(tif -> info, (tif -> map)[i][j])
					|| !is_printable((tif -> map[i][j])) \
					|| is_full(tif -> info, (tif -> map)[i][j]))
				return (0);
			j++;
		}
		if (j != tif -> col)
			return (0);
		i++;
	}
	return (1);
}
