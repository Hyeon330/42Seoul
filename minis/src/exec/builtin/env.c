/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:35:10 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/14 16:26:43 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print(t_node_env *node)
{
	if (node->val)
	{
		ft_putstr_fd(node->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putstr_fd(node->val, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

int	env(t_node_env *env)
{
	print_env(env, print, ENV);
	return (0);
}
