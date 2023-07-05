#include "minishell.h"

void	split_tok_get_wordcnt_qt(char **s, int *wordcnt, char c)
{
	(*wordcnt)++;
	(*s)++;
	while (**s && **s != c)
		(*s)++;
	while (*(++(*s)) && **s != ' ' && **s != '<' && **s != '>')
	{
		if (**s == '\'')
			while (*(++(*s)) && **s != '\'')
				;
		else if (**s == '"')
			while (*(++(*s)) && **s != '"')
				;
	}
}

void	split_tok_get_wordcnt_rdr(char **s, int *wordcnt, char c)
{
	(*wordcnt)++;
	while (**s && **s == c)
		(*s)++;
}

int	split_tok_get_wordlen_qt(char *s, int *i, char c)
{
	while (s[++(*i)] && s[*i] != c)
		;
	while (s[++(*i)] && s[*i] != ' ' && s[*i] != '<' && s[*i] != '>')
	{
		if (s[*i] == '\'')
			while (s[++(*i)] && s[*i] != '\'')
				;
		else if (s[*i] == '"')
			while (s[++(*i)] && s[*i] != '"')
				;
	}
	return (*i);
}


int	split_tok_get_wordlen_rdr(char *s, int *i, char c)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
	return (*i);
}
