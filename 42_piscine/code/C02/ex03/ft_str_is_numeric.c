/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:15:06 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/04 23:40:14 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	if (!(*str))
		return (1);
	if (*str >= '0' && *str <= '9')
		return (ft_str_is_numeric(str + 1));
	else
		return (0);
}

/*int main(void)
{
	printf("%d", ft_str_is_numeric("902"));
	return 0;
}*/
