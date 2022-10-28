/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:29:58 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/11 17:37:23 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_ck(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	print_nbr_base(long num, char *base, long base_len)
{
	if (num >= base_len)
		print_nbr_base(num / base_len, base, base_len);
	ft_putchar(base[num % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	long	base_len;

	num = (long) nbr;
	base_len = base_ck(base);
	if (base_len > 1)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num *= -1;
		}
		print_nbr_base(num, base, base_len);
	}
}
