/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:44:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/10 15:37:20 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (*(dest + i))
		i++;
	j = 0;
	while (j < nb && *(src + j))
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	*(dest + i + j) = 0;
	return (dest);
}

/*int main(void)
{
	char s1[30] = "hello";
	char *s2 = "1234567890";

	printf("%s", ft_strncat(s1, s2, 15));

	return 0;
}*/
