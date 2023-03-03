/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:21:44 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/03 22:03:31 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <stdio.h>

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
	int		uda;
	int		udb;
	int		push_num;
}	t_cmd_info;

void	put(t_deque dq);

// push_swap.c
int		push_swap(t_deque *dq);

// deque.c
void	add_head(t_deque *dq, int num);
void	add_tail(t_deque *dq, int num);
int		poll_head(t_deque *dq);
int		poll_tail(t_deque *dq);

// operations.c
void	s(t_deque *dq);
void	p(t_deque *dq1, t_deque *dq2);
void	r(t_deque *dq);
void	rr(t_deque *dq);

// sort.c
void	q_sort(int *arr, int left, int right);

// helpers.c
int		set_deque(t_deque *dq, char **av, int ac);
int		set_pi(t_deque dq, int *pi);

// run.c
void	run(t_deque *dq, int cmd);

// libft.a
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
