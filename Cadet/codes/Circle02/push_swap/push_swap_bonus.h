/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:21:44 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/07 18:08:57 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

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

// deque_bonus.c
void	add_head(t_deque *dq, int num);
void	add_tail(t_deque *dq, int num);
int		poll_head(t_deque *dq);
int		poll_tail(t_deque *dq);

// operations_bonus.c
void	s(t_deque *dq);
void	p(t_deque *dq1, t_deque *dq2);
void	r(t_deque *dq);
void	rr(t_deque *dq);

// set_deque_bonus.c
int		set_deque(t_deque *dq, char **av, int ac);

// checker_bonus.c
int		checker(t_deque *dq);

// run_bonus.c
int		run(t_deque *dq, int cmd);

// libftprintf.a
int		ft_printf(const char *format, ...);

// libgnl.a
char	*get_next_line(int fd);

// libft.a
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
