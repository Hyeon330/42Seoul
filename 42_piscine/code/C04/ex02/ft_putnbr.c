/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:00:30 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/06 12:50:03 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	num;

	num = (long) nb;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

/*int main(void)
{
	ft_putnbr(INT_MIN);
	return 0;
}*/
