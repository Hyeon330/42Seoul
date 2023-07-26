/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:47:05 by eoh               #+#    #+#             */
/*   Updated: 2023/07/23 22:47:37 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (!cmd)
		error("malloc error");
	cmd->next = NULL;
	cmd->red = NULL;
	cmd->av = NULL;
	cmd->ac = 0;
	return (cmd);
}

t_redir	*init_redir(void)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir) * 1);
	if (!redir)
		error("malloc error");
	redir->next = NULL;
	redir->file = NULL;
	redir->type = -1;
	return (redir);
}
