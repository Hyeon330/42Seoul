/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:46:35 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/07 21:32:30 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	std_ioe_back(void)
{
	dup2(STDIN_BACK, STDIN_FILENO);
	dup2(STDOUT_BACK, STDOUT_FILENO);
	dup2(STDERR_BACK, STDERR_FILENO);
}

int	handle_pipe(t_vars *vars, t_cmd *cmd, int *fd)
{
	if (pipe(fd) == -1)
	{
		vars->exit_code = ft_exec_err(EXEC_PIPE, cmd->av[0], NULL);
		return (1);
	}
	return (0);
}

void	exec(t_vars *vars)
{
	t_cmd	*cmd;
	int		fd[2];
	int		builtin_no;

	cmd = vars->token.cmd;
	while (cmd)
	{
		if (!(cmd->next && handle_pipe(vars, cmd, fd)))
		{
			builtin_no = isbuiltin(cmd->av[0]);
			if (!builtin_no || vars->token.size - 1)
				child_proc();
			else
			{
				if (fd_ctrl(cmd, fd))
					builtin(vars, cmd, builtin_no);
				else
					vars->exit_code = 1;
			}
		}
		cmd = cmd->next;
	}
	std_ioe_back();
}
