/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:28:32 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 17:24:50 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_env_have_quote(char *env)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (env[i])
	{
		if (env[i] == 34 || env[i] == 39)
			cnt++;
		i++;
	}
	return (cnt);
}

char	*replace_env_have_quote(char *env, int i)
{
	char	*quote;
	char	*front;
	char	*back;
	char	*result;
	char	*temp;

	if (env[i] == 34)
		quote = ft_strdup("'\"'");
	if (env[i] == 39)
		quote = ft_strdup("\"'\"");
	front = ft_substr(env, 0, i);
	back = ft_substr(env, i + 1, ft_strlen(env) - i + 1);
	temp = ft_strjoin(front, quote);
	free(quote);
	result = ft_strjoin(temp, back);
	free_replace_env(front, back, temp);
	return (result);
}

char	*replace_env_have_quote_main(char *env)
{
	int		i;
	char	*old;
	char	*new_env;

	old = env;
	new_env = NULL;
	i = -1;
	while (env[++i])
	{
		if (env[i] == 34 || env[i] == 39)
		{
			if (old)
				free(old);
			old = new_env;
			new_env = replace_env_have_quote(env, i);
			env = new_env;
			i += 2;
			continue ;
		}
	}
	if (old)
		free(old);
	return (env);
}
