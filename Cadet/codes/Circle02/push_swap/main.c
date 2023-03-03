/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:49:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/03 22:46:00 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put(t_deque dq)
{
	t_node	*n;

	n = dq.head;
	while (n)
	{
		printf("%d ", n->num);
		n = n->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_deque	dq[2];

	ft_memset(&dq, 0, sizeof(dq));
	if (ac == 2)
		return (0);
	if (ac > 1)
	{
		if (!set_deque(&dq[0], av, ac) || !push_swap(dq))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		put(dq[0]);
	}
	else
		write(2, "Error\n", 6);
}
