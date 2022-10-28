/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:56:24 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/03 07:58:28 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	if (!(*str))
		return (1);
	if (*str >= 'A' && *str <= 'Z')
		return (ft_str_is_uppercase(str + 1));
	else
		return (0);
}

/*int main(void)
{
	printf("%d", ft_str_is_numeric("fdsfFAA"));
	return 0;
}*/
