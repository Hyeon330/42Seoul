/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 07:43:32 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/05 03:12:48 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (!(*str))
		return (1);
	if (*str >= 32 && *str <= 126)
		return (ft_str_is_printable(str + 1));
	else
		return (0);
}

/*int main(void)
{
	char str[5] = "fdsfs";
	str[1] = 32;
	printf("%d", ft_str_is_printable(str));

	return 0;
}*/
