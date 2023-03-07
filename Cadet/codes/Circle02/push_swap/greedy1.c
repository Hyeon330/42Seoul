/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:30:15 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/05 02:51:53 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_cmd(t_deque *dq, t_cmd_info cmd)
{
	if (cmd.uda == cmd.udb)
	{
		while (cmd.a && cmd.b)
		{
			run(dq, 8 + cmd.uda * 3);
			cmd.a--;
			cmd.b--;
		}
	}
	while (cmd.a--)
		run(dq, 6 + cmd.uda * 3);
	while (cmd.b--)
		run(dq, 7 + cmd.udb * 3);
	run(dq, 4);
}

void	greedy(t_deque *dq)
{
	t_node		*n[2];
	t_cmd_info	cmd_info[2];

	while (dq[1].size)
	{
		loop_b(dq, n, cmd_info);
		run_cmd(dq, cmd_info[0]);
	}
}
