#include "minishell.h"

char	**free_result(char **s)
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

char	*when_redir(char **s)
{
	char	*redir;

	redir = *s;
	if (*s + 1)
}

char	*when_charset(char **s, char c)
{
	char	*tmp;
	char	*result;

	tmp = *s;
	while (**s && **s != c)
		*s += 1;
	result = (char *)malloc(sizeof(char) * (*s - tmp + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, tmp, *s - tmp + 1);
	return (result);
}

char	*splite_quote(char *s)
{
	char	*result;
	char	quote;
	int		end;

	quote = s[0];
	end = 1;
	while (s[end != quote])
	{
		end++;
	}
	result = ft_substr(s, 1, end - 1);
	return (result);
}

char	*when_quote(char **s)
{
	char	*quote;
	char	*result;

	quote = splite_quote(*s);
	result = (char *)malloc(sizeof(char) * (ft_strlen(quote) + 1));
	if (!result)
		error("malloc error");
	ft_strlcpy(result, quote, ft_strlen(quote) + 1);
	if (!result)
		free_result(result);
	*s += (ft_strlen(quote) + 2);
	free(quote);
	return (result);
}

char	**do_splited(char *s, char **splited, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
			result[i++] = when_quote(&s);
			continue ;
		else if (*s == '>' || *s == '<')
			result[i++] = when_redir(&s);
			continue;
		else if (*s != c)
			result[i++] = when_charset(&s, c);
		else
			s++;
	}
	return (result);
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
	splited = do_split(str, splited, ' ');
}
