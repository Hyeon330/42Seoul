/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:14:32 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/29 20:38:28 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(t_tree *tree, char **env)
{
	char	**var;
	int		i;

	while (*env)
	{
		var = ft_split(*env, '=');
		if (!var)
			ft_error(DYNAMIC);
		if (!ft_strncmp(var[0], "OLDPWD", 7))
			insert(tree, var[0], getenv(var[0]));
		i = 0;
		while (var[++i])
			free(var[i]);
		free(var);
		env++;
	}
}

void	exit_clear(t_cmd **cmds, t_tree env, char *str)
{
	
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_cmd	**cmds;
	t_tree	env_;
	int		cmd_num;

	(void)ac;
	(void)av;
	ft_memset(&env_, 0, sizeof(t_tree));
	g_exit_code = 0;
	set_env(&env_, env);
	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
			ft_error(DYNAMIC);
		if (!cmds[1] && !ft_strncmp(cmds[0]->av[0], "exit", 5))
			exit_clear(cmds, env_, str);
		else
			exec(cmds, cmd_num, &env_);
		add_history(str);
		free(str);
	}
	free(str);
}