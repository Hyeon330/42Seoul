/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:41:09 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 15:45:15 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_pipe_w(t_cmd *cmd, int pipe_w)
{
	char	*limiter;
	char	*line;
	size_t	line_s;

	limiter = ft_strjoin(cmd->cmd, "\n");
	if (!limiter)
		ft_error(DYNAMIC, NULL);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		line_s = ft_strlen(line);
		if (!line || (!ft_strncmp(line, limiter, line_s)))
			break;
		write(pipe_w, line, line_s);
		free(line);
	}
	free(limiter);
	if (line)
		free(line);
}

int	here_doc(t_cmd *cmd)
{
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error(PIPE, NULL);
	input_pipe_w(cmd, fd[1]);
	close(fd[1]);
	return (fd[0]);
}

int	in_redir(t_cmd *cmd)
{
	int	fd;

	if (cmd->type & IN_REDIR)
	{
		fd = open(cmd->cmd, O_RDONLY);
		if (fd < 0)
			return (ft_error(OPEN, cmd->cmd));
	}
	if (cmd->type & HERE_DOC)
		fd = here_doc(cmd);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	out_redir(t_cmd *cmd)
{
	int	fd;

	fd = open(cmd->cmd, O_WRONLY | O_CREAT | O_APPEND | \
		(cmd->type >> 3 & 1) * O_TRUNC, 0644);
	if (fd < 0)
		return (ft_error(OPEN, cmd->cmd));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}
