/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:14:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/09 22:13:40 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(int ac, char **av)
{
	int	opt;
	int	i;
	
	opt = ft_strncmp(av[1], "-n", 3);
	i = 0 | !opt;
	while (++i < ac)
	{
		printf("%s", av[i]);
		if (i != ac - 1)
			printf(" ");
	}
	if (opt)
		printf("\n");
}

void	builtin(int builtin_no, int ac, char **av)
{
	if (builtin_no == ECHO)
		echo(ac, av);
}