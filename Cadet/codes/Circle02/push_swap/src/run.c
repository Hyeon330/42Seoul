/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:48:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:52:54 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	run1(t_deque *dq, int c)
{
	if (c == SA)
		return (s(&dq[0]));
	if (c == SB)
		return (s(&dq[1]));
	if (c == SS)
		return (s(&dq[0]) && s(&dq[1]));
	if (c == PA)
		return (p(&dq[0], &dq[1]));
	if (c == PB)
		return (p(&dq[1], &dq[0]));
	if (c == RA)
		return (r(&dq[0]));
	if (c == RB)
		return (r(&dq[1]));
	if (c == RR)
		return (r(&dq[0]) && r(&dq[1]));
	if (c == RRA)
		return (rr(&dq[0]));
	if (c == RRB)
		return (rr(&dq[1]));
	if (c == RRR)
		return (rr(&dq[0]) && rr(&dq[1]));
	return (0);
}

void	run2(int c)
{
	if (c == SA)
		ft_printf("sa\n");
	if (c == SB)
		ft_printf("sb\n");
	if (c == SS)
		ft_printf("ss\n");
	if (c == PA)
		ft_printf("pa\n");
	if (c == PB)
		ft_printf("pb\n");
	if (c == RA)
		ft_printf("ra\n");
	if (c == RB)
		ft_printf("rb\n");
	if (c == RR)
		ft_printf("rr\n");
	if (c == RRA)
		ft_printf("rra\n");
	if (c == RRB)
		ft_printf("rrb\n");
	if (c == RRR)
		ft_printf("rrr\n");
}

int	run(t_deque *dq, int cmd)
{
	if (run1(dq, cmd))
	{
		run2(cmd);
		return (1);
	}
	return (0);
}
