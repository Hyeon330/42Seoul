/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:33:24 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/08 03:38:04 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print(t_node_env *node)
{
	if (!ft_strncmp(node->key, "_", 2))
		return ;
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putstr_fd(node->key, STDOUT_FILENO);
	if (node->val)
	{
		ft_putstr_fd("=\"", STDOUT_FILENO);
		ft_putstr_fd(node->val, STDOUT_FILENO);
		ft_putstr_fd("\"", STDOUT_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}

int	export(t_cmd *cmd, t_env *env)
{
	char	*pair[2];
	int		i;

	if (!cmd->av[1])
	{
		inorder_env(env->root, print, EXPORT);
		return (0);
	}
	i = 0;
	while (cmd->av[++i])
	{
		if (!get_pair(pair, cmd->av[i]))
			return (ft_exec_err(EXEC_DYNAMIC, cmd->av[0], NULL));
		insert_env(env, pair[0], pair[1]);
	}
	return (0);
}