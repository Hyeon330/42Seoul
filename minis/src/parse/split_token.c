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

char	*when_redir(char **s)
{
	char	*result;
	char	redir;
	int		len;

	char	*temp;
	temp = *s;
	redir = temp[0];
	len = 1;
	if (temp[0] == temp[1])
		len++;
	result = (char *)malloc(sizeof(char *) * len);
	if (!result)
		error("malloc error");
	ft_strlcpy(result, temp, len + 1);
	if (!result)
		free_splited_token(&result);
	*s += len;
	return (result);
}

char	*when_charset(char **s, char c, t_vars vars)
{
	char	*tmp;
	char	*result;
	char	*old_result;

	tmp = *s;
	while (**s && **s != c && **s != '<' && **s != '>')
		*s += 1;
	result = (char *)malloc(sizeof(char) * (*s - tmp + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, tmp, *s - tmp + 1);
	if (count_replace(result) != -1)
	{
		old_result = result;
		result = replace_character(s, vars, count_replace(result));
		free(old_result);
	}
	return (result);
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

char	*when_quote(char	**s)
{
	char	*quote;
	char	*result;

	quote = split_quote(*s);
	result = (char *)malloc(sizeof(char) * (ft_strlen(quote) + 1));
	if (!result)
	{
		free(result);
		return (0);
	}
	ft_strlcpy(result, quote, ft_strlen(quote) + 1);
	*s += (ft_strlen(quote) + 2);
	free(quote);
	return (result);
}

char	**do_split_token(char *s, char **splited, char c, t_vars vars)
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
			splited[i++] = when_charset(&s, c, vars);
		else
			s++;
	}
	return (splited);
}

char	**split_token_main(char *str, t_vars vars)
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
	splited = do_split_token(str, splited, ' ', vars);
	return (splited);
}
