/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:40:32 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 17:23:36 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	system("leaks minishell");
	if (check_env_have_quote(env) > 0)
		env = replace_env_have_quote_main(env);
	system("leaks minishell");
	free(temp);
	temp = ft_strjoin(front, env);
	result = ft_strjoin(temp, back);
	free_replace_env(front, back, env);
	free(temp);
	return (result);
}

char	*replace_env_main(char *str, t_vars *vars, char *old, char *new)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			i = replace_index_quote(str, i);
		if (is_env(str, i) == 1)
		{
			if (old)
				free(old);
			old = new;
			if (str[i + 1] == '?')
				new = replace_exit_code(str, i);
			else
				new = replace_env(str, *vars, i, find_end_index_env(str, i));
			str = new;
			i = 0;
			continue ;
		}
		i++;
	}
	if (old)
		free(old);
	return (str);
}
