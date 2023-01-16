/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:21:45 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/01/16 22:39:28 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put(t_stack *s)
{
	while (s)
	{
		printf("%d\n", s->num);
		s = s->next;
	}
}

void	init_stack(t_stack **s)
{
	int	i;

	i = -1;
	while (++i < 4)
		s[i] = NULL;
}

void	error(void)
{
	write(2, "Error\n", 6);
}

long	ft_atoi(char *str, int *idx)
{
	long	num;
	int		sign;

	sign = 1;
	if (str[*idx] == '-')
		sign *= -1;
	if (str[*idx] == '-' || str[*idx] == '+')
		(*idx)++;
	num = 0;
	while (str[*idx] >= '0' && str[*idx] <= '9')
	{
		num *= 10;
		num += (str[*idx] - '0') * sign;
		(*idx)++;
	}
	return (num);
}

//	2147483647
//	-2147483648
//	"123 432" 421
int	set_stack(t_stack **s, char **av, int ac)
{
	long	num;
	int		i;
	int		j;
	char	**sp_av;

	while (--ac)
	{
		sp_av = ft_split(av[ac], ' ');
		i = -1;
		while (sp_av[++i])
			;
		while (sp_av[--i])
		{
			j = 0;
			num = ft_atoi(sp_av[i], &j);
			if (sp_av[i][j] && sp_av[i][j] != ' ' || \
				(num < INT_MIN || num > INT_MAX))
				return (0);
			push(s, (int)num);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*s[4];

	init_stack(s);
	if (ac > 1)
	{
		if (!set_stack(&s[0], av, ac))
		{
			error();
			return (0);
		}
		put(s[0]);
	}
	else
		error();
	return (0);
}
