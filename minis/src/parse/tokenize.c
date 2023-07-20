#include "minishell.h"

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
		temp->file = heredoc_main(file);
	else
		temp->file = file;
	return (cmd->red);
}

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
		i++;
	}
	cmd->av = tokenize_av(av_cnt, splited);
	cmd->ac = av_cnt;
	return (cmd);
}