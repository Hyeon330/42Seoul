/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:33:24 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/29 19:34:42 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_env *node)
{
	printf("declare -x %s", node->key);
	if (node->val)
		printf("=\"%s\"", node->val);
	printf("\n");
}

int	export(t_cmd *cmd, t_tree *env)
{
	char	**tmp;
	int		i;
	int		j;

	if (!cmd->av[1])
		inorder(env->root, print_export, EXPORT);
	i = -1;
	while (cmd->av[++i])
	{
		tmp = ft_split(cmd->av[i], '=');
		if (!tmp)
			return (ft_error(DYNAMIC));
		insert(env, tmp[0], ft_strchr(cmd->av[i], '=') + 1);
		j = 0;
		while (tmp[++j])
			free(tmp[j]);
		free(tmp);
	}
	return (0);
}
