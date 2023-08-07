/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:22:03 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 20:01:36 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_double_end(char *str, int i)
{
	i++;
	while (str[i] != 34)
	{
		i++;
	}
	return (i);
}

int	find_single_end(char *str, int i)
{
	i++;
	while (str[i] != 39)
	{
		i++;
	}
	return (i);
}

char	*remove_double(char *str, int i, int end, t_vars *vars)
{
	char	*front;
	char	*back;
	char	*mid;
	char	*temp;
	char	*result;

	front = ft_substr(str, 0, i);
	mid = ft_substr(str, i + 1, end - i - 1);
	back = ft_substr(str, end + 1, ft_strlen(str) - end - 1);
	mid = replace_mid_dollar(mid, vars);
	temp = ft_strjoin(front, mid);
	result = ft_strjoin(temp, back);
	free_replace_env(front, back, mid);
	free(temp);
	return (result);
}

char	*remove_single(char *str, int i, int end)
{
	char	*front;
	char	*back;
	char	*mid;
	char	*temp;
	char	*result;

	front = ft_substr(str, 0, i);
	mid = ft_substr(str, i + 1, end - i - 1);
	back = ft_substr(str, end + 1, ft_strlen(str) - end - 1);
	temp = ft_strjoin(front, mid);
	result = ft_strjoin(temp, back);
	free_replace_env(front, back, mid);
	free(temp);
	return (result);
}
