/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:54:27 by eoh               #+#    #+#             */
/*   Updated: 2023/07/23 23:00:30 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_replace(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '~' && (check_wave(str, i) == 1))
			cnt++;
		if (str[i] == '$' && str[i] != '\0')
			cnt++;
		i++;
	}
	return (cnt);
}

int	check_wave(char *str, int i)
{
	int	result;

	result = 0;
	if (str[i] != '~')
		return (0);
	if (i == 0 && (str[i + 1] == '/' || str[i + 1] == ' ' \
	|| str[i + 1] == '\0'))
		result = 1;
	if (i != 0 && str[i - 1] == ' ' && (str[i + 1] == '/' \
	|| str[i + 1] == ' ' || str[i + 1] == '\0'))
		result = 1;
	return (result);
}

int	check_env(char *str, int i)
{
	if (str[i] != '$')
		return (0);
	if (str[i + 1] == '?')
		return (2);
	if (str[i + 1] != '\0' && str[i + 1] != 32 && \
	(str[i + 1] < 9 || str[i + 1] > 13))
		return (1);
	return (0);
}
