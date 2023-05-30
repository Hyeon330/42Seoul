/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:14:32 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/30 22:24:34 by hyeonsul         ###   ########.fr       */
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

void	free_cmds(t_cmd **cmds)
{
	
}

void	exit_clear(t_cmd **cmds, t_tree env)
{
	
}

void	proc(t_tree env)
{
	char	*str;
	t_cmd	**cmds;
	int		cmds_cnt;

	str = readline(PROMPT);
	if (!str)
		exit_clear(cmds, env);
	add_history(str);
	str = pre_parse(str);
	parse(&cmds, &cmds_cnt, str);
	if (!str)
		ft_error(DYNAMIC);
	free(str);
	if (!cmds[1] && !ft_strncmp(cmds[0]->av[0], "exit", 5))
		exit_clear(cmds, env);
	else
		exec(cmds, cmds_cnt, &env);
	free_cmds(cmds);
}

int	main(int ac, char** av, char **env)
{
	t_tree	env_;

	(void)ac;
	(void)av;
	ft_memset(&env_, 0, sizeof(t_tree));
	g_exit_code = 0;
	set_env(&env_, env);
	while (1)
		proc(env_);
}
