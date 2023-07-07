/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:32:04 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 17:47:18 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_path(t_cmd *cmd, t_tree *env, int *chk)
{
	if (!cmd->av[1])
	{
		*chk = 1;
		cmd->av[1] = search(env->root, "HOME");
		if (!cmd->av[1])
			return (cd_error(HOME_NOT_SET, NULL));
	}
	if (!ft_strncmp(cmd->av[1], "-", 2))
	{
		*chk = 2;
		cmd->av[1] = search(env->root, "OLDPWD");
		if (!cmd->av[1])
			return (cd_error(OLDPWD_NOT_SET, NULL));
	}
	return (0);
}

int	insert_pwd(t_tree *env, char *key, char *val)
{
	key = ft_strdup(key);
	if (!key)
		return (ft_error(DYNAMIC, NULL));
	val = ft_strdup(val);
	if (!val)
	{
		free(key);
		return (ft_error(DYNAMIC, NULL));
	}
	insert(env, key, val);
	return (0);
}

int	cd(t_cmd *cmd, t_tree *env)
{
	char	path[1024];
	int		chk;

	chk = 0;
	if (get_path(cmd, env, &chk))
		return (1);
	if (!isdir(cmd->av[1]))
		return (cd_error(CD_NADIR, cmd->av[1]));
	if (chdir(cmd->av[1]) < 0)
		return (ft_error(OPEN, cmd->av[1]));
	if (insert_pwd(env, "OLDPWD", search(env->root, "PWD")))
		return (1);
	getcwd(path, 1024);
	if (insert_pwd(env, "PWD", path))
		return (1);
	if (chk)
		cmd->av[1] = NULL;
	if (chk == 2)
		ft_putstr_fd(search(env->root, "PWD"), STDOUT_FILENO);
	return (0);
}
