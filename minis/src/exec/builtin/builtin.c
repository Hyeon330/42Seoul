/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:40:05 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/07 18:17:51 by hyeonsul         ###   ########.fr       */
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

void	builtin(t_vars *vars, t_cmd *cmd, int builtin_no)
{
	if (builtin_no == ECHO)
		vars->exit_code = echo(cmd);
	if (builtin_no == CD)
		vars->exit_code = cd(cmd, &vars->env);
	if (builtin_no == PWD)
		vars->exit_code = pwd(vars->env.root);
	if (builtin_no == EXPORT)
		vars->exit_code = export(cmd, &vars->env);
	if (builtin_no == UNSET)
		vars->exit_code = unset(cmd, &vars->env);
	if (builtin_no == ENV)
		vars->exit_code = env(vars->env.root);
	if (builtin_no == EXIT)
		vars->exit_code = exit_clear(cmd, vars);
}
