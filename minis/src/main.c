/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:14:32 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/11 05:01:41 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isbuiltin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5))
		return (ECHO);
	if (!ft_strncmp(cmd, "cd", 3))
		return (CD);
	if (!ft_strncmp(cmd, "pwd", 4))
		return (PWD);
	if (!ft_strncmp(cmd, "export", 7))
		return (EXPORT);
	if (!ft_strncmp(cmd, "unset", 6))
		return (UNSET);
	if (!ft_strncmp(cmd, "env", 4))
		return (ENV);
	return (0);
}

void	exec(t_cmd **cmds, char **env)
{
	t_cmd	*cmd;
	int		builtin_no;
	int		i;

	i = -1;
	while (cmds[++i])
	{
		while (cmds[i])
		{
			if (cmds[i]->type & CMD)
				cmd = cmds[i];
			if (cmds[i]->type & (IN_REDIR | HERE_DOC))
				in_redir(cmds[i]);
			if (cmds[i]->type & (OUT_REDIR | APPEND))
				out_redir(cmds[i]);
			cmds[i] = cmds[i]->next;
		}
	}
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_cmd	**cmds;

	(void)ac;
	(void)av;
	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
			ft_error(DYNAMIC);
		if (!ft_strncmp(str, "exit", 5))
			break ;
		else
			exec(cmds, env);
		add_history(str);
		free(str);
	}
	free(str);
}