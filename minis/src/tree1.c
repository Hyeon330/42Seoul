/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 03:38:09 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/21 22:08:46 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	insert3(t_env **node, t_env **parent, t_env *new, int chk)
{
	if (*node)
	{
		(*node)->val = new->val;
		free(new->key);
		free(new);
		return (0);
	}
	if (chk < 0)
		(*parent)->right = new;
	else
		(*parent)->left = new;
	return (1);
}

void	insert2(t_tree *tree, t_env *new)
{
	t_env	*node;
	t_env	*parent;
	int		chk;

	node = tree->root;
	while (node)
	{
		chk = ft_strncmp(node->key, new->key, ft_strlen(new->key));
		if (!chk)
			break ;
		parent = node;
		if (chk < 0)
			node = node->right;
		else
			node = node->left;
	}
	if (insert3(&node, &parent, new, chk))
		tree->size++;
}

void	insert(t_tree *tree, char *key, char *val)
{
	t_env	*new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		ft_error(DYNAMIC);
	new->key = key;
	new->val = val;
	if (tree->root == NULL)
	{
		tree->size++;
		tree->root = new;
		return ;
	}
	insert2(tree, new);
}
