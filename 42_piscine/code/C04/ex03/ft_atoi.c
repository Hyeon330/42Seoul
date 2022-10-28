/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:14:41 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/06 21:40:03 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	num;
	int	positive;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	positive = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			positive *= -1;
		str++;
	}
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += (*str - '0') * positive;
		str++;
	}
	return (num);
}

/*#include <stdio.h>

int main(void)
{
	printf("%d", ft_atoi("  -+   3123fsdf13"));
	return 0;
}*/
