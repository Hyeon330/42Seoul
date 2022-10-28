/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:26:18 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/10 15:31:49 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (!(*(s1 + i) && *(s2 + i)) || *(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (0);
}

/*int main(void)
{
	char *s1 = "fdsaa";
	char *s2 = "fdsaaaa";
	printf("%d\n", ft_strncmp(s1, s2, 6));
	printf("%d\n", strncmp(s1, s2, 6));
	return 0;
}*/
