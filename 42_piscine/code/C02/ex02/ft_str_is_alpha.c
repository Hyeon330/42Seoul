/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:26:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/04 23:39:11 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	if (!(*str))
		return (1);
	if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
		return (ft_str_is_alpha(str + 1));
	else
		return (0);
}

/*int main(void)
{
	printf("%d", ft_str_is_alpha("afdzA"));
	return 0;
}*/
