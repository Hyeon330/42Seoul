/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:29 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 14:34:22 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search(t_env *node, char *key)
{
	int	chk;

	while (node)
	{
		chk = ft_strncmp(node->key, key, ft_strlen(key));
		if (!chk)
			return (node->val);
		if (chk < 0)
			node = node->right;
		else
			node = node->left;
	}
	return (NULL);
}

t_env	*find_min_key(t_env *root)
{
	t_env	*node;

	node = root;
	while (node && node->left != NULL)
		node = node->left;
	return (node);
}

t_env	*find_end(t_env *node)
{
	t_env	*tmp;

	if (node->left == NULL)
		tmp = node->right;
	else
		tmp = node->left;
	free(node->key);
	free(node->val);
	free(node);
	return (tmp);
}

t_env	*recursive_del(t_env **node, char *key, int *chk_del)
{
	t_env	*tmp;
	int		chk;

	if (!*node)
		return (NULL);
	chk = ft_strncmp((*node)->key, key, ft_strlen(key));
	if (chk > 0)
		(*node)->left = recursive_del(&(*node)->left, key, chk_del);
	if (chk < 0)
		(*node)->right = recursive_del(&(*node)->right, key, chk_del);
	if (!chk)
	{
		*chk_del = 1;
		if ((*node)->left && (*node)->right)
		{
			tmp = find_min_key((*node)->right);
			(*node)->key = ft_strdup(tmp->key);
			(*node)->val = ft_strdup(tmp->val);
			(*node)->right = recursive_del(&(*node)->right, tmp->key, chk_del);
		}
		else
			return (find_end(*node));
	}
	return (*node);
}

void	delete_(t_tree *tree, char *key)
{
	int	chk;

	chk = 0;
	recursive_del(&tree->root, key, &chk);
	if (chk)
		tree->size--;
}
