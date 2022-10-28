/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:45:41 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/20 22:14:54 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	ck1;
	int	ck2;
	int	i;

	ck1 = 1;
	ck2 = 1;
	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			ck1 = 0;
		i++;
	}
	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			ck2 = 0;
		i++;
	}
	if (ck1 || ck2)
		return (1);
	else
		return (0);
}
