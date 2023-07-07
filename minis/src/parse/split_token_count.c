#include "minishell.h"

int	count_redir(char *s, int i)
{
	char	redir;

	redir = s[i];
	if (s[i + 1] == '<' || s[i + 1] == '>')
	{
		if (s[i + 1] != redir)
			error("no words after redirection");
		else
			return (i + 1);
	}
	return (i);
}

int	count_quote(char *s, int i)
{
	char	quote;
	int		end;

	quote = s[i];
	end = -1;
	i++;
	while (s[i])
	{
		if (s[i] == quote)
		{
			end = i;
			break ;
		}
		i++;
	}
	if (end == -1)
	{
		perror("wrong quote");
		exit(1);
	}
	else
		return (end);
}

int	count_token(char *s, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			i = count_quote(s, i) + 1;
			cnt++;
			continue ;
		}
		if (s[i] == '<' || s[i] == '>')
		{
			i = count_redir(s, i) + 1;
			cnt++;
			continue;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}