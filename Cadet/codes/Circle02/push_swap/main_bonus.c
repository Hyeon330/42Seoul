/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 05:48:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/07 18:38:31 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	int		chk;

	if (ac == 1)
		ft_printf("Error\n");
	else
	{
		ft_memset(&dq, 0, sizeof(dq));
		if (!set_deque(&dq[0], av, ac))
		{
			ft_printf("Error\n");
			return (0);
		}
		chk = checker(dq);
		if (chk < 0)
			ft_printf("Error\n");
		else if (chk)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_nodes(dq[0].head);
	}
}
