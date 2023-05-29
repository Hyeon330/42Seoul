/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:33:54 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/29 19:34:08 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(t_cmd *cmd, t_tree *env)
{
	int	i;

	i = 0;
	while (cmd->av[++i])
		delete_(env, cmd->av[i]);
	return (0);
}
