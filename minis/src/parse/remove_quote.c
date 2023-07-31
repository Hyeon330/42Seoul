#include "minishell.h"

int	check_quote(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			cnt++;
			//i = replace_index_quote(str, i);
		}
		i++;
	}
	return (cnt);
}

char	*remove_quote(char *splited_token)
{
	int		cnt;
	int		len;
	int		i;
	int		j;
	char	*removed;

	cnt = check_quote(splited_token);
	len = ft_strlen(splited_token) - cnt;
	i = 0;
	j = 0;
	removed = (char *)malloc(sizeof(char) * (len + 1));
	if (!removed)
		error("malloc_error");
	removed[len] = '\0';
	while (splited_token[i])
	{
		if (splited_token[i] != 34 && splited_token[i] != 39)
		{
			removed[j] = splited_token[i];
			j++;
		}
		i++;
	}
	return (removed);
}

void	remove_quote_main(char **splited_token)
{
	int		i;
	char	*old;

	i = 0;
	while (splited_token[i])
	{
		if (check_quote(splited_token[i]) != 0)
		{
			old = splited_token[i];
			splited_token[i] = remove_quote(splited_token[i]);
			free(old); 
		}
		i++;
	}
}