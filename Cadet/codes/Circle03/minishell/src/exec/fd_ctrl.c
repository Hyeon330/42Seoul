/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:26:36 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/03 22:22:55 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	in_redir(t_redir *red)
{
	int	fd;

	fd = open(red->file, O_RDONLY);
	if (fd < 0)
		return (ft_exec_err(EXEC_OPEN, NULL, red->file));
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

static int	out_redir(t_redir *red)
{
	int	fd;

	fd = open(red->file, O_WRONLY | O_CREAT | O_APPEND | \
		(O_TRUNC ^ (red->type >> 2 & 1) * O_TRUNC), 0644);
	if (fd < 0)
		return (ft_exec_err(EXEC_OPEN, NULL, red->file));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

void	pipex(int *fd, int INOUT, t_cmd *pipe_chk)
{
	if (pipe_chk && INOUT)
		dup2(fd[1], INOUT);
	if (!INOUT)
		dup2(fd[0], INOUT);
	close(fd[0]);
	close(fd[1]);
}

int	fd_ctrl(t_cmd *cmd, int *fd)
{
	t_redir	*red;

	pipex(fd, STDOUT_FILENO, cmd->next);
	red = cmd->red;
	while (red)
	{
		if ((red->type & (IN_REDIR | HEREDOC) && in_redir(red)) || \
			(red->type & (OUT_REDIR | APPEND) && out_redir(red)))
			return (1);
		red = red->next;
	}
	return (0);
}