#include "minishell.h"

static int	split_tok_get_wordcnt(char *s)
{
	int	wordcnt;

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
			while (*s && *s != ' ' && *s != '\'' && *s != '"'
				&& *s != '<' && *s != '>')
				s++;
		}
	}
	return (wordcnt);
}

/*

int static	split_tok_get_wordcnt(char *s)
{
	int	wordcnt;

	wordcnt = 0;
	while (*s)
	{
		if (*s == '\'')
		{
			(wordcnt)++;
			(s)++;
			while (*s && *s != '\'')
				(s)++;
			while (*(++s) && *s != ' ' && *s != '<' && *s != '>')
			{
				if (*s == '\'')
					while (*(++s) && *s != '\'')
						;
				else if (*s == '"')
					while (*(++s) && *s != '"')
						;
			}
		}
		else if (*s == '"')
		{
			(wordcnt)++;
			(s)++;
			while (*s && *s != '"')
				(s)++;
			while (*(++s) && *s != ' ' && *s != '<' && *s != '>')
			{
				if (*s == '"')
					while (*(++s) && *s != '"')
						;
				else if (*s == '\'')
					while (*(++s) && *s != '\'')
						;
			}
		}
		else if (*s == '<')
		{
			(wordcnt)++;
			while (*s && *s == '<')
				(s)++;
		}
		else if (*s == '>')
		{
			(wordcnt)++;
			while (*s && *s == '>')
				(s)++;
		}
		else if (*s == ' ')
			s++;
		else
		{
			wordcnt++;
			while (*s && *s != ' ' && *s != '\'' && *s != '"'
				&& *s != '<' && *s != '>')
				s++;
		}
	}
	return (wordcnt);
}

*/
static int	split_tok_get_wordlen(char *s)
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
		{
			while (s[i] && s[i] != ' ' && s[i] != '"' && s[i] != '\''
				&& s[i] != '<' && s[i] != '>')
				i++;
			return (i);
		}
	}
	return (0);
}

/*
int	static split_tok_get_wordlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != ' ')
	{
		if (s[i] == '\'')
		{
			while (s[++i] && s[i] != '\'')
				;
			while (s[++i] && s[i]  != ' ' && s[i]  != '<' && s[i]  != '>')
			{
				if (s[i]  == '\'')
					while (s[++i] && s[i]  != '\'')
						;
				else if (s[i]  == '"')
					while (s[++i] && s[i]  != '"')
						;
			}
			return (i);
		}
		else if (s[i] == '"')
		{
			while (s[++i] && s[i] != '"')
				;
			while (s[++i] && s[i] != ' ' && s[i] != '<' && s[i] != '>')
			{
				if (s[i] == '\'')
					while (s[++i] && s[i] != '\'')
						;
				else if (s[i] == '"')
					while (s[++i] && s[i] != '"')
						;
			}
			return (i);
		}
		else if (s[i] == '<')
		{
			while (s[i] && s[i] == '<')
				i++;
			return (i);
		}
		else if (s[i] == '>')
		{
			while (s[i] && s[i] == '>')
				i++;
			return (i);
		}
		else
		{
			while (s[i] && s[i] != ' ' && s[i] != '"' && s[i] != '\''
				&& s[i] != '<' && s[i] != '>')
				i++;
			return (i);
		}
	}
	return (0);
}
*/
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
		wordlen = split_tok_get_wordlen(s);
		if (wordlen)
		{
			ppc[++ppc_i] = (char *)ft_calloc(wordlen + 1, sizeof(char));
			if (!ppc[ppc_i])
				return (0);
			split_tok_get_word(&ppc[ppc_i], s,  wordlen);
			s += wordlen;
		}
		else
			s++;
	}
	return (1);
}

char **split_tok(char *s)
{
	char	**ppc;
	int		wordcnt;
	int		i;

	wordcnt = 0;
	if (!s)
		return (NULL);
	wordcnt = split_tok_get_wordcnt(s);
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
