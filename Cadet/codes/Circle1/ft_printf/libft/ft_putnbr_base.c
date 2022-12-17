/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:50:36 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/30 22:41:02 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_num(unsigned long n, char *base, unsigned long base_len, \
		int *cnt)
{
	if (n >= base_len)
		print_num(n / base_len, base, base_len, cnt);
	*cnt += ft_putchar_fd(base[n % base_len], 1);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	cnt;

	cnt = 0;
	if (!n)
		return (ft_putchar_fd('0', 1));
	print_num(n, base, (unsigned long)ft_strlen(base), &cnt);
	return (cnt);
}
