/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:15 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/01/16 15:26:12 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack **s)
{
	int	tmp1;
	int	tmp2;

	if (size(*s) > 1)
	{
		tmp1 = pop(s);
		tmp2 = pop(s);
		push(s, tmp1);
		push(s, tmp2);
	}
}

void	p(t_stack **s1, t_stack **s2, t_stack **s1_t, t_stack **s2_t)
{
	if (!isempty(*s2))
	{
		push(s1, pop(s2));
		if (size(*s1) == 1)
			*s1_t = *s1;
		if (isempty(*s2))
			*s2_t = NULL;
	}
}

void	r(t_stack **s, t_stack **tail)
{
	if (size(*s) > 1)
	{
		(*tail)->next = *s;
		(*s)->prev = *tail;
		*s = (*s)->next;
		(*s)->prev = NULL;
		*tail = (*tail)->next;
		(*tail)->next = NULL;
	}
}

void	rr(t_stack **s, t_stack **tail)
{
	if (size(*s) > 1)
	{
		(*s)->prev = *tail;
		(*tail)->next = *s;
		*tail = (*tail)->prev;
		(*tail)->next = NULL;
		*s = (*s)->prev;
		(*s)->prev = NULL;
	}
}
