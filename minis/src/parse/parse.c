#include "minishell.h"

void	do_parse(t_vars *vars, char **splited_pipe)
{
	int		i;
	char	**splited_token;
	t_cmd	*tmp;

	i = 0;
	while (splited_pipe[i])
	{
		splited_token = split_token_main(splited_pipe[i]);
		if (i == 0)
		{
			vars->token.cmd = tokenize(splited_token);
			tmp = vars->token.cmd;
		}
		else
		{
			tmp->next = tokenize(splited_token);
			tmp = tmp->next;
		}
		i++;
	}
	vars->token.size = i;
}

int	parse(t_vars *vars, char *str)
{
	char	**splited_pipe;
	int	i;

	i = 0;
	splited_pipe = check_readline(str);
	if (!splited_pipe)
		return (0);
	do_parse(vars, splited_pipe);
	//free_two_dimen(splited_pipe);
	return (1);
}