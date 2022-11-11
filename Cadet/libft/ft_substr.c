/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:30:06 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/11 23:44:51 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pc;
	unsigned int	s_size;
	unsigned int	i;
	size_t			j;

	if (s == NULL)
		return (NULL);
	s_size = ft_strlen(s);
	if (s_size <= start)
		return (ft_strdup(""));
	if (s_size < len)
		pc = (char *)malloc(sizeof(char) * (s_size - start + 1));
	else
		pc = (char *)malloc(sizeof(char) * (len + 1));
	if (pc == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		if (i >= start)
		{
			pc[j] = s[i];
			j++;
		}
		i++;
	}
	pc[j] = 0;
	return (pc);
}
