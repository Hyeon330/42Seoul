/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:27:54 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/17 08:25:35 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_putnbr(long nbr, long ori)
{
	char	c;

	if (nbr >= 10)
		ft_putnbr(nbr / 10, nbr);
	c = nbr % 10 + '0';
	write(1, &c, 1);
	if (nbr == ori)
		write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par -> str)
	{
		ft_putstr(par -> str);
		ft_putnbr(par -> size, par -> size);
		ft_putstr(par -> copy);
		par++;
	}
}
