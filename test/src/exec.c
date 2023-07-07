/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 03:43:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 22:50:02 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_proc(t_cmd *cmd, int pipe_chk, int *fd, t_vars *vars)
{
	pid_t	pid;
	int		builtin_no;

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
		builtin_no = isbuiltin(cmd->cmd);
		if (builtin_no)
			exit(builtin(builtin_no, cmd, vars));
		else
			execute(cmd, vars);
		exit(127);
	}
}

void	waiting(void)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
		g_exit_code = status >> 8;
}

int	handle_pipe(int *fd, int pipe_chk)
{
	if (pipe_chk && pipe(fd) == -1)
	{
		g_exit_code = ft_error(PIPE, NULL);
		return (0);
	}
	return (1);
}

int	handle_builtin(int *fd, t_vars *vars, int builtin_no)
{
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	if (fd_ctrl(vars->cmds[0], 0, NULL))
	{
		g_exit_code = 1;
		return (0);
	}
	g_exit_code = builtin(builtin_no, vars->cmds[0], vars);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	return (1);
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
		if (!handle_pipe(fd, pipe_chk))
			continue ;
		builtin_no = isbuiltin(vars->cmds[i]->cmd);
		if (vars->cmds_cnt == 1 && builtin_no)
		{
			if (!handle_builtin(fd, vars, builtin_no))
				continue ;
		}
		else
			child_proc(vars->cmds[i], pipe_chk, fd, vars);
		if (pipe_chk)
			pipex(fd, STDIN_FILENO);
	}
	waiting();
}
