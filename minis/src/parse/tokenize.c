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

t_token	init_token(char *str)
{
	t_token	token;

	/*token = (t_token *)malloc(sizeof(t_token) * 1);
	if (!token)
		error("malloc error");//에러 처리 물어보기*/
	token.cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!token.cmd)
		error("malloc error");
	token.cmd->next = NULL;
	token.cmd->red = (t_redir *)malloc(sizeof(t_redir));
	if (!token.cmd->red)
		error("malloc error");
	token.cmd->red = NULL;
	token.size = get_token_size(str);
	return (token);
}//다른 항목도 필요하면 초기화 해주기

int		check_redirection(char *str)
{
	if (strncmp(str, '<<' , ft_strlen(str)) != 0 && \
	strncmp(str, '>>' , ft_strlen(str)) != 0 && \
	strncmp(str, '<' , ft_strlen(str)) != 0 && \
	strncmp(str, '>' , ft_strlen(str)) != 0)
		return (-1);
	return (1);
}

void	add_redirection(t_token *token, char *str)
{
	while (token->cmd->next != NULL)
	{
		token->cmd = token->cmd->next;
	}
	
}

void	add_redir_file(t_token *token, char *str)
{

}

void	add_cmd(t_token *token, char *str)
{

}

void	tokenize(t_token *token, char *str)
{
	char	**splited;
	int		i;

	splited = split_token(str);
	while (splited[i])
	{
		if (check_redirection(splited[i]) == 1)
		{
			add_redirection(token, str);
			i++;
			add_redir_file(token, str);
		}
		else
			add_cmd(token, str);
		i++;
	}
}

void	tokenize_main(t_vars *vars, char *str)
{
	//t_token	*token;
	char	**splited_pipe;
	int			i;

	//token = init_token(str);
	splited_pipe = ft_split(str, '|');
	i = 0;
	while (splited_pipe[i])
	{
		tokenize(&(vars->token), splited_pipe[i]);
		i++;
	}

}