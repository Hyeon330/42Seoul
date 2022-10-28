/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:00:19 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/03 08:53:33 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*start;

	start = str;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (start);
}

/*int main(void)
{
	char c[20] = "abcDeFghiJkz";
	int i = 0;
	printf("%s", ft_strupcase(c));
	return 0;
}*/
