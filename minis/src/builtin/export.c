/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:33:24 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 03:16:14 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_env *node)
{
	if (!ft_strncmp(node->key, "_", 2))
		return ;
	printf("declare -x %s", node->key);
	if (node->val)
		printf("=\"%s\"", node->val);
	printf("\n");
}

int	export(t_cmd *cmd, t_tree *env)
{
	char	**tmp;
	char	*val;
	char	*chk_eq;
	int		i;
	int		j;

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
		chk_eq = ft_strchr(cmd->av[i], '=');
		if (chk_eq)
			val = ft_strdup(chk_eq + 1);
		else
			val = NULL;
		if (chk_eq && !val)
			return (ft_error(DYNAMIC, NULL));
		insert(env, tmp[0], val);
		j = 0;
		while (tmp[++j])
			free(tmp[j]);
		free(tmp);
	}
	return (0);
}
