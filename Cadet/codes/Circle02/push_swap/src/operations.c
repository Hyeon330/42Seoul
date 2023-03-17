/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:43:30 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:52:14 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	s(t_deque *dq)
{
	int	tmp1;
	int	tmp2;

	if (dq->size > 1)
	{
		tmp1 = poll_head(dq);
		tmp2 = poll_head(dq);
		if (!add_head(dq, tmp1))
			return (0);
		if (!add_head(dq, tmp2))
			return (0);
	}
	return (1);
}

int	p(t_deque *dq1, t_deque *dq2)
{
	if (dq2->size > 0)
		return (add_head(dq1, poll_head(dq2)));
	return (1);
}

int	r(t_deque *dq)
{
	if (dq->size > 1)
		return (add_tail(dq, poll_head(dq)));
	return (1);
}

int	rr(t_deque *dq)
{
	if (dq->size > 1)
		return (add_head(dq, poll_tail(dq)));
	return (1);
}
