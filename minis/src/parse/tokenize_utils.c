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
	enum e_redir_type	redir_type;

	if (strncmp(str, '<' , ft_strlen(str)) != 0)
		redir_type = IN_REDIR;
	else if (strncmp(str, '>' , ft_strlen(str)) != 0)
		redir_type = OUT_REDIR;
	else if (strncmp(str, '<<' , ft_strlen(str)) != 0 || \
	strncmp(str, '>>' , ft_strlen(str)) != 0)
		redir_type = APPEND;
	else
		return (-1);
}