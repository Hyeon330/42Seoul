/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:36:46 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 14:05:40 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*init_redir(void)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir) * 1);
	if (!redir)
		error("malloc error");
	redir->file = NULL;
	redir->next = NULL;
	redir->type = -1;
	return (redir);
}

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (!cmd)
		error("malloc error");
	cmd->next = NULL;
	cmd->ac = 0;
	cmd->av = NULL;
	cmd->red = NULL;
	return (cmd);
}

char	*init_char(int size)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		error("malloc error");
	result[size] = '\0';
	return (result);
}

char	**init_two_dimension(int size)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		error("malloc error");
	result[size] = NULL;
	return (result);
}
