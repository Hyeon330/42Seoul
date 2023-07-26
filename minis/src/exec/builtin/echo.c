/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:30:57 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/24 20:00:57 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_opt {
	ECHO_FLAG = 0b1,
	ECHO_N = 0b10
};

int	get_opt(char *opt)
{
	int	ret;

	if (!opt || *opt++ != '-')
		return (0);
	ret = ECHO_FLAG;
	while (*opt)
	{
		if (*opt == 'n')
			ret |= ECHO_N;
		else
			return (0);
		opt++;
	}
	return (ret);
}

int	echo(t_cmd *cmd)
{
	int	tmp;
	int	opt;
	int	i;

	tmp = 1;
	opt = 0;
	i = 0;
	while (tmp)
	{
		tmp = get_opt(cmd->av[i + 1]);
		opt |= tmp;
		i += tmp & ECHO_FLAG;
	}
	while (cmd->av[++i])
	{
		ft_putstr_fd(cmd->av[i], STDOUT_FILENO);
		if (i != cmd->ac - 1)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (!(opt & ECHO_N))
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
