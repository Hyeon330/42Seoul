/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctrl_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:50:31 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/01 18:08:19 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

void	in_out(char *filename, int INOUT, int here_doc)
{
	int	fd;

	if (!INOUT)
		fd = open(filename, O_RDONLY);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND | \
		(O_TRUNC ^ here_doc * O_TRUNC), 0644);
	if (fd == -1 && !INOUT)
		ft_perror("Infile error");
	if (fd == -1)
		ft_perror("Outfile error");
	dup2(fd, INOUT);
	close(fd);
}

void	change_out(t_args args, int i, int *fd)
{
	if (i == args.ac - 2)
		in_out(args.av[i + 1], STDOUT_FILENO, args.here_doc);
	else
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}
