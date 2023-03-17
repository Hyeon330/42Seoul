/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:06:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 22:12:01 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*get_path()
{
	
}

int	main(int ac, char **av, char **env)
{
	int		file;
	int		fd[2];
	pid_t	pid;
	char	**argv;
	char	buff[BUFF_SIZE];
	int		i;
	
	ft_memset(buff, 0, BUFF_SIZE);
	file = open(av[1], O_RDONLY);

	dup2(file, STDIN_FILENO);
	close(file);

	i = 1;
	while (++i < ac - 1)
	{
		pipe(fd);
		pid = fork();
		if (!pid)
		{
			if (i == ac - 2)
			{
				file = open(av[i + 1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
				dup2(file, STDOUT_FILENO);
			}
			else
				dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			argv = ft_split(av[i], ' ');
			execve(argv[0], argv, env);
		}
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
}