/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:49:40 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/31 20:06:41 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_env(t_node_env *node)
{
	if (!node)
		return ;
	clear_env(node->left);
	clear_env(node->right);
	free(node->key);
	free(node->val);
	free(node);
}

static int	other_case(char ***pair, int oldpwd)
{
	char	*tmp;

	tmp = (*pair)[1];
	if (!ft_strncmp((*pair)[0], "SHELL", 6))
		tmp = ft_strdup("minishell");
	else if (!ft_strncmp((*pair)[0], "SHLVL", 6))
		tmp = ft_itoa(ft_atoi((*pair)[1]) + 1);
	else if (!oldpwd)
		return (1);
	if (!tmp)
		return (0);
	if (oldpwd)
		tmp = NULL;
	free((*pair)[1]);
	(*pair)[1] = tmp;
	return (1);
}

void	set_env(t_env *env, char **p_env)
{
	char	**pair;
	int		i;

	i = -1;
	while (*p_env && ++i < 5)
	{
		pair = get_pair(*p_env);
		if (!pair)
			exit(ft_env_error(ENV_DYNAMIC));
		if (!other_case(&pair, !ft_strncmp(pair[0], "OLDPWD", 7)))
			exit(ft_env_error(ENV_DYNAMIC));
		insert_env(env, pair[0], pair[1]);
		free(pair);
		p_env++;
	}
}

void	print_env(t_node_env *node, void (*visit)(t_node_env *), int builtin_no)
{
	if (!node)
		return ;
	print_env(node->left, visit, builtin_no);
	if (builtin_no == EXPORT || (builtin_no == ENV && node->val))
		visit(node);
	print_env(node->right, visit, builtin_no);
}
