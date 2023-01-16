/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:21:44 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/01/16 21:53:35 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <stdio.h>

typedef struct s_stack {
	struct s_stack	*prev;
	struct s_stack	*next;
	int				num;
}	t_stack;

// stack.c
void	push(t_stack **s, int num);
int		pop(t_stack **s);
int		size(t_stack *s);
int		isempty(t_stack *s);

// operations.c
void	s(t_stack **s);
void	p(t_stack **s1, t_stack **s2, t_stack **s1_t, t_stack **s2_t);
void	r(t_stack **s, t_stack **tail);
void	rr(t_stack **s, t_stack **tail);

// libft
char	**ft_split(char const *s, char c);

#endif
