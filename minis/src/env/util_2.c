/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:04:36 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/12 19:41:08 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_visit(t_node_env *node, char ***env, int idx, int *chk)
{
	(*env)[idx] = strjoin_between_char(node->key, node->val, '=');
	if (!(*env)[idx])
	{
		clear_ppc(env);
		*chk = 1;
	}
}

static void	recursive_env(t_node_env *node, char ***env, int *idx, int *chk)
{
	if (!node || *chk)
	{
		--(*idx);
		return ;
	}
	env_visit(node, env, *idx, chk);
	++(*idx);
	recursive_env(node->left, env, idx, chk);
	++(*idx);
	recursive_env(node->right, env, idx, chk);
}

char	**get_env(t_env *env)
{
	char	**env;
	int		i;
	int		chk;

	env = (char **)malloc(sizeof(char *) * (env->size + 1));
	if (!env)
		return (NULL);
	ft_memset(env, 0, sizeof(char *) * (env->size + 1));
	i = 0;
	chk = 0;
	recursive_env(env->root, &env, &i, &chk);
	if (chk)
		return (NULL);
	return (env);
}
