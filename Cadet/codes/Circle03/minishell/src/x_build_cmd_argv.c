/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_build_cmd_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:43:22 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:43:22 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmd_argc(char **tok, int tokcnt)
{
	int		i;
	int		got_cmd;
	int		argc;

	argc = 0;
	got_cmd = 0;
	i = 0;
	while (tok[i] && i < tokcnt)
	{
		if (is_redir(tok[i]))
			i++;
		else if (i == 0 || (i > 1 && got_cmd == 0 && is_redir(tok[i - 2])))
		{
			got_cmd = 1;
			argc++;
		}
		else
			argc++;
		i++;
	}
	return (argc);
}

int	is_cmd_argv(char **tok, int j, int tokcnt)
{
	int		i;
	int		got_cmd;

	got_cmd = 0;
	i = -1;
	while (tok[++i] && i < tokcnt)
	{
		if (is_redir(tok[i]))
			i++;
		else if (i == 0 || (i > 1 && !got_cmd && is_redir(tok[i - 2])))
		{
			got_cmd = 1;
			if (i == j)
				return (1);
		}
		else if (i == j)
			return (1);
	}
	return (0);
}

void	get_cmd_argv_word(char *argv_j, char *tok_i, int wordlen)
{
	int		k;
	int		j;

	j = 0;
	k = -1;
	while (++k < wordlen)
	{
		if (tok_i[k] && tok_i[k] == '\'')
		{
			while (tok_i[++k] && tok_i[k] != '\'')
				argv_j[j++] = tok_i[k];
		}
		else if (tok_i[k] && tok_i[k] == '"')
		{
			while (tok_i[++k] && tok_i[k] != '"')
				argv_j[j++] = tok_i[k];
		}
		else
			argv_j[j++] = tok_i[k];
	}
	argv_j[j] = '\0';
	argv_j[wordlen] = '\0';
}

int	fill_cmd_argv(char **argv, char **tok)
{
	int	i;
	int	j;
	int	wordlen;

	i = 0;
	j = 0;
	while (tok[i])
	{
		if (is_cmd_argv(tok, i, get_tokcnt(tok)))
		{
			wordlen = ft_strlen(tok[i]);
			argv[j] = ft_calloc(wordlen + 1, sizeof(char));
			if (!argv[j])
				return (0);
			get_cmd_argv_word(argv[j], tok[i], wordlen);
			j++;
		}
		i++;
	}
	argv[j] = NULL;
	return (1);
}

char	**build_cmd_argv(char **tok, int *ac)
{
	char	**argv;
	int		argc;
	int		i;

	argc = 0;
	if (!tok)
		return (NULL);
	argc = get_cmd_argc(tok, get_tokcnt(tok));
	argv = ft_calloc(argc + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	if (!fill_cmd_argv(argv, tok))
	{
		i = -1;
		while (argv[++i] && i < argc)
			free(argv[i]);
		free(argv);
		return (NULL);
	}
	*ac = argc;
	return (argv);
}
