/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:14:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/19 02:57:21 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_cmd *cmd)
{
	int	opt;
	int	i;
	
	opt = !ft_strncmp(cmd->av[1], "-n", 3);
	i = 0 | opt;
	while (++i < cmd->ac)
	{
		printf("%s", cmd->av[i]);
		if (i != cmd->ac - 1)
			printf(" ");
	}
	if (!opt)
		printf("\n");
}

void	cd(t_cmd *cmd, char **env)
{
	char		now[PATH_LEN];
	char		*before;

	getcwd(now, sizeof(now));
	if (cmd->av[2])
		ft_error(CHDIR_ARG);
	if (!ft_strncmp(cmd->av[1], "-", 2))
	{
		before = getenv("OLDPWD");
		if (!before)
			// ft_error();
		export(ft_strjoin("OLDPWD=", now));
		cmd->av[1] = before;
	}
	if (!cmd->av[1] || !ft_strncmp(cmd->av[1], "~", 2))
		cmd->av[1] = getenv("HOME");
	if (chdir(cmd->av[1]) < 0)
		ft_error(SYSTEM);
}

char	*pwd()
{
	char	buf[PATH_LEN];

	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
	return (buf);
}

void	export(t_cmd *cmd)
{
	
}

void	builtin(int builtin_no, t_cmd *cmd, char **env)
{
	if (builtin_no == ECHO)
		echo(cmd);
	if (builtin_no == CD)
		cd(cmd, env);
	if (builtin_no == PWD)
		pwd();
	// if (builtin_no == EXPORT)
	// 	export(cmd);
}