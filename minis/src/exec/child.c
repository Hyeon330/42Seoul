/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:11:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/14 20:04:06 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	path_cmd(t_cmd *cmd, char **env)
{
	int	chk;

	chk = isdir(cmd->av[0]);
	if (chk)
		ft_exec_err(chk, cmd->av[0], NULL);
	execve(cmd->av[0], cmd->av, env);
}

static void	not_path_cmd(t_vars *vars, t_cmd *cmd, char **env)
{
	char	**paths;
	char	*real_path;
	int		i;

	paths = ft_split(search_env(vars->env.root, "PATH"), ':');
	if (!paths)
		exit(ft_exec_err(EXEC_DYNAMIC, cmd->av[0], NULL));
	i = -1;
	while (paths[++i])
	{
		real_path = strjoin_between_char(paths[i], cmd->av[0], '/');
		if (!real_path)
			exit(ft_exec_err(EXEC_DYNAMIC, cmd->av[0], NULL));
		execve(real_path, cmd->av, env);
		free(real_path);
		free(paths[i]);
	}
	free(paths);
	ft_exec_err(EXEC_CNF, cmd->av[0], NULL);
}

static void	execute(t_vars *vars, t_cmd *cmd)
{
	char	**env;

	env = get_env(&vars->env);
	if (!env)
		exit(ft_exec_err(EXEC_DYNAMIC, cmd->av[0], NULL));
	if (ft_strchr(cmd->av[0], '/') || !search_env(vars->env.root, "PATH"))
		path_cmd(cmd, env);
	else
		not_path_cmd(vars, cmd, env);
}

int	child_proc(t_vars *vars, t_cmd *cmd, int *fd, int builtin_no)
{
	pid_t	pid;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		return (ft_exec_err(EXEC_FORK, cmd->av[0], NULL));
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (fd_ctrl(cmd, fd))
			exit(1);
		if (builtin_no)
			exit(builtin(vars, cmd, builtin_no));
		else
			execute(vars, cmd);
		exit(127);
	}
	return (0);
}
