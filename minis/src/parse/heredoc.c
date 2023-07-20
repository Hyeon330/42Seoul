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
	char			*new_result;

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
	new_result = heredoc_join_path(result);
	return (new_result);
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
	char	*file_name;

	limiter = ft_strjoin(limiter, "\n");
	file_name = get_heredoc_filename();
	while (access(file_name, F_OK) == 0)
	{
		free(file_name);
		file_name = get_heredoc_filename();
	}
	fd = open(file_name, O_WRONLY|O_CREAT|O_EXCL|O_TRUNC, 0600);
	if (fd == -1)
		error("open error");
	write_heredoc(fd, limiter);
	close(fd);
	return (file_name);
}