/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:22:55 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 17:44:48 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*tokenize_redir(char **splited_token, int i)
{
	t_redir	*redir;

	redir = init_redir();
	if (!redir)
		error("malloc error");
	redir->type = check_redirection(splited_token[i]);
	if (redir->type == HEREDOC)
		redir->file = heredoc_main(splited_token[i + 1]);
	else
		redir->file = ft_strdup(splited_token[i + 1]);
	return (redir);
}

void	tokenize_redir_main(char **splited_token, int i, t_cmd	*cmd)
{
	t_redir	*temp;

	if (cmd->red == NULL)
	{
		cmd->red = tokenize_redir(splited_token, i);
		temp = cmd->red;
	}
	else
	{
		temp = cmd->red;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = tokenize_redir(splited_token, i);
	}
}

void	tokenize_av(char **splited_token, t_cmd *cmd)
{
	int		cnt;
	int		i;
	int		j;
	char	**av;

	cnt = count_av(splited_token);
	if (cnt == 0)
		return ;
	i = 0;
	j = 0;
	av = init_two_dimension(cnt);
	while (splited_token[i])
	{
		if (check_redirection(splited_token[i]) == -1)
		{
			av[j] = ft_strdup(splited_token[i]);
			j++;
		}
		else
			i++;
		i++;
	}
	cmd->av = av;
}

t_cmd	*tokenize(char **splited_token)
{
	t_cmd	*cmd;
	int		i;

	cmd = init_cmd();
	tokenize_av(splited_token, cmd);
	cmd->ac = count_av(splited_token);
	if (count_rd(splited_token) != 0)
	{
		i = 0;
		while (splited_token[i])
		{
			if (check_redirection(splited_token[i]) != -1)
				tokenize_redir_main(splited_token, i, cmd);
			i++;
		}
	}
	return (cmd);
}
