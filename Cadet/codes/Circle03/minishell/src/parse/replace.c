/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:09:11 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 20:41:13 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_dollar(char *str, int i, int end, t_vars *vars)
{
	char	*new_str;

	if (str[i + 1] == '?')
		new_str = replace_exit_code(str, i);
	else
		new_str = replace_env(str, *vars, i, end);
	return (new_str);
}

char	*replace_token2(char *str, int *i, t_vars *vars)
{
	int		end;
	char	*new_str;

	new_str = NULL;
	if (str[*i] == 39)
	{
		end = find_single_end(str, *i);
		new_str = remove_single(str, *i, end);
		*i = end - 1;
	}
	else if (str[*i] == 34)
	{
		end = find_double_end(str, *i);
		new_str = remove_double(str, *i, end, vars);
		*i = new_idx_dollar(str, new_str, *i, end);
	}
	else if (is_env(str, *i) == 1)
	{
		end = find_dollar_end(str, *i);
		new_str = replace_dollar(str, *i, end, vars);
		*i = new_idx_dollar(str, new_str, *i, end);
	}
	return (new_str);
}

char	*replace_token_do(char *str, t_vars *vars)
{
	int		i;
	char	*new_str;
	char	*old;

	i = 0;
	old = NULL;
	new_str = NULL;
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34 || is_env(str, i) == 1)
		{
			if (old)
				free(old);
			old = new_str;
			new_str = replace_token2(str, &i, vars);
			str = new_str;
			continue ;
		}
		i++;
	}
	if (old)
		free(old);
	return (str);
}

void	replace_new(char **splited_token, t_vars *vars)
{
	int		i;
	char	*old;

	i = 0;
	while (splited_token[i])
	{
		if (check_replace2(splited_token[i]) != 0)
		{
			old = splited_token[i];
			splited_token[i] = replace_token_do(splited_token[i], vars);
			free(old);
		}
		i++;
	}
}
