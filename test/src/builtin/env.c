/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:35:10 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 19:22:27 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_env *node)
{
	if (node->val)
	{
		ft_putstr_fd(node->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putstr_fd(node->val, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

int	env(t_env *envp)
{
	inorder(envp, print_env, ENV);
	return (0);
}
