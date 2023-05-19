/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 03:38:09 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/19 10:40:42 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert2(t_env *node, t_env *new, char *key, char *val)
{
	t_env	*parent;
	int		chk;

	while (node)
	{
		chk = ft_strncmp(node->key, key, ft_strlen(key));
		if (!chk)
			break ;
		parent = node;
		if (chk < 0)
			node = node->right;
		else
			node = node->left;
	}
	if (node)
	{
		free(new);
		node->val = val;
		return ;
	}
	if (chk < 0)
		parent->right = new;
	else
		parent->left = new;
}

void	insert(t_env **root, char *key, char *val)
{
	t_env	*new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		ft_error(DYNAMIC);
	new->key = key;
	new->val = val;
	if (*root == NULL)
	{
		*root = new;
		return ;
	}
	insert2(*root, new, key, val);
}

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

t_env	*find_min_key(t_env **node)
{
	while ((*node)->left != NULL)
		*node = (*node)->left;
	return (*node);
}

t_env	*delete(t_env **node, char *key)
{
	t_env	*tmp;
	int		chk;

	chk = ft_strncmp((*node)->key, key, ft_strlen(key));
	if (chk < 0)
		(*node)->left = delete(&(*node)->left, key);
	if (chk > 0)
		(*node)->right = delete(&(*node)->right, key);
	else
	{
		if ((*node)->left == NULL)
			return ((*node)->right);
		if ((*node)->right == NULL)
			return ((*node)->left);
		tmp = find_min_key(&(*node)->right);
		(*node)->key = tmp->key;
		(*node)->val = tmp->val;
		(*node)->right = delete(&(*node)->right, tmp->key);
	}
	return (*node);
}
