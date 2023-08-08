/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:46:35 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/08 17:55:42 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_pipe(t_cmd *cmd, int *fd)
{
	if (pipe(fd) == -1)
	{
		g_exit_code = ft_exec_err(EXEC_PIPE, cmd->av[0], NULL);
		return (1);
	}
	return (0);
}

static void	waiting(void)
{
	int	status;
	int	signal_num;

	while (wait(&status) != -1)
		;
	signal_num = status & 0x7F;
	if (signal_num)
		g_exit_code = 128 + signal_num;
	else
		g_exit_code = status >> 8;
	if (signal_num == SIGINT)
		write(1, "\n", 1);
	if (signal_num == SIGQUIT)
	{
		write(1, "Quit: ", 6);
		printf("%d\n", signal_num);
	}
}

static int	set_(t_vars *vars, t_cmd *cmd)
{
	char	*key;
	char	*val;

	if (!cmd)
		return (0);
	key = ft_strdup("_");
	if (!cmd->av || cmd->next)
		val = ft_strdup("");
	else
		val = ft_strdup(cmd->av[cmd->ac - 1]);
	if (chk_pair(key, val))
	{
		g_exit_code = ft_exec_err(EXEC_DYNAMIC, cmd->av[cmd->ac - 1], NULL);
		return (1);
	}
	insert_env(&vars->env, key, val);
	return (0);
}

static int	built_child(t_vars *vars, t_cmd *cmd, int *fd, int builtin_no)
{
	if (!builtin_no || vars->token.size - 1)
	{
		if (child_proc(vars, cmd, fd, builtin_no))
			return (-1);
	}
	else if (!fd_ctrl(cmd, fd))
		g_exit_code = builtin(vars, cmd, builtin_no);
	else
		g_exit_code = 1;
	return (builtin_no);
}

void	exec(t_vars *vars)
{
	t_cmd	*cmd;
	int		fd[2];
	int		builtin_no;

	cmd = vars->token.cmd;
	if (set_(vars, cmd))
		return ;
	while (cmd)
	{
		builtin_no = isbuiltin(cmd);
		if (handle_pipe(cmd, fd) || built_child(vars, cmd, fd, builtin_no) < 0)
		{
			close(fd[0]);
			close(fd[1]);
			break ;
		}
		pipex(fd, STDIN_FILENO, cmd->next);
		cmd = cmd->next;
	}
	if (!builtin_no || vars->token.size - 1)
		waiting();
	std_ioe_back();
	signal(SIGINT, handler);
}
