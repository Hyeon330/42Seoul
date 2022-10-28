/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:01:57 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/09/28 22:54:08 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c[1];

	c[0] = '0';
	while (c[0] <= '9')
	{
		write(1, c, 1);
		c[0]++;
	}
}
/*int main(void)
{
	ft_print_numbers();

	return 0;
}*/
