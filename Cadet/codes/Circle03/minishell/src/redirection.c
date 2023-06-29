/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:41:09 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 19:06:24 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	in_redir(t_cmd *cmd)
{
	int	fd;

	fd = open(cmd->cmd, O_RDONLY);
	if (fd < 0)
		return (ft_error(OPEN, cmd->cmd));
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	out_redir(t_cmd *cmd)
{
	int	fd;

	fd = open(cmd->cmd, O_WRONLY | O_CREAT | O_APPEND | \
		(O_TRUNC ^ (cmd->type >> 4 & 1) * O_TRUNC), 0644);
	if (fd < 0)
		return (ft_error(OPEN, cmd->cmd));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}
