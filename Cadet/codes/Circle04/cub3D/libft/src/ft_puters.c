/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:49:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 20:51:50 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	input_str(char *pc, char *str, t_args *lst)
{
	int	i;

	i = -1;
	while (++i < lst->arg_size)
	{
		if (!str)
			pc[i] = "(null)"[i];
		else
			pc[i] = str[i];
	}
}

void	input_hex(char *pc, unsigned long num, char spec)
{
	char	*hex;

	if (spec == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	input_num_base(pc, num, hex, 16);
}

void	input_int(char *pc, int num)
{
	char	*dec;
	int		sign;
	int		i;

	dec = "0123456789";
	sign = 1;
	i = 0;
	if (num < 0)
	{
		sign = -1;
		while (*(pc - ++i) == '0')
			;
		*(pc - i) = '-';
	}
	if (num == -2147483648)
	{
		input_num_base(pc, num / 10 * sign, dec, 10);
		*(pc + 9) = '8';
	}
	else
		input_num_base(pc, num * sign, dec, 10);
}

void	input_num_base(char *pc, unsigned long num, char *base, int base_len)
{
	int		left;
	int		right;
	char	tmp;

	right = 0;
	if (!num)
		pc[0] = '0';
	while (num)
	{
		pc[right++] = base[num % base_len];
		num /= base_len;
	}
	left = -1;
	while (++left < --right)
	{
		tmp = pc[left];
		pc[left] = pc[right];
		pc[right] = tmp;
	}
}
