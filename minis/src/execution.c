/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:33:30 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 17:24:35 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_real_path(char *path, char *cmd)
{
	char	*ret;
	int		s_path;
	int		s_cmd;
	int		s_tot;
	int		i;

	s_path = ft_strlen(path);
	s_cmd = ft_strlen(cmd);
	s_tot = s_path + s_cmd + 1;
	ret = (char *)malloc(sizeof(char) * (s_tot + 1));
	if (!ret)
		return (NULL);
	ret[s_path] = '/';
	ret[s_tot] = 0;
	i = -1;
	while (++i < s_path)
		ret[i] = *path++;
	while (++i < s_tot)
		ret[i] = *cmd++;
	path -= s_path;
	cmd -= s_cmd;
	return (ret);
}

int	isdir(char	*path)
{
	struct stat	file_stat;

	if (!stat(path, &file_stat))
	{
		if (file_stat.st_mode & S_IFREG)
			return (0);
		if (file_stat.st_mode & S_IFDIR)
			return (ISADIR);
	}
	return (OPEN);
}

void path_cmd(t_cmd *cmd, char **env)
{
	if (isdir(cmd->cmd))
		ft_error(ISADIR, cmd->cmd);
	execve(cmd->cmd, cmd->av, env);
}

int	not_path_cmd(t_cmd *cmd, t_tree *env, char **envp)
{
	char	**paths;
	char	*real_path;
	int		i;

	paths = ft_split(search(env->root, "PATH"), ':');
	if (!paths)
		return (ft_error(DYNAMIC, NULL));
	i = -1;
	while (paths[++i])
	{
		real_path = get_real_path(paths[i], cmd->cmd);
		if (!real_path)
			return (ft_error(DYNAMIC, NULL));
		execve(real_path, cmd->av, envp);
		free(real_path);
	}
	return (isdir(cmd->cmd));
}

void	execute(t_cmd *cmd, t_vars *vars, char **envp)
{
	int	chk;

	if (ft_strchr(cmd->cmd, '/'))
		path_cmd(cmd, envp);
	else
	{
		chk = not_path_cmd(cmd, &vars->env, envp);
		if (chk == OPEN || !chk)
			ft_error(CNF, cmd->cmd);
		if (chk == ISADIR)
			exit(1);
	}
}