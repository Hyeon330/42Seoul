/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:43:00 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 20:43:13 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_heredoc(char *limiter, int fd)
{
	char	*str;

	while (1)
	{
		write(1, "> ", 2);
		str = get_next_line(0);
		if (!str || ft_strncmp(str, limiter, ft_strlen(limiter)) == 0)
			break ;
		write(fd, str, ft_strlen(str));
		free(str);
		str = NULL;
	}
	free(limiter);
	if (str)
		free(str);
}

int	heredoc_wait(char *limiter)
{
	int	status;

	wait(&status);
	signal(SIGINT, handler);
	free(limiter);
	if (status == 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

int	heredoc(char *limiter, char *file_name)
{
	pid_t	pid;
	int		fd;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
	{
		error("fork error\n");
		return (0);
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		fd = open(file_name, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0600);
		if (fd == -1)
			error ("open error");
		write_heredoc(limiter, fd);
		close(fd);
		exit(1);
	}
	g_exit_code = heredoc_wait(limiter);
	return (g_exit_code);
}

char	*get_heredoc_filename(void)
{
	int				i;
	unsigned int	num;
	int				fd;
	char			str[3];
	char			*result;

	i = 0;
	num = 1;
	fd = open ("/dev/random", O_RDONLY);
	read(fd, str, 3);
	while (i < 3)
	{
		num *= (unsigned char)str[i];
		i++;
	}
	close(fd);
	result = ft_itoa(num);
	return (result);
}

char	*heredoc_main(char *limiter)
{
	char	*temp;
	char	*file_name;

	limiter = ft_strjoin(limiter, "\n");
	temp = get_heredoc_filename();
	file_name = heredoc_join_path(temp);
	while (access(file_name, F_OK) == 0)
	{
		free(file_name);
		file_name = get_heredoc_filename();
	}
	if (heredoc(limiter, file_name))
	{
		unlink(file_name);
		free(file_name);
		return (NULL);
	}
	return (file_name);
}
