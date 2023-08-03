/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:32:04 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/31 20:39:34 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_meta_path{
	HOME = 1,
	PREV
};

enum e_cd_err {
	CD_NADIR = 0,
	OLDPWD_NOT_SET,
	HOME_NOT_SET,
	CD_FAIL
};

int	cd_error(int e_no, char *str)
{
	write(2, "minish: cd: ", 12);
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
	}
	if (e_no == HOME_NOT_SET)
		write(2, "HOME not set\n", 13);
	if (e_no == OLDPWD_NOT_SET)
		write(2, "OLDPWD not set\n", 15);
	if (e_no == CD_NADIR)
		write(2, "Not a directory\n", 16);
	if (e_no == CD_FAIL)
		write(2, "Directory change failed\n", 24);
	return (1);
}

static int	meta_path(t_cmd *cmd, t_env *env, int *chk)
{
	char	*str;

	if (!cmd->av[1])
	{
		*chk = HOME;
		cmd->av[1] = search_env(env->root, "HOME");
		if (!cmd->av[1])
			return (cd_error(HOME_NOT_SET, NULL));
	}
	if (!ft_strncmp(cmd->av[1], "-", 2))
	{
		*chk = PREV;
		free(cmd->av[1]);
		cmd->av[1] = NULL;
		str = search_env(env->root, "OLDPWD");
		if (!str)
			return (cd_error(OLDPWD_NOT_SET, NULL));
		cmd->av[1] = ft_strdup(str);
		if (!cmd->av[1])
			return (ft_exec_err(EXEC_DYNAMIC, cmd->av[0], cmd->av[1]));
	}
	return (0);
}

static int	set_pwd(t_cmd *cmd, t_env *env)
{
	char	*pair[2];
	char	path[5120];
	char	*chk;

	chk = getcwd(path, 5120);
	if (!chk)
	{
		chdir(search_env(env->root, "PWD"));
		pair[0] = ft_strdup("OLDPWD");
		pair[1] = ft_strdup("");
	}
	else
	{
		pair[0] = ft_strdup("PWD");
		pair[1] = ft_strdup(path);
	}
	if (chk_pair(pair[0], pair[1]))
		return (ft_exec_err(EXEC_DYNAMIC, cmd->av[0], cmd->av[1]));
	insert_env(env, pair[0], pair[1]);
	if (!chk)
		return (cd_error(CD_FAIL, cmd->av[1]));
	return (0);
}

int	cd(t_cmd *cmd, t_env *env)
{
	char	*key;
	char	*val;
	int		chk;

	chk = 0;
	if (meta_path(cmd, env, &chk))
		return (1);
	if (!isdir(cmd->av[1]))
		return (cd_error(CD_NADIR, cmd->av[1]));
	if (chdir(cmd->av[1]) < 0)
		return (ft_exec_err(EXEC_OPEN, cmd->av[0], cmd->av[1]));
	key = ft_strdup("OLDPWD");
	val = ft_strdup(search_env(env->root, "PWD"));
	if (chk_pair(key, val))
		return (ft_exec_err(EXEC_DYNAMIC, cmd->av[0], cmd->av[1]));
	insert_env(env, key, val);
	if (set_pwd(cmd, env))
		return (1);
	if (chk == HOME)
		cmd->av[1] = NULL;
	if (chk == PREV)
		pwd(env->root);
	return (0);
}
