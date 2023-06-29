/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:33:24 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 23:41:59 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_env *node)
{
	if (!ft_strncmp(node->key, "_", 2))
		return ;
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putstr_fd(node->key, STDOUT_FILENO);
	if (node->val)
	{
		ft_putstr_fd("=\"", STDOUT_FILENO);
		ft_putstr_fd(node->val, STDOUT_FILENO);
		ft_putstr_fd("\"", STDOUT_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}

char	*get_val(char *av)
{
	char	*chk_eq;
	char	*val;

	chk_eq = ft_strchr(av, '=');
	if (chk_eq)
		val = ft_strdup(chk_eq + 1);
	else
		val = NULL;
	if (chk_eq && !val)
		return (NULL);
	return (val);
}

void	free_tmp(char **tmp)
{
	int	j;

	j = 0;
	while (tmp[++j])
		free(tmp[j]);
	free(tmp);
}

int	export(t_cmd *cmd, t_tree *env)
{
	char	**tmp;
	char	*val;
	int		i;

	if (!cmd->av[1])
	{
		inorder(env->root, print_export, EXPORT);
		return (0);
	}
	i = 0;
	while (cmd->av[++i])
	{
		tmp = ft_split(cmd->av[i], '=');
		if (!tmp)
			return (ft_error(DYNAMIC, NULL));
		val = get_val(cmd->av[i]);
		if (!val)
			return (ft_error(DYNAMIC, NULL));
		insert(env, tmp[0], val);
		free(val);
		free_tmp(tmp);
	}
	return (0);
}
