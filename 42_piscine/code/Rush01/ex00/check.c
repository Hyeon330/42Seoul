/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:02:51 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/09 20:01:11 by chajung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		row_lr_chk(int map[4][5], char *view);
int		col_ud_chk(int map[4][5], char *view);
void	ft_putchar(char c);

int	valid_chk(int map[4][5], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (i != col && map[row][i] == map[row][col])
			return (0);
		i++;
	}
	while (j < 4)
	{
		if (j != row && map[j][col] == map[row][col])
			return (0);
		j++;
	}
	return (1);
}

void	map_chk(int map[4][5], char *view)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (row_lr_chk(map, view) && col_ud_chk(map, view))
	{
		while (i < 4)
		{
			j = 0;
			while (j < 3)
			{
				ft_putchar(map[i][j] + '0');
				ft_putchar(' ');
				j++;
			}
			ft_putchar(map[i][j] + '0');
			ft_putchar('\n');
			i++;
		}
		map[3][4] = 1;
	}
}
