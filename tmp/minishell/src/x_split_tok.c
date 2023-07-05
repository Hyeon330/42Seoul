/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_split_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:41:48 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:41:48 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	split_tok_get_wordcnt2(char *s)
{
	int		wordcnt;

	wordcnt = 0;
	while (*s)
	{
		if (*s == '\'')
			split_tok_get_wordcnt_qt(&s, &wordcnt, '\'');
		else if (*s == '"')
			split_tok_get_wordcnt_qt(&s, &wordcnt, '"');
		else if (*s == '<')
			split_tok_get_wordcnt_rdr(&s, &wordcnt, '<');
		else if (*s == '>')
			split_tok_get_wordcnt_rdr(&s, &wordcnt, '>');
		else if (*s == ' ')
			s++;
		else
		{
			wordcnt++;
			split_tok_get_wordcnt2_det(&s);
		}
	}
	return (wordcnt);
}

int	split_tok_get_wordlen2(char *s)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != ' ')
	{
		if (s[i] == '\'')
			return (split_tok_get_wordlen_qt(s, &i, '\''));
		else if (s[i] == '"')
			return (split_tok_get_wordlen_qt(s, &i, '"'));
		else if (s[i] == '<')
			return (split_tok_get_wordlen_rdr(s, &i, '<'));
		else if (s[i] == '>')
			return (split_tok_get_wordlen_rdr(s, &i, '>'));
		else
			return (split_tok_get_wordlen2_det(s, &i));
	}
	return (0);
}

static void	split_tok_get_word(char **row, char *s, int wordlen)
{
	int	i;

	i = 0;
	if (s[i] && s[i] != ' ')
	{
		while (i < wordlen)
		{
			(*row)[i] = s[i];
			i++;
		}
		(*row)[wordlen] = 0;
	}
}

static int	split_tok_fill_rows(char **ppc, char *s)
{
	int		ppc_i;
	int		wordlen;

	wordlen = 0;
	ppc_i = -1;
	while (*s)
	{
		wordlen = split_tok_get_wordlen2(s);
		if (wordlen)
		{
			ppc[++ppc_i] = (char *)ft_calloc(wordlen + 1, sizeof(char));
			if (!ppc[ppc_i])
				return (0);
			split_tok_get_word(&ppc[ppc_i], s, wordlen);
			s += wordlen;
		}
		else
			s++;
	}
	return (1);
}

char	**split_tok(char *s)
{
	char	**ppc;
	int		wordcnt;
	int		i;

	wordcnt = 0;
	if (!s)
		return (NULL);
	wordcnt = split_tok_get_wordcnt2(s);
	ppc = (char **)ft_calloc(wordcnt + 1, sizeof(char *));
	if (!ppc)
		return (NULL);
	ppc[wordcnt] = NULL;
	if (!split_tok_fill_rows(ppc, s))
	{
		i = -1;
		while (ppc[++i] && i < wordcnt)
			free(ppc[i]);
		free(ppc);
		return (NULL);
	}
	return (ppc);
}
