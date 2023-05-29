/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:32:04 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/29 21:41:59 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(t_cmd *cmd, t_tree *env)
{
	char	*before;
	int		chk;

	if (!cmd->av[1])
		cmd->av[1] = search(env->root, "HOME");
	else
	{
		chk = !ft_strncmp(cmd->av[1], "-", 2);
		if (chk)
		{
			before = search(env->root, "OLDPWD");
			if (!before)
				return(ft_error(OLDPWD));
			cmd->av[1] = before;
		}
	}
	if (chdir(cmd->av[1]) < 0)
		return (ft_error(SYSTEM));
	insert(env, "OLDPWD", search(env->root, "PWD"));
	insert(env, "PWD", cmd->av[1]);
	if (chk)
		printf("%s\n", cmd->av[1]);
	return (0);
}
