/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:10:54 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/21 03:33:01 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if (f(tab[i]))
			cnt++;
		i++;
	}
	return (cnt);
}
/*int fff(char *a)
{
	(void) a;
	return 1;
}

#include <stdio.h>
int main(int ac, char *av[])
{
	printf("%d", ft_count_if(av, ac, fff));
}*/
