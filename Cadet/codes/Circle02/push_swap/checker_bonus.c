/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 07:47:03 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/07 18:12:42 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_cmd(char *cmd)
{
	if (!ft_strncmp("sa\n", cmd, 3))
		return (1);
	if (!ft_strncmp("sb\n", cmd, 3))
		return (2);
	if (!ft_strncmp("ss\n", cmd, 3))
		return (3);
	if (!ft_strncmp("pa\n", cmd, 3))
		return (4);
	if (!ft_strncmp("pb\n", cmd, 3))
		return (5);
	if (!ft_strncmp("ra\n", cmd, 3))
		return (6);
	if (!ft_strncmp("rb\n", cmd, 3))
		return (7);
	if (!ft_strncmp("rr\n", cmd, 3))
		return (8);
	if (!ft_strncmp("rra", cmd, 3))
		return (9);
	if (!ft_strncmp("rrb", cmd, 3))
		return (10);
	if (!ft_strncmp("rrr", cmd, 3))
		return (11);
	else
		return (0);
}

int	chk(t_deque dq)
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
			return (-1);
		cmd = get_next_line(0);
	}
	if (dq[1].size || !chk(dq[0]))
		return (0);
	return (1);
}
