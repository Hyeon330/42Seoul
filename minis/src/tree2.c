/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:17:29 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 02:23:04 by hyeonsul         ###   ########.fr       */
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

t_env	*find_min_key(t_env *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

t_env	*left_or_right_null(t_env *node)
{
	t_env	*ret;

	ret = NULL;
	if (node->left && node->right)
		return (NULL);
	if (node->left == NULL)
		ret = node->right;
	if (node->right == NULL)
		ret = node->left;
	free(node->key);
	free(node);
	return (ret);
}

t_env	*recursive_del(t_env **node, char *key, int *chk_del)
{
	t_env	*ret;
	t_env	*tmp;
	int		chk;

	if (!*node)
		return (NULL);
	chk = ft_strncmp((*node)->key, key, ft_strlen(key));
	if (chk > 0)
		(*node)->left = recursive_del(&(*node)->left, key, chk_del);
	if (chk < 0)
		(*node)->right = recursive_del(&(*node)->right, key, chk_del);
	else
	{
		*chk_del = 1;
		if (!((*node)->left || (*node)->right))
			return (NULL);
		ret = left_or_right_null(*node);
		if (ret)
			return (ret);
		tmp = find_min_key((*node)->right);
		(*node)->key = tmp->key;
		(*node)->val = tmp->val;
		(*node)->right = recursive_del(&(*node)->right, tmp->key, chk_del);
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
