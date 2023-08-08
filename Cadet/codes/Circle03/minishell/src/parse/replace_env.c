/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:40:32 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 20:20:58 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_dollar_end(char *str, int i)
{
	i++;
	if (str[i] == '?')
		return (i);
	while (str[i])
	{
		if (!((str[i] >= 48 && str[i] <= 57) || \
		(str[i] >= 65 && str[i] <= 90) || \
		(str[i] >= 97 && str[i] <= 122)))
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int	new_idx_dollar(char *str, char *new_str, int start, int end)
{
	int	remain;
	int	new_len;
	int	change;
	int	new_start;

	remain = ft_strlen(str) - (end - start + 1);
	new_len = ft_strlen(new_str);
	change = new_len - remain;
	if (change >= 0)
		new_start = start + change;
	else
	{
		change *= -1;
		new_start = start + change;
	}
	return (new_start);
}

char	*replace_mid_dollar(char *str, t_vars *vars)
{
	int		i;
	int		end;
	char	*new_str;
	char	*old;

	i = 0;
	old = NULL;
	while (str[i])
	{
		if (is_env(str, i) == 1)
		{
			if (old)
				free(old);
			old = str;
			end = find_dollar_end(str, i);
			new_str = replace_dollar(str, i, end, vars);
			i = new_idx_dollar(str, new_str, i, end);
			str = new_str;
			continue ;
		}
		i++;
	}
	if (old)
		free(old);
	return (str);
}

char	*replace_exit_code(char *str, int i)
{
	char	*exit_code;
	char	*front;
	char	*back;
	char	*temp;
	char	*result;

	front = ft_substr(str, 0, i);
	back = ft_substr(str, i + 2, ft_strlen(str) - i + 2);
	exit_code = ft_itoa(g_exit_code);
	temp = ft_strjoin(front, exit_code);
	result = ft_strjoin(temp, back);
	free(temp);
	if (front)
		free(front);
	if (back)
		free(back);
	free(exit_code);
	return (result);
}

char	*replace_env(char *str, t_vars vars, int i, int end)
{
	char	*env;
	char	*front;
	char	*back;
	char	*result;
	char	*temp;

	front = ft_substr(str, 0, i);
	temp = ft_substr(str, i + 1, end - i);
	back = ft_substr(str, end + 1, ft_strlen(str) - end + 1);
	if (search_env(vars.env.root, temp) == NULL)
		env = ft_strdup("");
	else
		env = ft_strdup(search_env(vars.env.root, temp));
	free(temp);
	temp = ft_strjoin(front, env);
	result = ft_strjoin(temp, back);
	free_replace_env(front, back, env);
	free(temp);
	return (result);
}
