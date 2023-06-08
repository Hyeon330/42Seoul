/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:30:46 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 18:02:06 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipex(int *fd, int INOUT)
{
	if (INOUT)
		dup2(fd[1], INOUT);
	else
		dup2(fd[0], INOUT);
	close(fd[1]);
	close(fd[0]);
}

int	redirect(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->type & (IN_REDIR | HERE_DOC) && in_redir(cmd))
			return (1);
		if (cmd->type & (OUT_REDIR | APPEND) && out_redir(cmd))
			return (1);
		cmd = cmd->next;
	}
	return (0);
}

int	fd_ctrl(t_cmd *cmd, int pipe_chk, int *fd)
{
	if (pipe_chk)
		pipex(fd, STDOUT_FILENO);
	return (redirect(cmd));
}