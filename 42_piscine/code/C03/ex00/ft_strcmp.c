/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:29:10 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/05 09:21:14 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	if (!(*s1 && *s2) || *s1 != *s2)
		return (*s1 - *s2);
	else
		return (ft_strcmp(s1 + 1, s2 + 1));
}

/*int main(void)
{
	char *s1 = "";
	char *s2 = "zxzfd";
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", strcmp(s1, s2));
	return 0;
}*/
