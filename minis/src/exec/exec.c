/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:46:35 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/12 19:44:08 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_pipe(t_vars *vars, t_cmd *cmd, int *fd)
{
	if (pipe(fd) == -1)
	{
		vars->exit_code = ft_exec_err(EXEC_PIPE, cmd->av[0], NULL);
		return (1);
	}
	return (0);
}

static void	waiting(t_vars *vars)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
		vars->exit_code = status >> 8;
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
			if ((!builtin_no || vars->token.size - 1) && \
				child_proc(vars, cmd, fd, builtin_no))
				break ;
			else if (fd_ctrl(cmd, fd))
				vars->exit_code = builtin(vars, cmd, builtin_no);
			else
				vars->exit_code = 1;
		}
		if (cmd->next)
			pipex(fd, STDIN_FILENO);
		cmd = cmd->next;
	}
	waiting(vars);
	// signal(SIGINT, sigint_handler);
	std_ioe_back();
}
