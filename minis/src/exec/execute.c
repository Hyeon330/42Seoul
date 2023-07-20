/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:04:23 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/20 17:35:58 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isexecute(char *path)
{
	int	chk;

	chk = isdir(path);
	if (chk)
		return (chk);
	if (access(path, X_OK) == -1)
		exit(ft_exec_err(EXEC_PERM_DNI, path, NULL));
	return (0);
}

static void	path_cmd(t_cmd *cmd, char **env)
{
	int	chk;

	chk = isexecute(cmd->av[0]);
	if (chk)
		ft_exec_err(chk, cmd->av[0], NULL);
	execve(cmd->av[0], cmd->av, env);
}

static char	*get_path(t_vars *vars, t_cmd *cmd)
{
	char	**paths;
	char	*ret;
	int		i;

	paths = ft_split(search_env(vars->env.root, "PATH"), ':');
	if (!paths)
		exit(ft_exec_err(EXEC_DYNAMIC, cmd->av[0], NULL));
	i = -1;
	while (paths[++i])
	{
		ret = strjoin_between_char(paths[i], cmd->av[0], '/');
		if (!ret)
			exit(ft_exec_err(EXEC_DYNAMIC, cmd->av[0], NULL));
		if (!isexecute(ret))
		{
			while (paths[i])
				free(paths[i++]);
			free(paths);
			return (ret);
		}
		free(ret);
		free(paths[i]);
	}
	free(paths);
	return (NULL);
}

static void	not_path_cmd(t_vars *vars, t_cmd *cmd, char **env)
{
	char	*path;

	path = get_path(vars, cmd);
	if (!path)
		ft_exec_err(EXEC_CNF, cmd->av[0], NULL);
	execve(path, cmd->av, env);
}

void	execute(t_vars *vars, t_cmd *cmd)
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
