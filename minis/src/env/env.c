/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:49:40 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/08 03:00:31 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	other_case(char **pair, int oldpwd)
{
	char	*tmp;

	if (oldpwd)
		tmp = NULL;
	if (!ft_strncmp(pair[0], "SHELL", 6))
		tmp = ft_strdup("minishell");
	if (!ft_strncmp(pair[0], "SHLVL", 6))
		tmp = ft_itoa(ft_atoi(pair[1]) + 1);
	if (!tmp && !oldpwd)
		return (0);
	free(pair[1]);
	pair[1] = tmp;
	return (1);
}

void	set_env(t_env *env, char **p_env)
{
	char	*pair[2];
	char	*tmp;

	while (*p_env)
	{
		if (get_pair(pair, *p_env))
			exit(ft_env_error(ENV_DYNAMIC));
		if (!other_case(pair, !ft_strncmp(pair[0], "OLDPWD", 7)))
			exit(ft_env_error(ENV_DYNAMIC));
		insert_env(env, pair[0], pair[1]);
		p_env++;
	}
}

void	print_env(t_node_env *node, void (*visit)(t_env *), int builtin_no)
{
	if (!node)
		return ;
	print_env(node->left, visit, builtin_no);
	if (builtin_no == EXPORT || (builtin_no == ENV && node->val))
		visit(node);
	print_env(node->right, visit, builtin_no);
}
