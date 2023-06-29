/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:30:57 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 19:25:48 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(t_cmd *cmd)
{
	int	opt;
	int	i;

	if (!cmd->av[1])
		return (0);
	opt = !ft_strncmp(cmd->av[1], "-n", 3);
	i = 0 | opt;
	while (++i < cmd->ac)
	{
		ft_putstr_fd(cmd->av[i], STDOUT_FILENO);
		if (i != cmd->ac - 1)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (!opt)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
