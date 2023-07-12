/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:01:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/12 14:19:05 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_env(t_node_env *node, char *key)
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
