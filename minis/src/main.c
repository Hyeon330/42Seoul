/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:14:32 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 20:25:34 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_val(char **var, int chk_oldpwd)
{
	if (chk_oldpwd)
		return (NULL);
	else if (!ft_strncmp(var[0], "SHELL", 6))
		return (ft_strdup("minishell"));
	else if (!ft_strncmp(var[0], "SHLVL", 6))
		return (ft_itoa(ft_atoi(var[1]) + 1));
	else
		return (ft_strdup(getenv(var[0])));
}

int	set_env(t_tree *tree, char **env)
{
	char	**var;
	char	*val;
	int		chk_oldpwd;
	int		i;

	while (*env)
	{
		var = ft_split(*env, '=');
		if (!var)
			return (ft_error(DYNAMIC, NULL));
		chk_oldpwd = !ft_strncmp(var[0], "OLDPWD", 7);
		val = get_val(var, chk_oldpwd);
		if (!chk_oldpwd && !val)
			return (ft_error(DYNAMIC, NULL));
		insert(tree, var[0], val);
		i = 0;
		while (var[++i])
			free(var[i]);
		free(var);
		env++;
	}
	return (0);
}

void	free_cmds(t_vars *vars)
{
	t_cmd	*tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < vars->cmds_cnt)
	{
		while (vars->cmds[i])
		{
			free(vars->cmds[i]->cmd);
			j = -1;
			while ((vars->cmds[i]->type & CMD) && vars->cmds[i]->av[++j])
				free(vars->cmds[i]->av[j]);
			tmp = vars->cmds[i];
			vars->cmds[i] = vars->cmds[i]->next;
			free(tmp);
		}
	}
	free(vars->cmds);
}

int	proc(t_vars *vars)
{
	char	*str;

	vars->cmds_cnt = 0;
	vars->cmds = NULL;
	str = readline(PROMPT);
	if (!str)
		return (0);
	if (*str != 0)
	{
		add_history(str);
		str = pre_parse(str, vars->env);
		if (!str)
			return (ft_error(DYNAMIC, NULL));
		parse(&vars->cmds, &vars->cmds_cnt, str);
		free(str);
		exec(vars);
		signal(SIGINT, sigint_handler);
		free_cmds(vars);
	}
	else
		free(str);
	return (1);
}

int	main(int ac, char** av, char **env)
{
	t_vars	vars;

	(void)ac;
	(void)av;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	ft_memset(&vars, 0, sizeof(t_vars));
	if (set_env(&vars.env, env))
		exit(1);
	while (proc(&vars))
		;
	exit_clear(NULL, &vars);
	return (0);
}
