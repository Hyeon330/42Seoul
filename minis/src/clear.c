/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:33:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/31 18:58:53 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_ppc(char ***ppc)
{
	int	i;

	i = -1;
	while ((*ppc)[++i])
		free((*ppc)[i]);
	free(*ppc);
}

void	clear_redir(t_redir *red)
{
	t_redir	*tmp;

	while (red)
	{
		tmp = red;
		red = red->next;
		if (tmp->type == HEREDOC)
			unlink(tmp->file);
		free(tmp);
	}
}

void	clear_token(t_token *token)
{
	t_cmd	*cmd;
	t_cmd	*tmp;

	if (!token)
		return ;
	cmd = token->cmd;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		clear_redir(tmp->red);
		clear_ppc(&tmp->av);
		free(tmp);
	}
}
