/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:14:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 07:56:21 by hyeonsul         ###   ########.fr       */
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
	if (!ft_strncmp(cmd, "exit", 5))
		return (EXIT);
	return (0);
}

int	builtin(int builtin_no, t_cmd *cmd, t_vars *vars)
{
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
		return (exit_clear(cmd, vars));
	return (1);
}
