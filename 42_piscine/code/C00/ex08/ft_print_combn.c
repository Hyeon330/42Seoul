/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:53:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/01 04:00:52 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char str[], int byte)
{
	write(1, str, byte);
}

void	fun(char num[], int i, int cycle, int byte)
{
	if (i == 0)
		num[i] = '0';
	else
		num[i] = num[i - 1] + 1;
	while (num[i] <= 10 - cycle + 48)
	{
		if (i != byte - 1)
			fun(num, i + 1, cycle - 1, byte);
		else
		{
			ft_putstr(num, byte);
			if (!(num[i] == '9' && num[0] == 10 - byte + 48))
				ft_putstr(", ", 2);
		}
		num[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	num[10];

	fun(num, 0, n, n);
}

/*int	main(void)
{
	ft_print_combn(1);
	return 0;
}*/
