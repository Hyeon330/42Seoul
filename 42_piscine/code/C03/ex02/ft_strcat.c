/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:36:52 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/13 15:19:55 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (start);
}

/*int main(void)
{
	char s1[6] = "hello";
	char *s2 = "world";

	printf("%s", ft_strcat(s1, s2));
	return 0;
}*/
