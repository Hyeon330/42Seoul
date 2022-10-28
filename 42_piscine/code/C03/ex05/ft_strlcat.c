/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:09:42 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/06 10:53:53 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	des_len;
	unsigned int	max_len;

	des_len = ft_strlen(dest);
	max_len = ft_strlen(dest) + ft_strlen(src);
	while (*dest)
		dest++;
	i = 0;
	while (size > des_len + 1 + i)
	{
		if (*src)
			*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	if (max_len < ft_strlen(src) + size)
		return (max_len);
	else
		return (ft_strlen(src) + size);
}

/*int main(void)
{
	int i = 17;

	char s1[50] = "fdsa";
	char s2[50] = "123123";
	printf("%d\n", ft_strlcat(s1, s2, i));
	printf("%s\n", s1);

	char c1[50] = "fdsa";
	char c2[50] = "123123";
	printf("%lu\n", strlcat(c1, c2, i));
	printf("%s\n", c1);
	return 0;
}*/
