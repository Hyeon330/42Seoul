/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:12:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/03 22:52:17 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sp_three_area(t_deque *dq, int *pi)
{
	int	size;
	int	max;

	max = 0;
	size = dq[0].size;
	while (size--)
	{
		if (max < dq[0].head->num)
			max = dq[0].head->num;
		if (dq[0].head->num > pi[1])
			run(dq, 6);
		else
		{
			run(dq, 5);
			if (dq[1].head->num < pi[0])
				run(dq, 7);
		}
	}
	while (dq[0].size != 1)
	{
		if (dq[0].head->num == max)
			run(dq, 6);
		else
			run(dq, 5);
	}
}

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
		run(dq, 9 + cmd.udb * 3);
	run(dq, 4);
}

void	greedy(t_deque *dq, int max)
{
	t_node		*an;
	t_node		*bn;
	t_cmd_info	cmd;
	t_cmd_info	tmp;

	while (dq[1].size)
	{
		if (dq[0].size == 1)
			run(dq, 4);
		else
		{
			ft_memset(&cmd, 0, sizeof(cmd));
			ft_memset(&tmp, 0, sizeof(tmp));
			cmd.a = INT_MAX;
			cmd.b = INT_MAX;
			bn = dq[1].head;
			while (bn)
			{
				tmp.a = 1;
				tmp.uda = 0;
				tmp.push_num = bn->num;
				an = dq[0].head;
				while (an)
				{
					if (an->next)
					{
						if ((an->num == max && an->next->num > tmp.push_num) || \
							(an->num < tmp.push_num && an->next->num > tmp.push_num))
							break ;
						tmp.a++;
					}
					else
						tmp.a = 0;
					an = an->next;
				}
				if ((dq[0].size >> 1) < tmp.a)
				{
					tmp.a = dq[0].size - tmp.a;
					tmp.uda = 1;
				}
				if ((tmp.udb && cmd.a + cmd.b > tmp.a + (dq[0].size - tmp.b)) || \
					(!tmp.udb && cmd.a + cmd.b > tmp.a + tmp.b))
					ft_memcpy(&cmd, &tmp, sizeof(cmd));
				bn = bn->next;
				tmp.b++;
				if (!tmp.udb && (dq[1].size >> 1) < tmp.b)
					tmp.udb = 1;
			}
			run_cmd(dq, cmd);
		}
	}
}

void	fix_a(t_deque *dq, int max)
{
	t_node	*n;
	int		i;
	int		chk_cmd;

	n = dq[0].head;
	i = 0;
	while (n)
	{
		if (n->num == max)
			break ;
		n = n->next;
		i++;
	}
	chk_cmd = 6 + ((dq[0].size >> 1) < i) * 3;
	while (dq[0].tail->num != max)
		run(dq, chk_cmd);
}

int	push_swap(t_deque *dq)
{
	int	pi[2];
	int	max;

	if (dq[0].size == 2)
	{
		if (dq[0].head->num - dq[0].head->next->num > 0)
			run(dq, 1);
		return (1);
	}
	set_pi(dq[0], pi);
	sp_three_area(dq, pi);
	put(dq[0]);
	put(dq[1]);
	max = dq[0].head->num;
	greedy(dq, max);
	fix_a(dq, max);
	return (1);
}
