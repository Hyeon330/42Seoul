/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:21:44 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/12 17:22:45 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648L
# define INT_MAX 2147483647L

enum e_op {
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	int				num;
}	t_node;

typedef struct s_deque {
	struct s_node	*head;
	struct s_node	*tail;
	size_t			size;
}	t_deque;

typedef struct s_cmd_info {
	size_t	a;
	size_t	b;
	size_t	cmd_tot;
	int		uda;
	int		udb;
}	t_cmd_info;

// push_swap.c
int		push_swap(t_deque *dq);

// push.c
int		push(t_deque *dq, int *pi);

// deque.c
int		add_head(t_deque *dq, int num);
int		add_tail(t_deque *dq, int num);
int		poll_head(t_deque *dq);
int		poll_tail(t_deque *dq);

// operations.c
int		s(t_deque *dq);
int		p(t_deque *dq1, t_deque *dq2);
int		r(t_deque *dq);
int		rr(t_deque *dq);

// sort.c
void	q_sort(int *arr, int left, int right);
int		issort(t_deque dq);

// set_deque.c
int		set_deque(t_deque *dq, char **av, int ac);

// run.c
int		run(t_deque *dq, int cmd);

// greedy1.c
int		greedy(t_deque *dq);

// greedy2.c
void	loop_b(t_deque *dq, t_node **n, t_cmd_info *cmd_info);

// libftprintf.a
int		ft_printf(const char *format, ...);

// libft.a
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isdigit(int c);

#endif
