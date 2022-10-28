/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:11:23 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/01 12:30:32 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		left;
	int		right;
	int		tmp;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		tmp = tab[left];
		tab[left] = tab[right];
		tab[right] = tmp;
		left++;
		right--;
	}
}

/*int main(void)
{
	int size = 6;
	int tab[6] = {1, 2, 3, 4, 5, 6};
	int i = 0;

	ft_rev_int_tab(tab, size);

	while (i != size)
	{
		printf("%d", tab[i]);
		i++;
	}

	return 0;
}*/
