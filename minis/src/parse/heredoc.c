/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:43:00 by eoh               #+#    #+#             */
/*   Updated: 2023/07/23 22:46:46 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_heredoc(int fd, char *limiter)
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
	}
	free(limiter);
	if (str)
		free(str);
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

char	*heredoc_join_path(char *file_name)
{
	char	*result;

	result = ft_strjoin("/tmp/", file_name);
	free(file_name);
	return (result);
}

char	*heredoc_main(char *limiter)
{
	int		fd;
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
	fd = open(file_name, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0600);
	if (fd == -1)
		error("open error");
	write_heredoc(fd, limiter);
	close(fd);
	return (file_name);
}
