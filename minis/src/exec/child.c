/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:11:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/03 20:20:58 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	child_proc(t_vars *vars, t_cmd *cmd, int *fd, int builtin_no)
{
	pid_t	pid;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		return (ft_exec_err(EXEC_FORK, cmd->av[0], NULL));
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (fd_ctrl(cmd, fd))
			exit(1);
		if (builtin_no)
			exit(builtin(vars, cmd, builtin_no));
		else
			execute(vars, cmd);
		clear_token(&vars->token);
		clear_env(vars->env.root);
		exit(127);
	}
	return (0);
}
