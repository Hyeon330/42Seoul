/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:42:37 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/19 00:02:24 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_strcat(char *s1, char *s2, char *sep, int flag)
{
	while (*s1)
		s1++;
	if (flag)
	{
		while (*sep)
			*s1++ = *sep++;
	}
	while (*s2)
		*s1++ = *s2++;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*pc;
	int		result_size;
	int		sep_size;
	int		i;

	sep_size = ft_strlen(sep);
	result_size = 0;
	i = 0;
	while (i < size)
		result_size += ft_strlen(strs[i++]) + sep_size;
	if (size)
		result_size -= sep_size;
	pc = (char *)malloc(sizeof(char) * (result_size + 1));
	i = 0;
	while (i <= result_size)
		pc[i++] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(pc, strs[i], sep, i);
		i++;
	}
	return (pc);
}
