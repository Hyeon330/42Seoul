/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 03:43:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 18:02:55 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_proc(t_cmd *cmd, int pipe_chk, int *fd, t_vars *vars)
{
	char	**envp;
	pid_t	pid;
	int		builtin_no;
	int		i;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		ft_error(FORK, NULL);
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (fd_ctrl(cmd, pipe_chk, fd))
			exit(1);
		envp = (char **)ft_calloc(vars->env.size + 1, sizeof(char *));
		if (!envp)
			ft_error(DYNAMIC, NULL);
		i = 0;
		get_envp(vars->env.root, &envp, &i);
		builtin_no = isbuiltin(cmd->cmd);
		if (builtin_no)
			exit(builtin(builtin_no, cmd, vars));
		else
			execute(cmd, vars, envp);
		exit(127);
	}
}

void	waiting()
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
		g_exit_code = status >> 8;
}

void	exec(t_vars *vars)
{
	int	fd[2];
	int	pipe_chk;
	int	builtin_no;
	int	i;

	i = -1;
	while (++i < vars->cmds_cnt)
	{
		pipe_chk = i + 1 < vars->cmds_cnt;
		if (pipe_chk && pipe(fd) == -1)
		{
			g_exit_code = ft_error(PIPE, NULL);
			continue ;
		}
		builtin_no = isbuiltin(vars->cmds[i]->cmd);
		if (vars->cmds_cnt == 1 && builtin_no)
			g_exit_code = builtin(builtin_no, vars->cmds[i], vars);
		else
			child_proc(vars->cmds[i], pipe_chk, fd, vars);
		if (pipe_chk)
			pipex(fd, STDIN_FILENO);
	}
	waiting();
}
