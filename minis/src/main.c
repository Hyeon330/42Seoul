/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:14:32 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/09 22:28:46 by hyeonsul         ###   ########.fr       */
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

void	exec(t_list *cmd_list, char **env)
{
	// int	biltin_no;

	// biltin_no = isbiltin(av[0]);
	// if (0 < biltin_no)
	// 	biltin(biltin_no, ac, av);
	// else
	// 	printf("not biltin\n");
	int		builtin_no;
	t_cmd	*cmd;

	while (cmd_list)
	{
		cmd = (t_cmd *)cmd_list->content;
		builtin_no = isbuiltin(cmd->av[0]);
		if (0 < builtin_no)
			builtin(builtin_no, cmd->ac, cmd->av);
	}
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	char	*cmds;

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