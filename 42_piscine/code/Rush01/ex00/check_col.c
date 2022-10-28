/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:54:43 by chajung           #+#    #+#             */
/*   Updated: 2022/10/09 20:00:36 by chajung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	col_u_chk(int map[4][5], char *view, int col)
{
	int	i;
	int	max;
	int	cnt;

	i = 0;
	max = 0;
	cnt = 0;
	while (i < 4)
	{
		if (map[i][col] > max)
		{
			max = map[i][col];
			cnt++;
		}
		i++;
	}
	if (cnt == view[2 * col] - 48)
		return (1);
	else
		return (0);
}

int	col_d_chk(int map[4][5], char *view, int col)
{
	int	i;
	int	max;
	int	cnt;

	i = 3;
	max = 0;
	cnt = 0;
	while (i >= 0)
	{
		if (map[i][col] > max)
		{
			max = map[i][col];
			cnt++;
		}
		i--;
	}
	if (cnt == view[2 * col + 8] - 48)
		return (1);
	else
		return (0);
}

int	col_ud_chk(int map[4][5], char *view)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!col_u_chk(map, view, i) || !col_d_chk(map, view, i))
			return (0);
		i++;
	}
	return (1);
}
