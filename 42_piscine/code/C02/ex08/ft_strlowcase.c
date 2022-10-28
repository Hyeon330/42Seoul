/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:53:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/03 08:58:39 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*start;

	start = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (start);
}

/*int main(void)
{
	char c[20] = "abcDeFghiJkz";
	printf("%s", ft_strlowcase(c));
	return 0;
}*/
