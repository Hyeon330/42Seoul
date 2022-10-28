/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:48:31 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/06 08:51:44 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

/*int main(void)
{
	printf("%d", ft_strlen("fdsafdsa"));
}*/
