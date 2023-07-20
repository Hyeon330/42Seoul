/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:40:05 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/20 19:42:25 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isbuiltin(t_cmd *cmd)
{
	if (!cmd->ac)
		return (NONE);
	if (!ft_strncmp(cmd->av[0], "echo", 5))
		return (ECHO);
	if (!ft_strncmp(cmd->av[0], "cd", 3))
		return (CD);
	if (!ft_strncmp(cmd->av[0], "pwd", 4))
		return (PWD);
	if (!ft_strncmp(cmd->av[0], "export", 7))
		return (EXPORT);
	if (!ft_strncmp(cmd->av[0], "unset", 6))
		return (UNSET);
	if (!ft_strncmp(cmd->av[0], "env", 4))
		return (ENV);
	if (!ft_strncmp(cmd->av[0], "exit", 5))
		return (EXIT);
	return (0);
}

int	builtin(t_vars *vars, t_cmd *cmd, int builtin_no)
{
	if (builtin_no == NONE)
		return (0);
	if (builtin_no == ECHO)
		return (echo(cmd));
	if (builtin_no == CD)
		return (cd(cmd, &vars->env));
	if (builtin_no == PWD)
		return (pwd(vars->env.root));
	if (builtin_no == EXPORT)
		return (export(cmd, &vars->env));
	if (builtin_no == UNSET)
		return (unset(cmd, &vars->env));
	if (builtin_no == ENV)
		return (env(vars->env.root));
	if (builtin_no == EXIT)
		return (exit_clear(vars, cmd));
	return (1);
}
