/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_character_quote.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:45:03 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 17:46:12 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_env_quote(char *str, t_vars vars, int i, int end)
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

char	*replace_quote_do(char *str, int i, t_vars *vars)
{
	char	*result;

	if (str[i + 1] == '?')
		result = replace_exit_code(str, i);
	else
		result = replace_env_quote(str, *vars, i, find_end_index_env(str, i));
	return (result);
}

char	*replace_quote2(char *str, int *i, t_vars *vars)
{
	char	*old;
	char	*new;

	old = NULL;
	new = NULL;
	while (str[*i] != 34)
	{
		if (is_env(str, *i) == 1)
		{
			if (old)
				free(old);
			old = new;
			new = replace_quote_do(str, *i, vars);
			str = new;
			*i = -1;
			break ;
		}
		(*i)++;
	}
	if (old)
		free(old);
	return (str);
}

char	*replace_character_quote(char *str, t_vars *vars)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			i++;
			str = replace_quote2(str, &i, vars);
			if (i == -1)
			{
				i = 0;
				continue ;
			}
		}
		i++;
	}
	return (str);
}
