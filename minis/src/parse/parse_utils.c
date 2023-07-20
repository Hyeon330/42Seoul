#include "minishell.h"

int	get_token_size(char *str)
{
	int	pipe_cnt;
	int	i;

	pipe_cnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			pipe_cnt++;
		i++;
	}
	return (pipe_cnt + 1);
}

int	check_redirection(char *str)
{
	int	flag;

	flag = 1;
	if (ft_strncmp(str, "<<" , ft_strlen("<<")) == 0)
		flag = HEREDOC;
	else if (ft_strncmp(str, ">>" , ft_strlen(">>")) == 0)
		flag = APPEND;
	else if (ft_strncmp(str, "<" , ft_strlen("<")) == 0)
		flag = IN_REDIR;
	else if (ft_strncmp(str, ">" , ft_strlen(">")) == 0)
		flag = OUT_REDIR;
	else
		flag = -1;
	return (flag);
}

int	check_only_whitespace(char *str)
{
	int	len;
	int	cnt;
	int	i;

	len = ft_strlen(str);
	cnt = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			cnt++;
		i++;
	}
	if (cnt == len)
		return (1);
	return (-1);
}