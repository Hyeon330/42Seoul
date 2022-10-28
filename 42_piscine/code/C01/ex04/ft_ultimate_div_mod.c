/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:25:51 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/09/30 09:32:49 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		tmp;

	tmp = *a % *b;
	*a /= *b;
	*b = tmp;
}

/*int main(void)
{
	int a = 42;
	int b = 8;

	ft_ultimate_div_mod(&a, &b);
	printf("%d, %d", a, b);

	return 0;
}*/
