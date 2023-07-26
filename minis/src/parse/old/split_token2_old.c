#include "minishell.h"

char	*when_redir(char **s)
{
	char	*result;
	int		len;

	char	*temp;
	temp = *s;
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
	char	*replaced_result;

	tmp = *s;
	while (**s && **s != c && **s != '<' && **s != '>')
		*s += 1;
	result = (char *)malloc(sizeof(char) * (*s - tmp + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, tmp, *s - tmp + 1);
	if (count_replace(result) != 0)
	{
		replaced_result = replace_character(result, vars, count_replace(result));
		return (replaced_result);
	}
	return (result);
}

char	*when_quote(char **s)
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
