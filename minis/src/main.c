/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:14:32 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/06 04:05:31 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isbiltin(char *cmd)
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

void	exec(int ac, char **av)
{
	int	chk_biltin;

	(void)ac;
	chk_biltin = isbiltin(av[0]);
	if (0 < chk_biltin)
		printf("biltin\n");
	else
		printf("not biltin\n");
}

int	main(void)
{
	char	*str;

	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
			ft_error(DYNAMIC);
		if (!ft_strncmp(str, "exit", 4))
			break ;
		else
			exec(0, &str);
		add_history(str);
		free(str);
	}
}