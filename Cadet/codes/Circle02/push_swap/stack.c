/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:21:39 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/01/16 14:16:07 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **s, int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->num = num;
	new->next = *s;
	new->prev = NULL;
	if (*s)
		(*s)->prev = new;
	*s = new;
}

int	pop(t_stack **s)
{
	t_stack	*tmp;
	int		num;

	tmp = *s;
	*s = tmp->next;
	num = tmp->num;
	free(tmp);
	return (num);
}

int size(t_stack *s)
{
	int cnt;

	cnt = 0;
	while (s)
	{
		s = s->next;
		cnt++;
	}
	return (cnt);
}

int	isempty(t_stack *s)
{
	if (s)
		return (0);
	return (1);
}
