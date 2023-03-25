/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:55:28 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/25 16:30:17 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	sp_free(char **sp)
{
	int	i;

	i = -1;
	while (sp[++i])
		free(sp[i]);
	free(sp);
}

char	**get_paths(char **env)
{
	while (*env && ft_strncmp("PATH=", *env, 5))
		env++;
	return (ft_split(*env + 5, ':'));
}

char	*get_path(char **paths, char *cmd)
{
	char	*path;
	int		path_len;
	int		cmd_len;
	int		tot_len;
	int		i;

	cmd_len = ft_strlen(cmd);
	i = -1;
	while (paths[++i])
	{
		path_len = ft_strlen(paths[i]);
		tot_len = path_len + cmd_len + 2;
		path = (char *)malloc(sizeof(char) * tot_len);
		if (!path)
			return (NULL);
		path[path_len] = '/';
		ft_memcpy(path, paths[i], path_len);
		ft_memcpy(path + path_len + 1, cmd, cmd_len + 1);
		if (!access(path, X_OK))
			break ;
		free(path);
		path = NULL;
	}
	sp_free(paths);
	return (path);
}

int	is_sqfind(char *agmt)
{
	while (*agmt && *agmt != '\'')
		agmt++;
	return (*agmt);
}

void	child_proc(int *fd, t_args args, int i)
{
	pid_t	pid;
	char	*path;
	char	**argv;

	if (pipe(fd) == -1)
		ft_perror("Pipe creation failed");
	pid = fork();
	if (pid == -1)
		ft_perror("Child proc creation failed");
	if (!pid)
	{
		change_out(args, i, fd);
		if (is_sqfind(args.av[i]))
			argv = sq_split(args.av[i]);
		else
			argv = ft_split(args.av[i], ' ');
		if (!argv)
			ft_error("Dynamic allocation error\n");
		path = get_path(get_paths(args.env), argv[0]);
		if (execve(path, argv, args.env) == -1)
			ft_perror("Execution error");
	}
}
