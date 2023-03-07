/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_deque_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:30:15 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/05 07:56:25 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atoi(char *str)
{
	long	num;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (str[i++] - '0') * sign;
	}
	if (str[i])
		return ((long)INT_MAX + 1);
	return (num);
}

int	isdup(t_deque *dq, int num)
{
	t_node	*node;

	node = dq->head;
	while (node)
	{
		if (node->num == num)
			return (1);
		node = node->next;
	}
	return (0);
}

int	set_deque(t_deque *dq, char **av, int ac)
{
	char	**sp_av;
	long	num;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		sp_av = ft_split(av[i], ' ');
		j = -1;
		while (sp_av[++j])
		{
			num = ft_atoi(sp_av[j]);
			if (num < INT_MIN || num > INT_MAX || isdup(dq, (int)num))
			{
				free(sp_av);
				return (0);
			}
			add_tail(dq, (int)num);
		}
		free(sp_av);
	}
	return (1);
}
