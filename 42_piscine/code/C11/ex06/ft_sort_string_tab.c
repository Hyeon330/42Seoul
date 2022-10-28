/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:19:06 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/20 23:39:05 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	q_sort(tab, 0, i - 1);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	int i;

	ft_sort_string_tab(argv);
	i = 0;
	while(i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
}*/
