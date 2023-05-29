/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:30:57 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/29 19:31:10 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(t_cmd *cmd)
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
	if (!opt)
		printf("\n");
	return (0);
}
