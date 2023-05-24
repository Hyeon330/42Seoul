/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 03:43:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/24 23:31:17 by hyeonsul         ###   ########.fr       */
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

char	*get_real_path(char *path, char *cmd)
{
	char	*path;
	int		s_path;
	int		s_cmd;
	int		s_tot;
	int		i;

	s_path = ft_strlen(path);
	s_cmd = ft_strlen(cmd);
	s_tot = s_path + s_cmd + 1;
	path = (char *)malloc(sizeof(char) * (s_tot + 1));
	if (!path)
		ft_error(DYNAMIC);
	path[s_path] = '/';
	path[s_tot] = 0;
	i = -1;
	while (++i < s_path)
		path[i] = path++;
	while (++i < s_tot)
		path[i] = cmd++;
}

int	execution(t_cmd *cmd, char **env)
{
	char	**paths;
	char	*real_path;
	int		ret;
	int		i;

	paths = ft_split(search(env, "PATH"), ":");
	if (!paths)
		ft_error(DYNAMIC);
	i = -2;
	while (paths[++i])
	{
		if (i < 0)
			ret = execve(cmd->cmd, cmd->av, env);
		else
		{
			real_path = get_real_path(paths[i], cmd->cmd);
			if (!real_path)
				ft_error(DYNAMIC);
			ret = execve(real_path, cmd->av, env);
		}
	}
	return (ret);
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
		execution(cmd, envp);
		exit(127);
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
		builtin_no = isbuiltin(cmds[i]->cmd);
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