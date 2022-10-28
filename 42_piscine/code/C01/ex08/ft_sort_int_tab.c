/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 07:31:01 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/01 12:34:38 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

void	swap(int arr[], int pl, int pr)
{
	int		tmp;

	tmp = arr[pl];
	arr[pl] = arr[pr];
	arr[pr] = tmp;
}

void	q_sort(int arr[], int left, int right)
{
	int		pl;
	int		pr;
	int		pi;

	pl = left;
	pr = right;
	pi = arr[(pl + pr) / 2];
	while (pl <= pr)
	{
		while (arr[pl] < pi)
			pl++;
		while (arr[pr] > pi)
			pr--;
		if (pl <= pr)
			swap(arr, pl++, pr--);
	}
	if (left < pr)
		q_sort(arr, left, pr);
	if (pl < right)
		q_sort(arr, pl, right);
}

void	ft_sort_int_tab(int *tab, int size)
{
	q_sort(tab, 0, size - 1);
}

/*int main(void)
{
	int num[9] = {9, 5, 8, 2, 4, 0, 1, 3, 7};
	ft_sort_int_tab(num, 9);
	int i = 0;
	while(i < 9)
	{
		printf("%d", num[i]);
		i++;
	}

	return 0;
}*/
