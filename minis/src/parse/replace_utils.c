#include "minishell.h"

int	check_wave(char *str, int i)
{
	int	result;

	result = 0;
	if (str[i] != '~')
		return (0);
	if (i == 0 && (str[i + 1] == '/' || is_white_space(str[i + 1]) == 1 \
	|| str[i + 1] == '\0'))
		result = 1;
	if (i != 0 && is_white_space(str[i - 1]) == 1 && (str[i + 1] == '/' \
	|| is_white_space(str[i + 1]) || str[i + 1] == '\0'))
		result = 1;
	return (result);
}

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (-1);
}

int	replace_index_quote(char *str, int i)
{
	char	q;

	q = str[i];
	i++;
	while (str[i] != q)
	{
		i++;
	}
	return (i);
}

int	find_end_index_env(char	*str, int i)
{
	i++;
	while (str[i] != '\0' && is_white_space(str[i]) != 1 \
	&& str[i] != 34 && str[i] != 39 && str[i] != '$' && str[i] != '~')
	{
		i++;
	}
	return (i - 1);
}