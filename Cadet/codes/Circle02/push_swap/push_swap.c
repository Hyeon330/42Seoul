/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:12:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/07 18:51:31 by hyeonsul         ###   ########.fr       */
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

void	fix_a(t_deque *dq, int min)
{
	t_node	*n;
	size_t	i;
	size_t	chk_cmd;

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

void	num_three(t_deque *dq)
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

int	under_three(t_deque *dq)
{
	if (dq[0].size == 1)
		return (1);
	if (dq[0].size == 2)
	{
		run(dq, 1);
		return (1);
	}
	if (dq[0].size == 3)
	{
		num_three(dq);
		return (1);
	}
	return (0);
}

int	push_swap(t_deque *dq)
{
	int	pi[2];
	int	min;

	if (issort(dq[0]))
		return (1);
	if (under_three(dq))
		return (1);
	set_pi(dq[0], pi, &min);
	if (dq[0].size > 50)
		sp_three_area(dq, pi);
	else
		push_b(dq);
	num_three(dq);
	greedy(dq);
	fix_a(dq, min);
	return (1);
}
