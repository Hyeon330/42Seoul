/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 03:43:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/19 02:53:46 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isbuiltin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5))
		return (ECHO);
	if (!ft_strncmp(cmd, "cd", 3))
		return (CD);
	if (!ft_strncmp(cmd, "pwd", 4))
		return (PWD);
	if (!ft_strncmp(cmd, "export", 7))
		return (EXPORT);
	if (!ft_strncmp(cmd, "unset", 6))
		return (UNSET);
	if (!ft_strncmp(cmd, "env", 4))
		return (ENV);
	return (0);
}

void	child_proc(t_cmd *cmd, int pipe_chk, int *fd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error(SYSTEM);
	if (!pid)
	{
		fd_ctrl(cmd, pipe_chk, fd);
		close(fd[0]);
		execve(cmd->path, cmd->av, env);
	}
}

void	exec(t_cmd **cmds, int cmd_num, t_env **env)
{
	int	fd[2];
	int	builtin_no;
	int	pipe_chk;
	int	i;

	i = -1;
	while (++i < cmd_num)
	{
		pipe_chk = i + 1 < cmd_num;
		if (pipe_chk && pipe(fd) == -1)
			ft_error(SYSTEM);
		builtin_no = isbuiltin(cmds[i]->path);
		if (builtin_no)
		{
			fd_ctrl(cmds[i], pipe_chk, fd);
			builtin(builtin_no, cmds[i], env);
		}
		else
			child_proc(cmds[i], pipe_chk, fd, env);
		if (pipe_chk)
			pipex(fd, STDIN_FILENO);
	}
	
}