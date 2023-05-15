/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:30:46 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/15 04:13:14 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipex(int *fd, int INOUT)
{
	if (INOUT)
		dup2(fd[1], INOUT);
	else
	{
		dup2(fd[0], INOUT);
		close(fd[0]);
	}
	close(fd[1]);
}

void	redirect(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->type & (IN_REDIR | HERE_DOC))
			in_redir(cmd);
		if (cmd->type & (OUT_REDIR | APPEND))
			out_redir(cmd);
		cmd = cmd->next;
	}
}

void	fd_ctrl(t_cmd *cmd, int pipe_chk, int *fd)
{
	if (pipe_chk)
		pipex(fd, STDOUT_FILENO);
	redirect(cmd);
}