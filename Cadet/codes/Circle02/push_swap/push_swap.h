/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:21:44 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/01/12 17:01:23 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_stack {
	struct s_stack	*next;
	int				num;
}	t_stack;

// stack.c
void	push(t_stack **s, int num);
int	pop(t_stack **s);
int	size(t_stack *s);
int	isempty(t_stack *s);

#endif
