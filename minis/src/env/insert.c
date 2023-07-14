/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:54:14 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/14 16:52:01 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node_env	*create_node(char *key, char *val)
{
	t_node_env	*node;

	node = (t_node_env *)malloc(sizeof(t_node_env));
	if (!node)
		exit(ft_env_error(ENV_DYNAMIC));
	node->key = key;
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static void	change_val(t_node_env *node, char *val)
{
	free(node->val);
	if (val)
		node->val = ft_strdup(val);
	else
		node->val = NULL;
}

static void	insert_loop(t_env *env, char *key, char *val)
{
	t_node_env	*node;
	t_node_env	*parent;
	int			cmp;

	node = env->root;
	while (node)
	{
		cmp = ft_strncmp(node->key, key, ft_strlen(key) + 1);
		parent = node;
		if (!cmp)
		{
			free(key);
			change_val(node, val);
			return ;
		}
		if (cmp > 0)
			node = node->left;
		if (cmp < 0)
			node = node->right;
	}
	if (cmp > 0)
		parent->left = create_node(key, val);
	else
		parent->right = create_node(key, val);
	env->size++;
}

void	insert_env(t_env *env, char *key, char *val)
{
	if (!env->root)
	{
		env->root = create_node(key, val);
		env->size = 1;
		return ;
	}
	insert_loop(env, key, val);
}
