/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:37:37 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 15:33:12 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_env_dollar(char *str, int len, int i, int j)
{
	char	*result;
	char	q;

	result = init_char(len);
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			q = str[i];
			while (str[i] != q)
			{
				result[j] = str[i];
				i++;
				j++;
			}
		}
		if (!(str[i] == '$' && (str[i + 1] == 34 || str[i + 1] == 39)))
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	return (result);
}

int	count_dollar(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] == 34 || str[i] == 39)
			i = replace_index_quote(str, i);
		if (str[i] == '$' && (str[i + 1] == 34 || str[i + 1] == 39))
			cnt++;
		i++;
	}
	return (cnt);
}

void	remove_env_main(char **splited)
{
	int		i;
	int		len;
	char	*old;

	i = 0;
	while (splited[i])
	{
		if (count_dollar(splited[i]) != 0)
		{
			len = ft_strlen(splited[i]) - count_dollar(splited[i]);
			old = splited[i];
			splited[i] = remove_env_dollar(splited[i], len, 0, 0);
			free(old);
		}
		i++;
	}
}
