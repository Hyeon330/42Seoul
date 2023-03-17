/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:12:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:52:44 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

int	fix_a(t_deque *dq, int min)
{
	t_node	*n;
	size_t	i;
	size_t	chk_cmd;
	int		chk;

	n = dq[0].head;
	i = 0;
	while (n)
	{
		if (n->num == min)
			break ;
		n = n->next;
		i++;
	}
	chk_cmd = RA + ((dq[0].size >> 1) < i) * 3;
	chk = 1;
	while (chk && dq[0].head->num != min)
		chk = run(dq, chk_cmd);
	return (chk);
}

int	num_three(t_deque *dq)
{
	long	num[3];
	int		chk;

	num[0] = dq[0].head->num;
	num[1] = dq[0].head->next->num;
	num[2] = dq[0].head->next->next->num;
	if (num[0] < num[1] && num[1] < num[2])
		return (1);
	if (num[0] < num[1] && num[1] > num[2])
	{
		chk = run(dq, RRA);
		if (chk && num[2] > num[0])
			chk = run(dq, SA);
		return (chk);
	}
	if (num[0] > num[1] && num[1] < num[2])
	{
		if (num[2] > num[0])
			chk = run(dq, SA);
		else
			chk = run(dq, RA);
		return (chk);
	}
	return (run(dq, RA) && run(dq, SA));
}

int	under_three(t_deque *dq)
{
	if (dq[0].size == 1)
		return (1);
	if (dq[0].size == 2)
	{
		if (!run(dq, SA))
			return (-1);
		return (1);
	}
	if (dq[0].size == 3)
		return (num_three(dq));
	return (0);
}

int	push_swap(t_deque *dq)
{
	int	pi[2];
	int	min;
	int	under_three_chk;

	if (issort(dq[0]))
		return (1);
	under_three_chk = under_three(dq);
	if (under_three_chk > 0)
		return (1);
	if (under_three_chk < 0)
		return (0);
	return (set_pi(dq[0], pi, &min) && push(dq, pi) && \
			num_three(dq) && greedy(dq) && fix_a(dq, min));
}
