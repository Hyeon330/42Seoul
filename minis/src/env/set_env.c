/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:49:40 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/05 19:49:42 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_val(char **var, int oldpwd)
{
	if (oldpwd)
		return (NULL);
	else if (!ft_strncmp(var[0], "SHELL", 6))
		return (ft_strdup("minishell"));
	else if (!ft_strncmp(var[0], "SHLVL", 6))
		return (ft_itoa(ft_atoi(var[1]) + 1));
	else
		return (ft_strdup(getenv(var[0])));
}

void	set_env(t_env *env, char **p_env)
{
	char	**sp_env;
	char	*val;
	int		oldpwd;
	int		i;

	while (*p_env)
	{
		sp_env = ft_split(*p_env, '=');
		if (!sp_env)
			exit(ft_env_error(ENV_DYNAMIC));
		oldpwd = !ft_strncmp(sp_env[0], "OLDPWD", 7);
		if (sp_env[1] || oldpwd)
		{
			val = get_val(sp_env, oldpwd);
			if (!oldpwd && !val)
				exit(ft_env_error(ENV_DYNAMIC));
			insert_env(env, sp_env[0], val);
		}
		i = 0;
		while (sp_env[++i])
			free(sp_env[i]);
		free(sp_env);
		p_env++;
	}
}
