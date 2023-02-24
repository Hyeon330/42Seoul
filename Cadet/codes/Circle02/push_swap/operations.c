/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:43:30 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/02/25 03:27:06 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_deque *dq)
{
	int	tmp1;
	int	tmp2;

	if (dq->size > 1)
	{
		tmp1 = poll_head(dq);
		tmp2 = poll_head(dq);
		add_head(dq, tmp1);
		add_head(dq, tmp2);
	}
}

void	p(t_deque *dq1, t_deque *dq2)
{
	if (dq2->size > 0)
		add_head(dq1, poll_head(dq2));
}

void	r(t_deque *dq)
{
	if (dq->size > 1)
		add_tail(dq, poll_head(dq));
}

void	rr(t_deque *dq)
{
	if (dq->size > 1)
		add_head(dq, poll_tail(dq));
}
