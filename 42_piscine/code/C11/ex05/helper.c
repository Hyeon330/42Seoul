/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:22:37 by chajung           #+#    #+#             */
/*   Updated: 2022/10/21 00:18:20 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_print(nb / 10);
		ft_print(nb % 10);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	ft_print(nb);
}

int	check_isspace(char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (check_isspace(str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
