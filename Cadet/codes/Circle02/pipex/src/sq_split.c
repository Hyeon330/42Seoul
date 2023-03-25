/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:21:11 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/23 18:01:14 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static int	count_s(char const *s)
{
	int	str_n;
	int	sq_chk;

	str_n = 0;
	while (*s)
	{
		if (*s == '\'')
		{
			sq_chk = 0;
			while (*++s != '\'')
				sq_chk++;
			s++;
			if (sq_chk)
				str_n++;
		}
		else if (*s != ' ')
		{
			str_n++;
			while (*s != ' ')
				s++;
		}
		else
			s++;
	}
	return (str_n);
}

static int	count_c(char const *s)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	if (s[i] == '\'')
	{
		while (s[++i] && s[i] != '\'')
			cnt++;
	}
	else if (s[i] != ' ')
	{
		while (s[i] && s[i++] != ' ')
			cnt++;
	}
	return (cnt);
}

static void	fill_pc_split(char **ppc, char const *s, int ppc_i, int pc_size)
{
	int	pc_i;

	if (*s == '\'')
		s++;
	pc_i = -1;
	while (++pc_i < pc_size)
		ppc[ppc_i][pc_i] = s[pc_i];
}

static int	fill_ppc(char **ppc, char const *s)
{
	int	ppc_i;
	int	pc_size;

	ppc_i = -1;
	while (*s)
	{
		pc_size = count_c(s);
		if (pc_size)
		{
			ppc[++ppc_i] = (char *)malloc(sizeof(char) * (pc_size + 1));
			if (!ppc[ppc_i])
				return (0);
			ppc[ppc_i][pc_size] = 0;
			fill_pc_split(ppc, s, ppc_i, pc_size);
		}
		if (*s == '\'')
			pc_size += 2;
		if (pc_size)
			s += pc_size;
		else
			s++;
	}
	return (1);
}

char	**sq_split(char const *s)
{
	char	**ppc;
	int		str_n;
	int		i;

	str_n = count_s(s);
	ppc = (char **)malloc(sizeof(char *) * (str_n + 1));
	if (!ppc)
		return (NULL);
	ppc[str_n] = NULL;
	if (!fill_ppc(ppc, s))
	{
		i = -1;
		while (ppc[++i] && i < str_n)
			free(ppc[i]);
		free(ppc);
		return (NULL);
	}
	return (ppc);
}
