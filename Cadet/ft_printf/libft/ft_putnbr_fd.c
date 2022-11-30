/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:17:52 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/30 21:50:11 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_num(int n, int fd, int sign, int *cnt)
{
	if (n * sign >= 10)
		print_num(n / 10, fd, sign, cnt);
	ft_putchar_fd((n % 10) * sign + '0', fd);
	(*cnt)++;
}

int	ft_putnbr_fd(int n, int fd)
{
	int	sign;
	int	cnt;

	sign = 1;
	cnt = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign *= -1;
		cnt++;
	}
	if (n == -2147483648)
	{
		print_num(n / 10, fd, sign, &cnt);
		cnt += ft_putchar_fd('8', fd);
	}
	else
		print_num(n, fd, sign, &cnt);
	return (cnt);
}
