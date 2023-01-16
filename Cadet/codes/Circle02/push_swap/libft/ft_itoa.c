/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:36:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/11 22:31:24 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cnt_size(int n)
{
	int	cnt;

	cnt = 0;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

void	input_pc(char *pc, int n, int n_size, int sign)
{
	while (n)
	{
		pc[--n_size] = (n % 10) * sign + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*pc;
	int		sign;
	int		n_size;

	n_size = cnt_size(n);
	if (!n)
		return (ft_strdup("0"));
	sign = 1;
	if (n < 0)
		pc = (char *)malloc(sizeof(char) * ++n_size + 1);
	else
		pc = (char *)malloc(sizeof(char) * n_size + 1);
	if (!pc)
		return (NULL);
	pc[n_size] = 0;
	if (n < 0)
	{
		pc[0] = '-';
		sign *= -1;
	}
	input_pc(pc, n, n_size, sign);
	return (pc);
}
