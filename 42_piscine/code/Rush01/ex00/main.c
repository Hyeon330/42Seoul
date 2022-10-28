/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:56:30 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/09 19:19:49 by chajung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_arr(int map[4][5]);
void	fill_map(int map[4][5], int row, int col, char *view);
void	error(void);

int	main(int argc, char *argv[])
{
	int	map[4][5];

	if (argc == 2)
	{
		init_arr(map);
		fill_map(map, 0, 0, argv[1]);
		if (map[3][4] != 1)
			error();
	}
	else
		error();
}
