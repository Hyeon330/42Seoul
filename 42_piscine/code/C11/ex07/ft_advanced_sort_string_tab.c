/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:40:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/21 03:44:05 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (cmp(tab[i], tab[j]) > 0)
				swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	int i;

	ft_advanced_sort_string_tab(argv, ft_strcmp);
	i = 0;
	while(i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
}*/
