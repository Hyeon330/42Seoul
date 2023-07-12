#include "test.h"

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
		splited_cmd = split_token_main(splited_pipe[i]);
		//syntax_check(splited_cmd, i);
		cmd = tokenize(cmd, splited_cmd);
		cmd->next = init_cmd();
		cmd = cmd->next;
		i++;
	}
	vars->token.cmd = temp;
}

int main()
{
	t_vars	vars;
	char	*str = " infile  -ls -al>> hello ls | grep 'hi'";
	t_cmd	*cmd;
	t_redir	*redir;

	init_vars(&vars);
	parse(&vars, str);

	cmd = vars.token.cmd;
	while (cmd != NULL)
	{
		printf("cmd : %s\n", cmd->cmd);
		for(int i = 0; cmd->av[i]; i++)
		{
			printf("av[%d] : %s\n", i, cmd->av[i]);
		}
		printf("redir\n");
		redir = cmd->red;
		while (redir != NULL)
		{
			printf("type : %d\n", redir->type);
			printf("file : %s\n", redir->file);
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}
// gcc -g test_parse.c test_tokenize.c test_split.c test_split_token.c test_count_token.c test_syntax.c test_utils.c
//여기서 다들어가면 성공