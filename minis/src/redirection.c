/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:41:09 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/11 01:20:17 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_pipe_w(t_cmd *cmd, int pipe_w)
{
	char	*limiter;
	char	*line;
	sizt_t	line_s;

	limiter = ft_strjoin(cmd->path, "\n");
	if (!limiter)
		ft_error(DYNAMIC);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 10);
		line = get_next_line(STDIN_FILENO);
		line_s = ft_strlen(line);
		if (!line || (!ft_strncmp(line, limiter, line_s)))
			break;
		while(pipe_w, line, line_s);
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
		ft_error(HERE_DOC);
	input_pipe_w(cmd, fd[1]);
	close(fd[0]);
	return (fd[1]);
}

void	in_redir(t_cmd *cmd)
{
	int	fd;

	if (cmd->type & IN_REDIR)
	{
		fd = open(cmd->path, O_RDONLY);
		if (fd < 0)
			ft_error(OPEN);
	}
	if (cmd->type & HERE_DOC)
		fd = here_doc(cmd);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	out_redir(t_cmd *cmd)
{
	int	fd;

	fd = open(cmd->path, WRONLY | O_CREAT | O_APPEND \
	O_TRUNC ^ (cmd->type >> 2 & 1) * O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}