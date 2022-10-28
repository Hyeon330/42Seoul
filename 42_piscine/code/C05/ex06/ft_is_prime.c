/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:50:58 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/12 00:51:09 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>

int main(void)
{
	int i = 0;
	while (i < 100)
	{
		printf("%d => %d\n", i, ft_is_prime(i));
		i++;
	}

	return 0;
}*/
