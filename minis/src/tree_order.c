/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:51:20 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/19 10:22:24 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inorder(t_env *node)
{
	if (!node)
		return ;
	inorder(node->left);
	printf("%s\n", node->key);
	inorder(node->right);
}