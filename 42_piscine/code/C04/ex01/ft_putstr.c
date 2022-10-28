/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:53:41 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/11 09:39:22 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/*int main(void)
{
	ft_putstr("fdsaasd");
	return 0;
}*/
