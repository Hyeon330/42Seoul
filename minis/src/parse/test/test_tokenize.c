#include "test.h"

void	init_vars(t_vars *vars)
{
	vars->token.cmd = NULL;
	//vars->token.cmd->red = NULL;
}

t_cmd	*init_cmd()
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (!cmd)
		error("malloc error");
	cmd->next = NULL;
	cmd->red = NULL;
	cmd->cmd = NULL;
	cmd->ac = -1;
	return (cmd);
	//ac도 초기화 해줘야하나?
}

t_redir	*init_redir()
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir) * 1);
	if (!redir)
		error("malloc error");
	redir->next = NULL;
	redir->file = NULL;
	redir->type = -1;
	return (redir);
	//타입초기화 비어있는걸 표시하려고 해뒀지만 필요없을 수도?
}

t_redir	*tokenize_redir(t_cmd *cmd, char *redir, char *file)
{
	t_redir	*temp;

	if (cmd->red == NULL)//cmd == NULL일수도없지. cmd는 init돼서 tokenize로 들어오니까
	{
		cmd->red = init_redir();
		temp = cmd->red;
	}
	else
	{
		temp = cmd->red;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = init_redir();
		temp = temp->next;
	}
	temp->type = check_redirection(redir);
	if (temp->type == HEREDOC)
		temp->file = "heredoc_temp";
	else
		temp->file = file;
	return (cmd->red);
}//이렇게 하면 릭이 나진 않을까?->새로 malloc하는건 새로 생긴 것 밖에 없으니 괜찮을듯

/*char	*tokenize_cmd(t_cmd *cmd, char *str)
{
	char	*old_cmd;

	if (cmd->cmd == NULL)
		cmd->cmd = ft_strdup(str);
	else
	{
		old_cmd = cmd->cmd;
		cmd->cmd = ft_strjoin(cmd->cmd, " ");
		free(old_cmd);
		old_cmd = cmd->cmd;
		cmd->cmd = ft_strjoin(cmd->cmd, str);
		free(old_cmd);
	}//여기서 바로 넣어야됨!
	return (cmd->cmd);
}*/

char	**tokenize_av(int cnt, char **splited)
{
	char	**av;
	int		i;
	int		j;

	i = 0;
	j = 0;
	av = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!av)
		error("malloc_error");
	av[cnt] = NULL;
	while (splited[j])
	{
		if (check_redirection(splited[j]) != -1)
			j++;
		else
		{
			av[i] = ft_strdup(splited[j]);
			i++;
		}
		j++;
	}
	return (av);
}

t_cmd	*tokenize(t_cmd *cmd, char **splited)
{
	int	i;
	int	av_cnt;

	i = 0;
	av_cnt = 0;
	while (splited[i])
	{
		if (check_redirection(splited[i]) != -1)
		{
			cmd->red = tokenize_redir(cmd, splited[i], splited[i + 1]);
			i++;
		}
		else
			av_cnt++;
			//cmd->cmd = tokenize_cmd(cmd, splited[i]);//옛날코드
		i++;
	}
	cmd->av = tokenize_av(av_cnt, splited);
	cmd->ac = av_cnt;
	return (cmd);
}//줄수 너무김 ->while (splited[i++])로 고쳐보기
//다하고나서 free_splited도 필요함

/*
int main()
{
	t_vars	vars;
	t_cmd	*cmd;
	t_cmd	*temp;
	t_cmd	*print_cmd;
	char	*str = " infile  -ls -al>> hello ls | grep 'hi'";
	char	**splited_pipe;
	char	**splited_cmd;
	int		i;
	int		j;

	init_vars(&vars);
	cmd = init_cmd();
	temp = cmd;
	splited_pipe = ft_split(str, '|');
	i = 0;
	while (splited_pipe[i])
	{
		//printf("splited pipe : %s\n", splited_pipe[i]);
		splited_cmd = split_token_main(splited_pipe[i]);
		syntax_check(splited_cmd, i);
		cmd = tokenize(cmd, splited_cmd);
		cmd->next = init_cmd();
		cmd = cmd->next;
		//temp = temp->next;
		i++;
	}
	printf("start\n");
	vars.token.cmd = temp;
	print_cmd = vars.token.cmd;
	while (print_cmd->next != NULL)
	{
		printf("print_cmd = %s\n", print_cmd->cmd);
		j = 0;
		while (print_cmd->av[j])
		{
			printf("av[%d] = %s\n", j, print_cmd->av[j]);
			j++;
		}
		print_cmd = print_cmd->next;
	}
	
		printf("redirection\n");
		while (print_cmd->red != NULL)
		{
			if (print_cmd->red->type == IN_REDIR)
				printf("type = <\n");
			else if (print_cmd->red->type == OUT_REDIR)
				printf("type = >\n");
			else if (print_cmd->red->type == APPEND)
				printf("type = >>\n");
			else if (print_cmd->red->type == HEREDOC)
				printf("type = <<\n");
			printf("filename : %s\n", print_cmd->red->file);
			print_cmd->red = print_cmd->red->next;
		}
		print_cmd = print_cmd->next;
	}
}*/
//gcc -g test_tokenize.c test_split.c test_split_token.c test_count_token.c test_syntax.c test_utils.c
//테스트문 next = null일때 종료조건 걸었는데 왜 종료 안되지? init할때 next는 null로 초기화 함