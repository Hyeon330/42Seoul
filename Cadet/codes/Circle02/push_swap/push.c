/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:22:08 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/07 18:16:51 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sp_three_area(t_deque *dq, int *pi)
{
	int	size;

	size = dq[0].size;
	while (size--)
	{
		if (dq[0].head->num > pi[1])
			run(dq, 6);
		else
		{
			run(dq, 5);
			if (dq[1].head->num < pi[0])
				run(dq, 7);
		}
	}
	while (dq[0].size > 3)
		run(dq, 5);
}

void	push_b(t_deque *dq)
{
	int	size;
	int	min;

	min = INT_MIN;
	size = dq[0].size - 3;
	while (size--)
		run(dq, 5);
}
