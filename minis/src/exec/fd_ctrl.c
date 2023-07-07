/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:26:36 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/07 17:44:06 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	in_redir(t_redir *red)
{
	int	fd;

	fd = open(red->file, O_RDONLY);
	if (fd < 0)
		return (ft_error(EXEC_OPEN, red->file));
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
		return (ft_error(EXEC_OPEN, red->file));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static void	pipex(int *fd, int INOUT)
{
	if (INOUT)
		dup2(fd[1], INOUT);
	else
		dup2(fd[0], INOUT);
	close(fd[1]);
	close(fd[0]);
}

int	fd_ctrl(t_cmd *cmd, int *fd)
{
	t_redir	*red;

	if (cmd->next)
		pipex(fd, STDOUT_FILENO);
	red = cmd->red;
	while (red)
	{
		if (red->type & IN_REDIR && in_redir(red) || \
			red->type & (OUT_REDIR | APPEND) && out_redir(red))
			return (0);
		red = red->next;
	}
	return (1);
}
