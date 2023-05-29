/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:35:10 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/29 19:35:56 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_env *node)
{
	if (node->val)
		printf("%s=%s\n", node->key, node->val);
}

int	env(t_env **envp)
{
	inorder(*envp, print_env, ENV);
	return (0);
}
