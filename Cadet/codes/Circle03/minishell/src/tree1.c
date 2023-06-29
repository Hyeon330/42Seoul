/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 03:38:09 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 18:27:55 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_node(char *key, char *val)
{
	t_env	*node;

	node = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!node)
		exit(ft_error(DYNAMIC, NULL));
	node->key = key;
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	change_val(t_env *node, char *val)
{
	free(node->val);
	if (val)
		node->val = strdup(val);
	else
		node->val = NULL;
}

void	insert_loop(t_tree *tree, char *key, char *val)
{
	t_env	*node;
	t_env	*parent;
	int		cmp;

	node = tree->root;
	while (node)
	{
		cmp = ft_strncmp(node->key, key, ft_strlen(key) + 1);
		parent = node;
		if (!cmp)
		{
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
	tree->size++;
}

void	insert(t_tree *tree, char *key, char *val)
{
	if (!tree->root)
	{
		tree->root = create_node(key, val);
		tree->size = 1;
		return ;
	}
	insert_loop(tree, key, val);
}
