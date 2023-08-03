/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:59:36 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 15:34:21 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_wave(char *str, int i)
{
	int	result;

	result = 0;
	if (str[i] != '~')
		return (0);
	if (i == 0 && (str[i + 1] == '/' || is_white_space(str[i + 1]) == 1 \
	|| str[i + 1] == '\0'))
		result = 1;
	if (i != 0 && is_white_space(str[i - 1]) == 1 && (str[i + 1] == '/' \
	|| is_white_space(str[i + 1]) || str[i + 1] == '\0'))
		result = 1;
	return (result);
}

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (-1);
}

int	is_env(char *str, int i)
{
	if (str[i] == '$' && (str[i + 1] == '?' || (str[i + 1] != '\0' \
	&& is_white_space(str[i + 1]) != 1 && str[i + 1] != 34 \
	&& str[i + 1] != 39 && str[i + 1] != '$' && str[i + 1] != '~')))
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
	while (str[i] != '\0' && is_white_space(str[i]) != 1 \
	&& str[i] != 34 && str[i] != 39 && str[i] != '$' && str[i] != '~')
	{
		i++;
	}
	return (i - 1);
}
