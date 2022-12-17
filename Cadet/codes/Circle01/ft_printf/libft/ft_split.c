/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:11:12 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/14 17:22:33 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_s(char const *s, char c)
{
	int	flag;
	int	str_n;
	int	i;

	str_n = 0;
	flag = 1;
	i = -1;
	while (s[++i])
	{
		if (flag && s[i] != c)
		{
			str_n++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
	}
	return (str_n);
}

int	count_c(char const *s, char c)
{
	int	cnt;

	cnt = -1;
	while (s[++cnt] && s[cnt] != c)
		;
	return (cnt);
}

void	fill_pc_split(char **ppc, char const *s, int ppc_i, int pc_size)
{
	int	pc_i;

	pc_i = -1;
	while (++pc_i < pc_size)
		ppc[ppc_i][pc_i] = s[pc_i];
}

int	fill_ppc(char **ppc, char const *s, char c)
{
	int		s_i;
	int		ppc_i;
	int		pc_size;

	s_i = 0;
	ppc_i = -1;
	while (s[s_i])
	{
		pc_size = count_c(s + s_i, c);
		if (pc_size)
		{
			ppc[++ppc_i] = (char *)malloc(sizeof(char) * (pc_size + 1));
			if (!ppc[ppc_i])
				return (0);
			ppc[ppc_i][pc_size] = 0;
			fill_pc_split(ppc, s + s_i, ppc_i, pc_size);
			s_i += pc_size;
		}
		else
			s_i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ppc;
	int		str_n;
	int		i;

	if (!s)
		return (NULL);
	str_n = count_s(s, c);
	ppc = (char **)malloc(sizeof(char *) * (str_n + 1));
	if (!ppc)
		return (NULL);
	i = 0;
	while (i <= str_n)
		ppc[i++] = NULL;
	if (!fill_ppc(ppc, s, c))
	{
		i = -1;
		while (ppc[++i] && i < str_n)
			free(ppc[i]);
		free(ppc);
		return (NULL);
	}
	return (ppc);
}
