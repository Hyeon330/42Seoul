/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:40:05 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/08 18:03:59 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isbuiltin(t_cmd *cmd)
{
	if (!cmd->ac)
		return (B_NONE);
	if (!ft_strncmp(cmd->av[0], "echo", 5))
		return (B_ECHO);
	if (!ft_strncmp(cmd->av[0], "cd", 3))
		return (B_CD);
	if (!ft_strncmp(cmd->av[0], "pwd", 4))
		return (B_PWD);
	if (!ft_strncmp(cmd->av[0], "export", 7))
		return (B_EXPORT);
	if (!ft_strncmp(cmd->av[0], "unset", 6))
		return (B_UNSET);
	if (!ft_strncmp(cmd->av[0], "env", 4))
		return (B_ENV);
	if (!ft_strncmp(cmd->av[0], "exit", 5))
		return (B_EXIT);
	return (0);
}

int	builtin(t_vars *vars, t_cmd *cmd, int builtin_no)
{
	if (builtin_no == B_NONE)
		return (0);
	if (builtin_no == B_ECHO)
		return (echo(cmd));
	if (builtin_no == B_CD)
		return (cd(cmd, &vars->env));
	if (builtin_no == B_PWD)
		return (pwd());
	if (builtin_no == B_EXPORT)
		return (export(cmd, &vars->env));
	if (builtin_no == B_UNSET)
		return (unset(cmd, &vars->env));
	if (builtin_no == B_ENV)
		return (env(vars->env.root));
	if (builtin_no == B_EXIT)
		return (exit_clear(vars, cmd));
	return (1);
}
