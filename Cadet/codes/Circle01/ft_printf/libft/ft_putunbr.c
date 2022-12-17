/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:55:45 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/30 22:31:35 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_num(unsigned int n, int *cnt)
{
	if (n >= 10)
		print_num(n / 10, cnt);
	*cnt += ft_putchar_fd(n % 10 + '0', 1);
}

int	ft_putunbr(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (!n)
		return (ft_putchar_fd('0', 1));
	print_num(n, &cnt);
	return (cnt);
}
