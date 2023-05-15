/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:14:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/15 12:08:10 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_cmd *cmd)
{
	int	opt;
	int	i;
	
	opt = !ft_strncmp(cmd->av[1], "-n", 3);
	i = 0 | opt;
	while (++i < cmd->ac)
	{
		printf("%s", cmd->av[i]);
		if (i != cmd->ac - 1)
			printf(" ");
	}
	if (opt)
		printf("\n");
}

void	cd(t_cmd *cmd)
{
	if (cmd->av[2])
		ft_error(CHDIR_ARG);
	if (chdir(cmd->av[1]) < 0)
		ft_error(SYSTEM);
}

void	pwd(t_cmd *cmd)
{
	char	buf[1024];

	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
}

void	builtin(int builtin_no, t_cmd *cmd)
{
	if (builtin_no == ECHO)
		echo(cmd);
	if (builtin_no == CD)
		cd(cmd);
	if (builtin_no == PWD)
		pwd(cmd);
	if (builtin_no == EXPORT)
		export(cmd);
}