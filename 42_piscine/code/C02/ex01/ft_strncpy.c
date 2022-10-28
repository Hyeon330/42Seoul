/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:22:19 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/05 19:01:44 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*start;
	unsigned int	i;

	start = dest;
	i = 0;
	while (i < n)
	{
		if (*src)
		{
			*dest = *src;
			src++;
		}
		else
			*dest = '\0';
		dest++;
		i++;
	}
	return (start);
}

/*int main(void)
{
	char dest[15] = "1234567890";
    ft_strncpy(dest, "abcdefghijkl", -1);
    printf("%s", dest);
    return 0;
}*/
