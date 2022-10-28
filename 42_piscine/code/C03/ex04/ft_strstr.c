/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:24:40 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/05 11:08:28 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	while (*(str + i))
	{
		j = 0;
		while (*(str + i + j) == *(to_find + j))
		{
			if (*(to_find + j + 1) == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	if (*to_find)
		return (0);
	else
		return (str);
}

/*int main(void)
{
	char s1[6] = "hello";
	char *s2 = "lo";

	printf("%s\n",strstr(s1, s2));
	printf("%s", ft_strstr(s1, s2));	
	return 0;
}*/
