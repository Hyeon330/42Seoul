/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:47:39 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/02/27 15:14:02 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isloop(t_deque *dq)
{
	t_node	*n;

	n = dq[0].head;
	while (n->next)
	{
		if (n->num - n->next->num > 0)
			return (1);
		n = n->next;
	}
	return (0);
}

int	cmd(t_deque dq)
{
	t_node	*n;
	int		min;
	int		min_i;
	int		i;

	min = INT_MAX;
	i = 0;
	n = dq.head;
	while (++i <= dq.size)
	{
		if (min >= n->num)
		{
			min = n->num;
			min_i = i;
		}
		n = n->next;
	}
	if (min_i == 1)
		return (5);
	if ((dq.size >> 1) + (dq.size & 1) >= min_i)
		return (6);
	else
		return (9);
}

void	left_three(t_deque *dq)
{
	int	compare[3];

	compare[0] = dq[0].head->num - dq[0].head->next->num;
	compare[1] = dq[0].head->next->num - dq[0].head->next->next->num;
	compare[2] = dq[0].head->next->next->num - dq[0].head->num;
	if (compare[0] < 0 && compare[1] < 0)
		return ;
	if (compare[0] < 0 && compare[1] > 0)
	{
		run(dq, 9);
		if (compare[2] > 0)
			run(dq, 1);
		return ;
	}
	if (compare[0] > 0 && compare[1] < 0)
	{
		if (compare[2] > 0)
			run(dq, 1);
		else
			run(dq, 6);
		return ;
	}
	run(dq, 6);
	run(dq, 1);
}

void	push_swap(t_deque *dq)
{   
	while (isloop(dq))
	{
		if (dq[0].size <= 3)
		{
			left_three(dq);
			break ;
		}
		else
			run(dq, cmd(dq[0]));
	}
	while (dq[1].size > 0)
		run(dq, 4);
}