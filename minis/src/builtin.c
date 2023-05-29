/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:14:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/29 19:37:03 by hyeonsul         ###   ########.fr       */
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

int	builtin(int builtin_no, t_cmd *cmd, t_tree *envp)
{
	if (builtin_no == ECHO)
		return (echo(cmd));
	if (builtin_no == CD)
		return (cd(cmd, envp));
	if (builtin_no == PWD)
		return (pwd(envp->root));
	if (builtin_no == EXPORT)
		return (export(cmd, envp));
	if (builtin_no == UNSET)
		return (unset(cmd, envp));
	if (builtin_no == ENV);
		return (env(envp));
	return (1);
}
