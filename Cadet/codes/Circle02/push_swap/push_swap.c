/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:12:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/05 02:49:27 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_pi(t_deque dq, int *pi, int *min)
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
	pi[0] = arr[dq.size / 3];
	pi[1] = arr[(dq.size << 1) / 3];
	*min = arr[0];
	free(arr);
	return (1);
}

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
	while (dq[0].size > 2)
		run(dq, 5);
}

void	fix_a(t_deque *dq, int min)
{
	t_node	*n;
	int		i;
	int		chk_cmd;

	n = dq[0].head;
	i = 0;
	while (n)
	{
		if (n->num == min)
			break ;
		n = n->next;
		i++;
	}
	chk_cmd = 6 + ((dq[0].size >> 1) < i) * 3;
	while (dq[0].head->num != min)
		run(dq, chk_cmd);
}

int	push_swap(t_deque *dq)
{
	int	pi[2];
	int	min;

	if (dq[0].size == 2)
	{
		if (dq[0].head->num - dq[0].head->next->num > 0)
			run(dq, 1);
		return (1);
	}
	set_pi(dq[0], pi, &min);
	sp_three_area(dq, pi);
	greedy(dq);
	fix_a(dq, min);
	return (1);
}
