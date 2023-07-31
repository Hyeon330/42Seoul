/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:02:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/31 20:04:59 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node_env	*find_min_key(t_node_env *root)
{
	t_node_env	*node;

	node = root;
	while (node && node->left != NULL)
		node = node->left;
	return (node);
}

static t_node_env	*find_end(t_node_env *node)
{
	t_node_env	*tmp;

	if (node->left == NULL)
		tmp = node->right;
	else
		tmp = node->left;
	free(node->key);
	free(node->val);
	free(node);
	return (tmp);
}

static t_node_env	*recursive_del(t_node_env *node, char *key, int *chk_del)
{
	t_node_env	*tmp;
	int			chk;

	if (!node)
		return (NULL);
	chk = ft_strncmp(node->key, key, ft_strlen(key) + 1);
	if (chk > 0)
		node->left = recursive_del(node->left, key, chk_del);
	if (chk < 0)
		node->right = recursive_del(node->right, key, chk_del);
	if (!chk)
	{
		*chk_del = 1;
		if (node->left && node->right)
		{
			tmp = find_min_key(node->right);
			node->key = ft_strdup(tmp->key);
			if (tmp->val)
				node->val = ft_strdup(tmp->val);
			else
				node->val = NULL;
			node->right = recursive_del(node->right, tmp->key, chk_del);
		}
		else
			return (find_end(node));
	}
	return (node);
}

void	remove_env(t_env *env, char *key)
{
	int	chk;

	chk = 0;
	env->root = recursive_del(env->root, key, &chk);
	if (chk)
		env->size--;
}
