/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 03:43:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/24 18:15:25 by hyeonsul         ###   ########.fr       */
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

void	execution(t_cmd *cmd, t_tree *env)
{
	char	**envp;
	char	**paths;
	int		i;

	envp = (char **)ft_calloc(env->size + 1, sizeof(char *));
	if (!envp)
		ft_error(DYNAMIC);
	i = 0;
	get_envp(env->root, &envp, &i);
	paths = ft_split(search(env, "PATH"), ":");
	if (!paths)
		ft_error(DYNAMIC);
}

void	child_proc(t_cmd *cmd, int pipe_chk, int *fd, t_tree *env)
{
	char	**envp;
	pid_t	pid;
	int		i;

	pid = fork();
	if (pid == -1)
		ft_error(SYSTEM);
	if (!pid)
	{
		envp = (char **)ft_calloc(env->size + 1, sizeof(char *));
		if (!envp)
			ft_error(DYNAMIC);
		i = 0;
		get_envp(env->root, &envp, &i);
		fd_ctrl(cmd, pipe_chk, fd);
		close(fd[0]);
		execve(cmd->path, cmd->av, envp);
	}
}

void	waiting()
{
	int	status;
	
	while (waitpid(-1, &status, 0) > 0)
		g_exit_code = status >> 8;
}

void	exec(t_cmd **cmds, int cmd_num, t_tree *env)
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
	waiting();
}