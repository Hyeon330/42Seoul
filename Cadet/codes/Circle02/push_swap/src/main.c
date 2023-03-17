/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:49:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:51:52 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	free_nodes(t_node *n)
{
	t_node	*tmp;

	while (n)
	{
		tmp = n->next;
		free(n);
		n = tmp;
	}
}

int	main(int ac, char **av)
{
	t_deque	dq[2];

	if (ac > 1)
	{
		ft_memset(&dq, 0, sizeof(dq));
		if (!set_deque(&dq[0], av, ac))
		{
			ft_printf("Error\n");
			return (0);
		}
		if (!dq[0].size)
			return (0);
		if (!push_swap(dq))
		{
			ft_printf("Error\n");
			return (0);
		}
		free_nodes(dq[0].head);
		free_nodes(dq[1].head);
	}
}
