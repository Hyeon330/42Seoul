/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:41:09 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/11 01:20:17 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_redir(t_cmd *cmd)
{
	int	fd;

	if (cmd->type & IN_REDIR)
	{
		fd = open(cmd->path, O_RDONLY);
		if (fd < 0)
			ft_error(OPEN);
	}
	if (cmd->type & HERE_DOC)
	{

	}
}

void	out_redir(t_cmd *cmd)
{
	
}