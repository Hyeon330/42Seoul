/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:58:54 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/05 04:43:49 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	char	*start;
	int		up;

	up = 1;
	start = str;
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		{
			if (up)
			{
				if (*str >= 'a' && *str <= 'z')
					*str -= 32;
				up--;
			}
			else if (*str >= 'A' && *str <= 'Z')
				*str += 32;
		}
		else if (*str >= '0' && *str <= '9')
			up = 0;
		else
			up = 1;
		str++;
	}
	return (start);
}

/*int main(void)
{
	char str[50] = "lalALla 42fsDfs, ajJJsfd";
	printf("%s", ft_strcapitalize(str));
	return 0;
}*/
