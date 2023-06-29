/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:40:28 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 23:40:30 by hyeonsul         ###   ########.fr       */
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

void	set_env(t_tree *tree, char **env)
{
	char	**var;
	char	*val;
	int		chk_oldpwd;
	int		i;

	while (*env)
	{
		var = ft_split(*env, '=');
		if (!var)
			exit(ft_error(DYNAMIC, NULL));
		chk_oldpwd = !ft_strncmp(var[0], "OLDPWD", 7);
		val = get_val(var, chk_oldpwd);
		if (!chk_oldpwd && !val)
			exit(ft_error(DYNAMIC, NULL));
		insert(tree, var[0], val);
		i = 0;
		while (var[++i])
			free(var[i]);
		free(var);
		env++;
	}
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
			if (vars->cmds[i]->type & CMD)
			{
				while (vars->cmds[i]->av[++j])
					free(vars->cmds[i]->av[j]);
				free(vars->cmds[i]->av);
			}
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
	char	*tmp;

	vars->cmds_cnt = 0;
	vars->cmds = NULL;
	str = readline(PROMPT);
	if (!str)
		return (0);
	if (*str != 0)
	{
		add_history(str);
		tmp = pre_parse(str, vars->env);
		if (!tmp)
			return (ft_error(DYNAMIC, NULL));
		parse(&vars->cmds, &vars->cmds_cnt, tmp);
		free(tmp);
		free(str);
		exec(vars);
		signal(SIGINT, sigint_handler);
		free_cmds(vars);
	}
	else
		free(str);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_vars	vars;

	(void)av;
	if (ac != 1)
		return (0);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	ft_memset(&vars, 0, sizeof(t_vars));
	set_env(&vars.env, env);
	while (proc(&vars))
		;
	exit_clear(NULL, &vars);
}
