#include "minishell.h"

static int	get_pipe_wordcnt(char *s, int wordcnt)
{
	while (*s)
	{
		if (*s != '|')
		{
			wordcnt++;
			get_pipe_wordcnt_pass_qt(&s);
			s++;
			while (*s && *s != '|')
			{
				get_pipe_wordcnt_pass_qt(&s);
				s++;
			}
		}
		else if (*s == '|')
			s++;
	}
	return (wordcnt);
}

static int	get_pipe_wordlen(char *s, int i)
{
	while (s[i] && s[i] != '|')
	{
		if (s[i] != '|')
		{
			if (s[i] == '\'')
				while (s[++i] && s[i] != '\'')
					;
			else if (s[i] == '"')
				while (s[++i] && s[i] != '"')
					;
			i++;
			while (s[i] && s[i] != '|')
			{
				if (s[i] == '\'')
					while (s[++i] && s[i] != '\'')
						;
				else if (s[i] == '"')
					while (s[++i] && s[i] != '"')
						;
				i++;
			}
		}
	}
	return (i);
}

static void	get_pipe_word(char **ppc, char *s, int ppc_i, int wordlen)
{
	int	i;

	i = -1;
	while (++i < wordlen)
		ppc[ppc_i][i] = s[i];
	ppc[ppc_i] = ms_strtrim_free(ppc[ppc_i], " \t\v\n\r\f");
}

static int	fill_pipe_words(char **ppc, char *s)
{
	int		ppc_i;
	int		wordlen;

	ppc_i = -1;
	while (*s)
	{
		wordlen = get_pipe_wordlen(s, 0);
		if (wordlen)
		{
			ppc[++ppc_i] = (char *)malloc(sizeof(char) * (wordlen + 1));
			if (!ppc[ppc_i])
				return (0);
			ppc[ppc_i][wordlen] = 0;
			get_pipe_word(ppc, s, ppc_i, wordlen);
			s += wordlen;
		}
		else
			s++;
	}
	return (1);
}

char **split_pipe(char *s, int *wordcnt)
{
	char **ppc;
	int		i;
	char *tmp;

	*wordcnt = 0;
	if (!s)
		return (NULL);
	tmp = ft_strtrim(s, " \t\v\n\r\f");
	*wordcnt = get_pipe_wordcnt(tmp, 0);
	ppc = (char **)malloc(sizeof(char *) * (*wordcnt + 1));
	if (!ppc)
		return (NULL);
	ppc[*wordcnt] = NULL;
	if (!fill_pipe_words(ppc, tmp))
	{
		i = -1;
		while (ppc[++i] && i < *wordcnt)
			free(ppc[i]);
		free(ppc);
		return (NULL);
	}
	free(tmp);
	return (ppc);
}
