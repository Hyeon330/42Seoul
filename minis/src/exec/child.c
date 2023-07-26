/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:11:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/26 22:44:52 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	child_proc(t_vars *vars, t_cmd *cmd, int *fd, int builtin_no)
{
	pid_t	pid;
	t_redir	*red;

	if (cmd->red)
	{
		printf("Parent->type=> %d\n", cmd->red->type);
		printf("Parent->file=> %s\n", cmd->red->file);
		printf("Parent->file=> %p\n", cmd->red->file);
	}
	signal(SIGINT, SIG_IGN);
	red = cmd->red;
	pid = fork();
	if (pid == -1)
		return (ft_exec_err(EXEC_FORK, cmd->av[0], NULL));
	if (!pid)
	{
		if (cmd->red)
		{
			printf("Child->type=> %d\n", cmd->red->type);
			printf("Child->file=> %s\n", cmd->red->file);
			printf("Child->file=> %p\n", cmd->red->file);
		}
		if (red)
		{
			printf("Child->type=> %d\n", red->type);
			printf("Child->file=> %s\n", red->file);
			printf("Child->file=> %p\n", red->file);
		}
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (fd_ctrl(cmd, fd))
			exit(1);
		if (builtin_no)
			exit(builtin(vars, cmd, builtin_no));
		else
			execute(vars, cmd);
		exit(127);
	}
	return (0);
}
