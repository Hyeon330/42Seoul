/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:43:50 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/03 22:35:43 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *arr, int left, int right)
{
	int	tmp;

	tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

void	q_sort(int *arr, int left, int right)
{
	int	pl;
	int	pr;
	int	pi;

	pl = left;
	pr = right;
	pi = arr[left];
	if (pl >= pr)
		return ;
	while (pl <= pr)
	{
		while (arr[pl] < pi)
			pl++;
		while (arr[pr] > pi)
			pr--;
		if (pl <= pr)
			swap(arr, pl++, pr--);
	}
	q_sort(arr, left, pr);
	q_sort(arr, pl, right);
}
