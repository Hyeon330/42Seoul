/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:32:04 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/20 21:23:00 by hyeonsul         ###   ########.fr       */
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
	HOME_NOT_SET
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
	return (1);
}

static int	meta_path(t_cmd *cmd, t_env *env, int *chk)
{
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
		cmd->av[1] = search_env(env->root, "OLDPWD");
		if (!cmd->av[1])
			return (cd_error(OLDPWD_NOT_SET, NULL));
	}
	return (0);
}

static int	set_pwd(t_env *env, char *key, char *val)
{
	if (!key || !val)
	{
		free(key);
		return (1);
	}
	insert_env(env, key, val);
	return (0);
}

int	cd(t_cmd *cmd, t_env *env)
{
	char	*key;
	int		chk;
	int		dir;

	chk = 0;
	if (meta_path(cmd, env, &chk))
		return (1);
	dir = isdir(cmd->av[1]);
	if (!dir)
		return (cd_error(CD_NADIR, cmd->av[1]));
	if (dir == EXEC_OPEN)
		return (ft_exec_err(EXEC_OPEN, cmd->av[0], cmd->av[1]));
	// 이 로직대로 하면 PWD에 상대경로로 들어갈 가능성이 있음
	// reset후에 다시 작성해라
	if (set_pwd(env, ft_strdup("OLDPWD"), \
		ft_strdup(search_env(env->root, "PWD"))) || \
		set_pwd(env, ft_strdup("PWD"), ft_strdup(cmd->av[1])))
		return (ft_exec_err(EXEC_DYNAMIC, cmd->av[0], cmd->av[1]));
	chdir(cmd->av[1]);
	if (chk == HOME)
		cmd->av[1] = NULL;
	if (chk == PREV)
		pwd(env->root);
	return (0);
}
