/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:50:56 by eoh               #+#    #+#             */
/*   Updated: 2023/07/24 20:04:47 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_wave(char *str, t_vars vars, int i)
{
	char	*home_path;
	char	*front;
	char	*back;
	char	*result;

	home_path = ft_strdup(search_env(vars.env.root, "HOME"));
	front = ft_substr(str, 0, i);
	back = ft_substr(str, i + 1, ft_strlen(str) - i + 1);
	free(str);
	result = ft_strjoin(front, home_path);
	result = ft_strjoin(result, back);
	if (home_path)
		free(home_path);
	if (front)
		free(front);
	if (back)
		free(back);
	return (result);
}

char	*replace_env(char *str, t_vars vars, int i)
{
	char	*env;
	char	*front;
	char	*back;
	char	*result;

	back = ft_substr(str, i + 1, ft_strlen(str) - i + 1);
	if (search_env(vars.env.root, back) == NULL)
		env = ft_strdup("");
	else
		env = ft_strdup(search_env(vars.env.root, back));
	front = ft_substr(str, 0, i);
	result = ft_strjoin(front, env);
	if (front)
		free(front);
	if (back)
		free(back);
	if (env)
		free(env);
	return (result);
}

char	*replace_exit_code(char *str, t_vars vars, int i)
{
	char	*exit_code;
	char	*front;
	char	*back;
	char	*temp;
	char	*result;

	front = ft_substr(str, 0, i);
	back = ft_substr(str, i + 2, ft_strlen(str) - i + 2);
	exit_code = ft_itoa(vars.exit_code);
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

char	*replace_character(char *str, t_vars vars, int cnt)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	new = str;
	while (++i < cnt)
	{
		j = 0;
		while (new[j])
		{
			if (check_wave(new, j) == 1 || check_env(new, j) != 0)
			{
				if (check_wave(new, j) == 1)
					new = replace_wave(new, vars, j);
				if (check_env(new, j) == 1)
					new = replace_env(new, vars, j);
				if (check_env(new, j) == 2)
					new = replace_exit_code(new, vars, j);
				break ;
			}
			j++;
		}
	}
	return (new);
}
