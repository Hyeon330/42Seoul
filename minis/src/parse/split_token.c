#include "minishell.h"

void	free_splited_token(char **s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		free((s[j]));
		j++;
	}
	free(s);
	error("splite error");
}

char	*split_quote(char *s)
{
	char	*result;
	char	quote;
	int		end;

	quote = s[0];
	end = 1;
	while (s[end] != quote)
	{
		end++;
	}
	result = ft_substr(s, 1, end - 1);
	return (result);
}

char	**do_split_token(char *s, char **splited, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
			splited[i++] = when_quote(&s);
		else if (*s == '>' || *s == '<')
			splited[i++] = when_redir(&s);
		else if (*s != c)
			splited[i++] = when_charset(&s, c);
		else
			s++;
	}
	return (splited);
}

char	**split_token_main(char *str)
{
	int		i;
	int		cnt;
	char	**splited;

	i = 0;
	cnt = count_token(str, ' ');
	splited = (char **)malloc(sizeof(char *) * cnt + 1);
	if (!splited)
		error("malloc error");
	splited[cnt] = NULL;
	splited = do_split_token(str, splited, ' ');
	return (splited);
}
