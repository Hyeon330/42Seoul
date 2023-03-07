/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:49:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/07 18:52:18 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (ac == 1)
		ft_printf("Error\n");
	else
	{
		ft_memset(&dq, 0, sizeof(dq));
		if (!set_deque(&dq[0], av, ac) || !push_swap(dq))
			ft_printf("Error\n");
		free_nodes(dq[0].head);
	}
}
