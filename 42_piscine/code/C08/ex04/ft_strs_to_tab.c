/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:09:22 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/17 08:25:17 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*pc;
	int		i;

	pc = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		pc[i] = str[i];
		i++;
	}
	pc[i] = 0;
	return (pc);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock_arr;

	stock_arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_arr)
		return ((void *) 0);
	i = 0;
	while (i < ac)
	{
		stock_arr[i].size = ft_strlen(av[i]);
		stock_arr[i].str = av[i];
		stock_arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock_arr[i].str = 0;
	return (stock_arr);
}
