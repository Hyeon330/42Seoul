/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_deque.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:30:15 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:53:19 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	free_sp(char **sp)
{
	int	i;

	i = -1;
	while (sp[++i])
		free(sp[i]);
	free(sp);
}

int	set_num(char *str, long *num)
{
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	*num = 0;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] && ft_isdigit(str[i]))
	{
		*num *= 10;
		*num += (str[i++] - '0') * sign;
		if (*num < INT_MIN || *num > INT_MAX)
			return (0);
	}
	if (str[i])
		return (0);
	return (1);
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
		if (!sp_av)
			return (0);
		j = -1;
		while (sp_av[++j])
		{
			if (!set_num(sp_av[j], &num) || \
				isdup(dq, (int)num) || \
				!add_tail(dq, (int)num))
			{
				free_sp(sp_av);
				return (0);
			}
		}
		free_sp(sp_av);
	}
	return (1);
}
