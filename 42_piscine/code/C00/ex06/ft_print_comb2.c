/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:44:51 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/09/29 18:03:57 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	num[5];
	int		i;
	int		j;

	i = 0;
	num[2] = ' ';
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			num[0] = i / 10 + 48;
			num[1] = i % 10 + 48;
			num[3] = j / 10 + 48;
			num[4] = j % 10 + 48;
			write(1, num, 5);
			if (!(i == 98 && j == 99))
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
/*int main(void)
{
	ft_print_comb2();
	return 0;
}*/
