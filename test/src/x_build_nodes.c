/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_build_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:43:16 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:43:16 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_redir_file_qt(char *filename)
{
	char	*ret;
	int		wordlen;

	if (!filename)
	{
		perror("Error : redirection file needed!");
		g_exit_code = 1;
	}
	wordlen = 0;
	ret = NULL;
	wordlen = ft_strlen(filename);
	if (!filename)
	{
		perror("Error : missing file after redirection!");
		g_exit_code = 2;
	}
	ret = ms_calloc(ft_strlen(filename), sizeof(char));
	get_cmd_argv_word(ret, filename, wordlen);
	return (ret);
}

static void	build_node_redir(t_cmd **root, char **tok, int i)
{
	t_cmd	*node;

	node = NULL;
	node = lstcmd_new();
	node->type = is_redir(tok[i]);
	node->cmd = get_redir_file_qt(tok[i + 1]);
	if (!*root)
		*root = node;
	else
		lstcmd_last(*root)->next = node;
}

static void	build_node_cmd_mid(t_cmd **root, char **tok, int i)
{
	t_cmd	*node;
	int		ac;

	(void)i;
	node = NULL;
	node = lstcmd_new();
	node->type = CMD;
	node->av = build_cmd_argv(tok, &ac);
	node->cmd = get_cmd_from_av(node->av[0]);
	node->ac = ac;
	node->next = lstcmd_last(*root);
	*root = node;
}

static void	build_node_cmd(t_cmd **root, char **tok, int i)
{
	t_cmd	*node;
	int		ac;

	(void)i;
	node = NULL;
	node = lstcmd_new();
	node->type = CMD;
	node->av = build_cmd_argv(tok, &ac);
	node->cmd = get_cmd_from_av(node->av[0]);
	node->ac = ac;
	if (!*root)
		*root = node;
	else
		lstcmd_last(*root)->next = node;
}

void	build_nodes(t_cmd **root, char **tok, int tokcnt)
{
	int		i;
	int		got_cmd;

	got_cmd = 0;
	i = -1;
	while (tok[++i] && i < tokcnt)
	{
		if (is_redir(tok[i]))
		{
			build_node_redir(root, tok, i);
			i++;
		}
		else if (i == 0)
		{
			got_cmd = 1;
			build_node_cmd(root, tok, i);
		}
		else if (i > 1 && got_cmd == 0 && is_redir(tok[i - 2]))
		{
			got_cmd = 1;
			build_node_cmd_mid(root, tok, i);
		}
	}
}
