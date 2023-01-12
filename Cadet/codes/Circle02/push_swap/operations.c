/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:15 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/01/12 17:39:00 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

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

void	p(t_stack **s1, t_stack **s2)
{
	if (!isempty(*s2))
		push(s1, pop(s2));
}

void	r(t_stack **s)
{
	if (size(*s) > 1)
}
