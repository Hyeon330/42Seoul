/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 07:47:03 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:50:54 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

int	get_cmd(char *cmd)
{
	if (!ft_strncmp("sa\n", cmd, 3))
		return (SA);
	if (!ft_strncmp("sb\n", cmd, 3))
		return (SB);
	if (!ft_strncmp("ss\n", cmd, 3))
		return (SS);
	if (!ft_strncmp("pa\n", cmd, 3))
		return (PA);
	if (!ft_strncmp("pb\n", cmd, 3))
		return (PB);
	if (!ft_strncmp("ra\n", cmd, 3))
		return (RA);
	if (!ft_strncmp("rb\n", cmd, 3))
		return (RB);
	if (!ft_strncmp("rr\n", cmd, 3))
		return (RR);
	if (!ft_strncmp("rra\n", cmd, 4))
		return (RRA);
	if (!ft_strncmp("rrb\n", cmd, 4))
		return (RRB);
	if (!ft_strncmp("rrr\n", cmd, 4))
		return (RRR);
	return (0);
}

int	chk_sort(t_deque dq)
{
	t_node	*n;

	n = dq.head->next;
	while (n)
	{
		if (n->prev->num > n->num)
			return (0);
		n = n->next;
	}
	return (1);
}

int	checker(t_deque *dq)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (!run(dq, get_cmd(cmd)))
		{
			free(cmd);
			return (-1);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	if (dq[1].size || !chk_sort(dq[0]))
		return (0);
	return (1);
}
