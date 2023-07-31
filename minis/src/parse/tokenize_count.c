#include "minishell.h"

int	count_av(char **splited_token)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (splited_token[i])
	{
		if (check_redirection(splited_token[i]) == -1)
			cnt++;
		else
			i++;
		i++;
	}
	return (cnt);
}

int	count_rd(char **splited_token)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (splited_token[i])
	{
		if (check_redirection(splited_token[i]) != -1)
		{
			cnt += 2;
			i++;
		}
		i++;
	}
	return (cnt);
}