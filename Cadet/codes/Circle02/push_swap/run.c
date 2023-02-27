/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:48:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/02/27 15:12:58 by hyeonsul         ###   ########.fr       */
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
		printf("%s\n", "sa");
	if (c == 2)
		printf("%s\n", "sb");
	if (c == 3)
		printf("%s\n", "ss");
	if (c == 4)
		printf("%s\n", "pa");
	if (c == 5)
		printf("%s\n", "pb");
	if (c == 6)
		printf("%s\n", "ra");
	if (c == 7)
		printf("%s\n", "rb");
	if (c == 8)
		printf("%s\n", "rr");
	if (c == 9)
		printf("%s\n", "rra");
	if (c == 10)
		printf("%s\n", "rrb");
	if (c == 11)
		printf("%s\n", "rrr");
}

void	run(t_deque *dq, int cmd)
{
	run1(dq, cmd);
	run2(cmd);
}
