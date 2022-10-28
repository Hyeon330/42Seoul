/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:36:57 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/03 07:58:18 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	if (!(*str))
		return (1);
	if (*str >= 'a' && *str <= 'z')
		return (ft_str_is_lowercase(str + 1));
	else
		return (0);
}

/*int main(void)
{
	printf("%d", ft_str_is_numeric("fdsfFAA"));
	return 0;
}*/
