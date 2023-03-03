/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:30:15 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/03 22:50:19 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	long	num;
	int		sign;
	int		i;

	sign = 1;
	i = -1;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = 0;
	while (str[++i] && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (str[i] - '0') * sign;
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

int	set_pi(t_deque dq, int *pi)
{
	t_node	*n;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * dq.size);
	if (!arr)
		return (0);
	n = dq.head;
	i = 0;
	while (n)
	{
		arr[i++] = n->num;
		n = n->next;
	}
	q_sort(arr, 0, dq.size - 1);
	i = -1;
	while (++i < dq.size)
		printf("%d ", arr[i]);
	printf("\n");
	pi[0] = arr[dq.size / 3];
	pi[1] = arr[(dq.size << 1) / 3];
	printf("%d %d\n", pi[0], pi[1]);
	free(arr);
	return (1);
}
