#include "../header/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		infile;
	int		fd[2];
	pid_t	pid;
	char	**argv;
	char	buff[BUFF_SIZE];
	
	ft_memset(buff, 0, BUFF_SIZE);
	infile = open(av[1], O_RDONLY);

	close(infile);
	
	read(infile, buff, BUFF_SIZE);

	write(fd[1], buff, ft_strlen(buff));

	pipe(fd);

	pid = fork();
	if (!pid)
	{
		// dup2(infile, STDIN_FILENO);
		// close(infile);
		dup2(fd[0], STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		argv = ft_split(av[2], ' ');
		execve(argv[0], argv, env);
	}

	pid = fork();
	if (!pid)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		argv = ft_split(av[3], ' ');
		execve(argv[0], argv, env);
	}

	// pid = fork();
	// if (!pid)
	// {
	// 	dup2(fd[0], STDIN_FILENO);
	// 	// dup2(fd[1], STDOUT_FILENO);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	argv = ft_split(av[3], ' ');
	// 	execve(argv[0], argv, env);
	// }

	close(fd[0]);
	close(fd[1]);

	while (wait(NULL) != -1)
		;
	// fd = open(av[3], O_CREAT|O_WRONLY|O_TRUNC, 0644);
	// read(fd[0], buff, BUFF_SIZE);
	// printf("%s", buff);
}