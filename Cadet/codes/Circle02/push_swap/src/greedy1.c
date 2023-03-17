/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:30:15 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:51:06 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	run_cmd(t_deque *dq, t_cmd_info cmd)
{
	int	chk;

	chk = 1;
	while (chk && cmd.uda == cmd.udb && cmd.a && cmd.b)
	{
		chk = run(dq, RR + cmd.uda * 3);
		cmd.a--;
		cmd.b--;
	}
	while (chk && cmd.a--)
		chk = run(dq, RA + cmd.uda * 3);
	while (chk && cmd.b--)
		chk = run(dq, RB + cmd.udb * 3);
	return (chk && run(dq, PA));
}

int	greedy(t_deque *dq)
{
	t_node		*n[2];
	t_cmd_info	cmd_info[2];
	int			chk;

	chk = 1;
	while (chk && dq[1].size)
	{
		loop_b(dq, n, cmd_info);
		chk = run_cmd(dq, cmd_info[0]);
	}
	return (chk);
}
