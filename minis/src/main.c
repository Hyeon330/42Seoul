/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:14:32 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/19 10:58:46 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(t_env **root, char **env)
{
	char	**var;
	int		i;

	while (*env)
	{
		var = ft_split(*env, '=');
		if (!var)
			ft_error(DYNAMIC);
		insert(root, var[0], getenv(var[0]));
		i = 0;
		while (var[++i])
			free(var[i]);
		free(var);
		env++;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_cmd	**cmds;
	t_env	*sh_env;

	(void)ac;
	(void)av;
	sh_env = NULL;
	set_env(&sh_env, env);
	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
			ft_error(DYNAMIC);
		if (!ft_strncmp(str, "exit", 5))
			break ;
		else
			exec(cmds, 0, env);
		add_history(str);
		free(str);
	}
	free(str);
}