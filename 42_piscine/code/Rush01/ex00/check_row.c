/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:31:31 by chajung           #+#    #+#             */
/*   Updated: 2022/10/09 19:35:17 by chajung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	row_l_chk(int map[4][5], char *view, int row)
{
	int	i;
	int	max;
	int	cnt;

	i = 0;
	max = 0;
	cnt = 0;
	while (i < 4)
	{
		if (map[row][i] > max)
		{
			max = map[row][i];
			cnt++;
		}
		i++;
	}
	if (cnt == view[2 * row + 16] - 48)
		return (1);
	else
		return (0);
}

int	row_r_chk(int map[4][5], char *view, int row)
{
	int	i;
	int	max;
	int	cnt;

	i = 3;
	max = 0;
	cnt = 0;
	while (i >= 0)
	{
		if (map[row][i] > max)
		{
			max = map[row][i];
			cnt++;
		}
		i--;
	}
	if (cnt == view[2 * row + 24] - 48)
		return (1);
	else
		return (0);
}

int	row_lr_chk(int map[4][5], char *view)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!row_l_chk(map, view, i) || !row_r_chk(map, view, i))
			return (0);
		i++;
	}
	return (1);
}
