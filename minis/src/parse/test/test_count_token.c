#include "test.h"

void	error(char *msg)
{
	perror(msg);
	exit(errno);
}

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
		error("wrong quote");
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
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0' || s[i + 1] == '>' || s[i + 1] == '<'))
			cnt++;
		i++;
	}
	return (cnt);
}
/*
int main()
{
	char	*str = "infile   -ls -al>> hello    < > >>hi<   ls";
	int		cnt = count_token(str, ' ');

	printf ("%d\n", cnt);
}
*/