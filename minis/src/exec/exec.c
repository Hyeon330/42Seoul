/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:46:35 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/05 22:50:42 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	std_ioe_back(void)
{
	dup2(STDIN_BACK, STDIN_FILENO);
	dup2(STDOUT_BACK, STDOUT_FILENO);
	dup2(STDERR_BACK, STDERR_FILENO);
}

int	handle_pipe(t_vars *vars, int *fd)
{
	if (pipe(fd) == -1)
	{
		vars->exit_code = ft_error(EXEC_PIPE, NULL);
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
		if (!(cmd->next && handle_pipe(vars, fd)))
		{
			builtin_no = isbuiltin(cmd->av[0]);
			if (!builtin_no || vars->token.size - 1)
				child_proc();
			else
			{
				if (ft_ctrl(cmd, fd))
					vars->exit_code = 1;
				else
					builtin(vars, builtin_no);
			}
		}
		cmd = cmd->next;
	}
	std_ioe_back();
}
