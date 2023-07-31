#include "minishell.h"

int	count_token(char *str)
{
	int		i;
	int		cnt;
	char	q;

	i = 0;
	cnt = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			i = replace_index_quote(str, i);
		if (is_redir(str, i) != 0)
		{
			if (is_redir(str, i) == 3 || is_redir(str, i) == 4)
				i++;
			cnt++;
		}
		else if (is_white_space(str[i]) != 1 && (str[i + 1] == '\0' \
		|| is_redir(str, i + 1) != 0 || is_white_space(str[i + 1]) == 1))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**do_split_token(char *str, int cnt)
{
	char	**splited_token;
	int		i;
	int		j;
	int		start;

	splited_token = (char **)malloc(sizeof(char *) * (cnt + 1));
	 if (!splited_token)
	 	error("malloc error");
	splited_token[cnt] = NULL;
	i = 0;
	j = 0;
	start = -1;
	while (str[i])
	{
		if (start == -1 && is_white_space(str[i]) != 1)
			start = i;
		if (str[i] == 34 || str[i] == 39)
			i = replace_index_quote(str, i);
		if (is_redir(str, i) != 0)
		{
			if (is_redir(str, i) == 3 || is_redir(str, i) == 4)
				i++;
			splited_token[j] = ft_substr(str, start, i - start + 1);
			j++;
			start = -1;
		}
		else if (is_white_space(str[i]) != 1 && (str[i + 1] == '\0' \
		|| is_redir(str, i + 1) != 0 || is_white_space(str[i + 1]) == 1))
		{
			splited_token[j] = ft_substr(str, start, i - start + 1);
			j++;
			start = -1;
		}
		i++;
	}
	return (splited_token);
}

char	**split_token_main(char *splited_pipe)
{
	int		cnt;
	char	**splited_token;

	cnt = count_token(splited_pipe);
	splited_token = do_split_token(splited_pipe, cnt);
	remove_quote_main(splited_token);
	return (splited_token);
}