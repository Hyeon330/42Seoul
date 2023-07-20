#include "test.h"

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
	printf("%s\n", result);
	free(file_name);
	return (result);
}

int main()
{
	char	*file_name;

	file_name = get_heredoc_filename();
	while (access(file_name, F_OK) == 0)
	{
		printf("try_agian\n");
		free(file_name);
		file_name = get_heredoc_filename();
	}
	printf("file name : %s\n", file_name);
}

//gcc test_heredoc_name.c test_utils.c