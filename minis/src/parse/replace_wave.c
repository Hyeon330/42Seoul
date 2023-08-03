/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_wave.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:44:23 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 15:11:42 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_wave(char *str, t_vars vars, int i)
{
	char	*home_path;
	char	*front;
	char	*back;
	char	*result;
	char	*temp;

	home_path = ft_strdup(search_env(vars.env.root, "HOME"));
	front = ft_substr(str, 0, i);
	back = ft_substr(str, i + 1, ft_strlen(str) - i + 1);
	temp = ft_strjoin(front, home_path);
	result = ft_strjoin(temp, back);
	free_replace_wave(temp, home_path, front, back);
	return (result);
}

char	*replace_wave_main(char *str, t_vars *vars)
{
	int		i;
	char	*old;
	char	*new;

	i = -1;
	old = NULL;
	new = NULL;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
			i = replace_index_quote(str, i);
		if (str[i] == '~' && check_wave(str, i) == 1)
		{
			if (old)
				free(old);
			old = new;
			new = replace_wave(str, *vars, i);
			str = new;
			i = -1;
			continue ;
		}
	}
	if (old)
		free(old);
	return (str);
}
