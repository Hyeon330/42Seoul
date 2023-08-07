/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:59:36 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 19:53:33 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (-1);
}

int	is_env(char *str, int i)
{
	if ((str[i] == '$' && str[i + 1] == '?') \
	|| (str[i] == '$' && is_character2(str[i + 1]) == 1))
		return (1);
	return (0);
}

int	replace_index_quote(char *str, int i)
{
	char	q;

	q = str[i];
	i++;
	while (str[i] && str[i] != q)
	{
		i++;
	}
	return (i);
}

int	find_end_index_env(char	*str, int i)
{
	i++;
	while (str[i] != '\0' && is_character2(str[i]) == 1)
	{
		i++;
	}
	return (i - 1);
}

int	check_replace2(char	*str)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39 || is_env(str, i) == 1)
			cnt++;
		i++;
	}
	return (cnt);
}
