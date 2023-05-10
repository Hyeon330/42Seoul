/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_first_in_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:42:25 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/11 04:22:55 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

void	input_file(t_args args, int *fd)
{
	char	*limiter;
	char	*line;
	size_t	line_s;

	limiter = ft_strjoin(args.av[2], "\n");
	if (!limiter)
		ft_error("Dynamic allocation error\n");
	while (1)
	{
		write(STDOUT_FILENO, "here_doc> ", 10);
		line = get_next_line(STDIN_FILENO);
		line_s = ft_strlen(line);
		if (!line || (!ft_strncmp(line, limiter, line_s)))
			break ;
		write(fd[1], line, line_s);
		free(line);
	}
	free(limiter);
	if (line)
		free(line);
}

void	here_doc(t_args args)
{
	int	fd[2];

	if (pipe(fd) == -1)
		ft_perror("here_doc error");
	input_file(args, fd);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void	set_first_in(t_args args)
{
	if (args.here_doc)
		here_doc(args);
	else
		in_out(args.av[1], STDIN_FILENO, args.here_doc);
}
