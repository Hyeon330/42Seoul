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

void	heredoc_main(char *limiter)
{
	int	fd;

	limiter = ft_strjoin(limiter, "\n");
	fd = open("heredoc_temp\n", O_WRONLY|O_CREAT|O_EXCL|O_TRUNC, 0600);
	if (fd == -1)
		error("open error");
	write_heredoc(fd, limiter);
	close(fd);
}