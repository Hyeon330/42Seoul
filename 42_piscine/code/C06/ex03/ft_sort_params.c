/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:27:37 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/12 21:04:21 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!(*s1 && *s2) || *s1 != *s2)
		return (*s1 - *s2);
	return (ft_strcmp(s1 + 1, s2 + 1));
}

void	q_sort(char *argv[], int left, int right)
{
	int		pl;
	int		pr;
	char	*pi;

	pl = left;
	pr = right;
	pi = argv[(pl + pr) / 2];
	while (pl <= pr)
	{
		while (ft_strcmp(argv[pl], pi) < 0)
			pl++;
		while (ft_strcmp(argv[pr], pi) > 0)
			pr--;
		if (pl <= pr)
			swap(&argv[pl++], &argv[pr--]);
	}
	if (left < pr)
		q_sort(argv, left, pr);
	if (pl < right)
		q_sort(argv, pl, right);
}

int	main(int argc, char *argv[])
{
	int	i;

	q_sort(argv, 1, argc - 1);
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}
