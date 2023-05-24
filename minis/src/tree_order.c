/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:51:20 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/24 23:24:28 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inorder(t_env *node, void (*visit)(t_env *), int builtin_no)
{
	if (!node)
		return ;
	inorder(node->left, visit, builtin_no);
	if (builtin_no == EXPORT || (builtin_no == ENV && node->val))
		visit(node);
	inorder(node->right, visit, builtin_no);
}

void	clear_ppc(char ***ppc)
{
	int	i;

	i = -1;
	while (ppc[++i])
		free((*ppc)[i]);
	free(*ppc);
}

void	envp_visit(t_env *node, char ***envp, int idx)
{
	int	i;
	int	s_key;
	int	s_val;
	int	s_tot;

	s_key = ft_strlen(node->key);
	s_val = ft_strlen(node->val);
	s_tot = s_key + s_val + 1;
	(*envp)[idx] = (char *)malloc(sizeof(char) * (s_tot + 1));
	if (!(*envp)[idx])
	{
		clear_ppc(envp);
		ft_error(DYNAMIC);
	}
	(*envp)[idx][s_key] = '=';
	(*envp)[idx][s_tot] = 0;
	i = -1;
	while (++i < s_key)
		(*envp)[idx][i] = node->key++;
	while (++i < s_tot)
		(*envp)[idx][i] = node->val++;
}

void	get_envp(t_env *node, char ***envp, int *idx)
{
	int	i;
	int	s_key;
	int	s_val;

	if (!node)
	{
		--(*idx);
		return ;
	}
	envp_visit(node, envp, *idx);
	get_envp(node->left, envp, ++(*idx));
	get_envp(node->right, envp, ++(*idx));
}