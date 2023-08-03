/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:43:26 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 13:54:51 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_env_quote(char *str, int i)
{
	if (str[i] == '$' && (is_white_space(str[i + 1] != 1) \
	&& str[i + 1] != 34 && str[i + 1] != 39 && str[i + 1] != '$'))
		return (1);
	return (0);
}

int	count_env_quote(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			i++;
			while (str[i] != 34)
			{
				if (is_env_quote(str, i) == 1)
					cnt++;
				i++;
			}
		}
		i++;
	}
	return (cnt);
}

int	count_wave(char *s)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			i = replace_index_quote(s, i);
		if ((i == 0 && s[i] == '~') || \
		(is_white_space(s[i]) == 1 && s[i + 1] == '~'))
		{
			if (i != 0)
				i++;
			if (s[i + 1] == '\0' || \
			is_white_space(s[i + 1]) == 1 || s[i + 1] == '/')
				cnt++;
		}
		i++;
	}
	return (cnt);
}

int	count_env(char *str)
{
	int		i;
	int		cnt;
	char	q;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			q = str[i];
			i++;
			while (str[i] != q)
			{
				i++;
			}
		}
		if (str[i] == '$' && \
		(str[i + 1] != '\0' && is_white_space(str[i + 1]) == -1 \
		&& str[i + 1] != 34 && str[i + 1] != 39 && str[i + 1] != '$'))
			cnt++;
		i++;
	}
	return (cnt);
}
