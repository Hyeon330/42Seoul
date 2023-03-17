/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:22:08 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:52:35 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	sp_three_area(t_deque *dq, int *pi)
{
	int	size;
	int	chk;

	chk = 1;
	size = dq[0].size;
	while (chk && size--)
	{
		if (dq[0].head->num > pi[1])
			chk = run(dq, RA);
		else
		{
			chk = run(dq, PB);
			if (dq[1].head->num < pi[0])
				chk = run(dq, RB);
		}
	}
	while (chk && dq[0].size > 3)
		chk = run(dq, PB);
	return (chk);
}

int	push_b(t_deque *dq)
{
	int	size;
	int	chk;

	chk = 1;
	size = dq[0].size - 3;
	while (size-- && chk)
		chk = run(dq, PB);
	return (chk);
}

int	push(t_deque *dq, int *pi)
{
	if (dq[0].size > 50)
		return (sp_three_area(dq, pi));
	else
		return (push_b(dq));
}
