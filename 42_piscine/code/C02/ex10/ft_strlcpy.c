/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:45:29 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/05 08:42:55 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	int		cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (size)
		*(dest + size - 1) = '\0';
	return (ft_strlen(src));
}

/*int main(void)
{
	char *src = "1234";
	char dest[20];

	int ret = ft_strlcpy(dest, src, 4);
	printf("dest = %s\nreturn = %d", dest, ret);
	
	return 0;
}*/
