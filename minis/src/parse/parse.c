#include "minishell.h"

int	parse(t_vars *vars, char *str)
{
	t_cmd	*cmd;
	t_cmd	*temp;
	char	**splited_pipe;
	char	**splited_cmd;
	int		i;

	if (check_only_whitespace(str) == 1)
		return (0);
	cmd = vars->token.cmd;
	cmd = init_cmd();
	temp = cmd;
	splited_pipe = ft_split(str, '|');
	i = 0;
	while (splited_pipe[i])
	{
		if (check_only_whitespace(splited_pipe[i]) == 1)
			error("parse error near '|'");
		i++;
	}
	i = -1;
	while (splited_pipe[++i])
	{
		splited_cmd = split_token_main(splited_pipe[i]);
		syntax_check(splited_cmd, i);
		cmd = tokenize(cmd, splited_cmd);
		if (!splited_pipe[i + 1])
			break ;
		cmd->next = init_cmd();
		cmd = cmd->next;
	}
	vars->token.size = i + 1;
	vars->token.cmd = temp;
	return (1);
}
//parse_main
//vars에 담기는지 확인하기!->cmd, redir담김!