/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:49:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/02/25 03:36:15 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put(t_deque dq)
{
	t_node	*n;

	n = dq.head;
	while (n)
	{
		printf("%d\n", n->num);
		n = n->next;
	}
}

void	init_deque(t_deque *dq)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		dq[i].head = NULL;
		dq[i].tail = NULL;
		dq[i].size = 0;
	}
}

int	main(int ac, char **av)
{
	t_deque	dq[2];

	init_deque(dq);
	if (ac > 1)
	{
		if (!set_deque(&dq[0], av, ac))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		put(dq[0]);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
