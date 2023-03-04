/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 02:46:10 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/05 02:50:51 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cmd_info(t_cmd_info *cmd_info, int i)
{
	ft_memset(&cmd_info[i], 0, sizeof(t_cmd_info));
	if (i)
	{
		cmd_info[i].a = 1;
		cmd_info[i].uda = 0;
	}
	else
		cmd_info[i].cmd_tot = -1;
}

int	chk_position(t_node **n)
{
	return ((n[0]->num > n[0]->next->num && \
			(n[0]->next->num > n[1]->num || n[0]->num < n[1]->num)) || \
			(n[0]->num < n[1]->num && n[0]->next->num > n[1]->num));
}

void	loop_a(t_deque *dq, t_node **n, t_cmd_info *cmd_info, int b_i)
{
	init_cmd_info(cmd_info, 1);
	cmd_info[1].udb = (dq[1].size >> 1) < b_i;
	n[0] = dq[0].head;
	while (n[0])
	{
		if (n[0]->next)
		{
			if (chk_position(n))
				break ;
			cmd_info[1].a++;
		}
		else
			cmd_info[1].a = 0;
		n[0] = n[0]->next;
	}
}

void	set_cmd(t_deque *dq, t_node **n, t_cmd_info *cmd_info, int b_i)
{
	if ((dq[0].size >> 1) < cmd_info[1].a)
	{
		cmd_info[1].a = dq[0].size - cmd_info[1].a;
		cmd_info[1].uda = 1;
	}
	if (cmd_info[1].udb)
		cmd_info[1].b = dq[1].size - b_i;
	else
		cmd_info[1].b = b_i;
	if (cmd_info[1].uda == cmd_info[1].udb)
	{
		if (cmd_info[1].a < cmd_info[1].b)
			cmd_info[1].cmd_tot = cmd_info[1].b;
		else
			cmd_info[1].cmd_tot = cmd_info[1].a;
	}
	else
		cmd_info[1].cmd_tot = cmd_info[1].a + cmd_info[1].b;
	if (cmd_info[0].cmd_tot > cmd_info[1].cmd_tot)
		ft_memcpy(&cmd_info[0], &cmd_info[1], sizeof(t_cmd_info));
}

void	loop_b(t_deque *dq, t_node **n, t_cmd_info *cmd_info)
{
	int	b_i;

	init_cmd_info(cmd_info, 0);
	b_i = 0;
	n[1] = dq[1].head;
	while (n[1])
	{
		loop_a(dq, n, cmd_info, b_i);
		set_cmd(dq, n, cmd_info, b_i);
		if (cmd_info[0].cmd_tot <= 1)
			break ;
		n[1] = n[1]->next;
		b_i++;
	}
}
