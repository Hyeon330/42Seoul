/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:48:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:53:04 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

int	run(t_deque *dq, int c)
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
