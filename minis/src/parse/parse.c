#include "minishell.h"

void	parse(t_vars *vars, char *str)
{
	t_cmd	*cmd;
	t_cmd	*temp;
	char	**splited_pipe;
	char	**splited_cmd;
	int		i;

	cmd = vars->token.cmd;
	cmd = init_cmd();
	temp = cmd;
	splited_pipe = ft_split(str, '|');
	i = 0;
	while (splited_pipe[i])
	{
		splited_cmd = split_token_main(splited_pipe[i], *vars);
		syntax_check(splited_cmd, i);
		cmd = tokenize(cmd, splited_cmd);
		cmd->next = init_cmd();
		cmd = cmd->next;
		i++;
	}
	vars->token.cmd = temp;
}//parse_main
//vars에 담기는지 확인하기!