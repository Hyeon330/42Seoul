/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:30:57 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/07 21:29:23 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_opt {
	FLAG = 0b1,
	N = 0b10
};

int	get_opt(char *opt)
{
	int	ret;

	if (*opt++ != '-')
		return (0);
	ret = FLAG;
	while (*opt)
	{
		if (*opt == 'n')
			ret |= N;
		else
			return (0);
		opt++;
	}
	return (ret);
}

int	echo(t_cmd *cmd)
{
	int	opt;
	int	i;

	if (!cmd->av[1])
		return (0);
	opt = get_opt(cmd->av[1]);
	i = opt & 1;
	while (cmd->av[++i])
	{
		ft_putstr_fd(cmd->av[i], STDOUT_FILENO);
		if (i != cmd->ac - 1)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (!(opt & N))
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
