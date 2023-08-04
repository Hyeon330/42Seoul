/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:02:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/04 18:26:41 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node_env	*find_min_key(t_node_env *node)
{
	while (node && node->left != NULL)
		node = node->left;
	return (node);
}

static t_node_env	*find_end(t_node_env *node, int *chk_del)
{
	t_node_env	*tmp;

	if (node->left == NULL)
		tmp = node->right;
	else
		tmp = node->left;
	if (!*chk_del)
	{
		*chk_del = 1;
		free(node->key);
		free(node->val);
	}
	free(node);
	return (tmp);
}

static t_node_env	*recursive_del(t_node_env *node, char *key, int *chk_del);

static void	have_all_leaf(t_node_env *node, int *chk_del)
{
	t_node_env	*tmp;

	*chk_del = 1;
	tmp = find_min_key(node->right);
	free(node->key);
	free(node->val);
	node->key = tmp->key;
	node->val = tmp->val;
	node->right = recursive_del(node->right, tmp->key, chk_del);
}

static t_node_env	*recursive_del(t_node_env *node, char *key, int *chk_del)
{
	int	chk;

	if (!node)
		return (NULL);
	chk = ft_strncmp(node->key, key, ft_strlen(key) + 1);
	if (chk > 0)
		node->left = recursive_del(node->left, key, chk_del);
	if (chk < 0)
		node->right = recursive_del(node->right, key, chk_del);
	if (!chk && node->left && node->right)
		have_all_leaf(node, chk_del);
	else if (!chk)
		return (find_end(node, chk_del));
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
