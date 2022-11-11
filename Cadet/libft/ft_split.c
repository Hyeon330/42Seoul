/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:11:12 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/11 20:05:42 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_s(char const *s, char c, int *str_n)
{
	int	flag;
	int	i;

	*str_n = 0;
	flag = 1;
	i = -1;
	while (s[++i])
	{
		if (flag && s[i] != c)
		{
			(*str_n)++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
	}
	return (*str_n);
}

char	*make_pc_malloc(char const *s, char c, int *i)
{
	int	pc_size;

	pc_size = 0;
	while (s[*i] && s[*i] != c)
	{
		pc_size++;
		(*i)++;
	}
	return ((char *)malloc(sizeof(char) * (pc_size + 1)));
}

void	input_ppc(char **ppc, char const *s, char c, int str_n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < str_n)
	{
		j = -1;
		while (s[k] && s[k] != c)
		{
			ppc[i][++j] = s[k];
			k++;
			if (!s[k] || s[k] == c)
			{
				ppc[i][++j] = 0;
				i++;
			}
		}
		while (s[k] && s[k] == c)
			k++;
	}
	ppc[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ppc;
	int		str_n;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	ppc = (char **)malloc(sizeof(char *) * (count_s(s, c, &str_n) + 1));
	if (!ppc)
		return (NULL);
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] != c)
		{
			ppc[++j] = make_pc_malloc(s, c, &i);
			if (!ppc[j])
				return (NULL);
		}
		else
			i++;
	}
	input_ppc(ppc, s, c, str_n);
	return (ppc);
}
