/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_counters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:44:21 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/10/05 23:14:04 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_str(char *str, t_args *lst)
{
	int	cnt;

	cnt = 0;
	if (str && lst->prec_cnt)
	{
		while (cnt < lst->prec_size && str[cnt])
			cnt++;
		return (cnt);
	}
	else if (str)
		return (ft_strlen(str));
	else if (lst->prec_cnt)
	{
		if (lst->prec_size > 6)
			return (6);
		else
			return (lst->prec_size);
	}
	else
		return (6);
}

int	count_int(int n, t_args *lst)
{
	int	cnt;

	cnt = 0;
	if (!n && !lst->prec_cnt)
		return (1);
	if (n < 0)
	{
		lst->minus = 1;
		lst->flag_size = 1;
		if (!lst->flag)
			lst->flag = ' ';
	}
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

int	count_uint(unsigned int n, t_args *lst)
{
	int	cnt;

	cnt = 0;
	if (!n && !lst->prec_cnt)
		return (1);
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

int	count_hex(unsigned long n, t_args *lst)
{
	int	cnt;

	cnt = 0;
	if (!n)
	{
		if (lst->spec == 'x' || lst->spec == 'X')
		{
			lst->flag = 0;
			lst->flag_size = 0;
		}
		if (lst->prec_cnt)
			return (0);
		else
			return (1);
	}
	while (n)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}
