/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:48:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/05 06:48:01 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run1(t_deque *dq, int c)
{
	if (c == 1 || c == 3)
		s(&dq[0]);
	if (c == 2 || c == 3)
		s(&dq[1]);
	if (c == 4)
		p(&dq[0], &dq[1]);
	if (c == 5)
		p(&dq[1], &dq[0]);
	if (c == 6 || c == 8)
		r(&dq[0]);
	if (c == 7 || c == 8)
		r(&dq[1]);
	if (c == 9 || c == 11)
		rr(&dq[0]);
	if (c == 10 || c == 11)
		rr(&dq[1]);
}

void	run2(int c)
{
	if (c == 1)
		ft_printf("sa\n");
	if (c == 2)
		ft_printf("sb\n");
	if (c == 3)
		ft_printf("ss\n");
	if (c == 4)
		ft_printf("pa\n");
	if (c == 5)
		ft_printf("pb\n");
	if (c == 6)
		ft_printf("ra\n");
	if (c == 7)
		ft_printf("rb\n");
	if (c == 8)
		ft_printf("rr\n");
	if (c == 9)
		ft_printf("rra\n");
	if (c == 10)
		ft_printf("rrb\n");
	if (c == 11)
		ft_printf("rrr\n");
}

void	run(t_deque *dq, int cmd)
{
	run1(dq, cmd);
	run2(cmd);
}