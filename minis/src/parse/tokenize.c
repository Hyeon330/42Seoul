#include "minishell.h"

t_redir	*tokenize_redir(t_cmd *cmd, char *redir, char *file)
{
	t_redir	*temp;
	temp = cmd->red;
	if (temp == NULL)
		temp = init_redir();
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = init_redir();
		temp = temp->next;
	}
	temp->type = check_redirection(redir);
	if (temp->type == HEREDOC)
	{
		heredoc(file);
		temp->file = "heredoc_temp";
	}
	else
		temp->file = file;
	return (cmd->red);
}//이렇게 하면 릭이 나진 않을까?->새로 malloc하는건 새로 생긴 것 밖에 없으니 괜찮을듯

char	*tokenize_cmd(t_cmd *cmd, char *str)
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
	}
	return (cmd->cmd);
}

t_cmd	*tokenize(t_cmd *cmd, char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (check_redirection(splited[i]) == 1)
		{
			cmd->red = tokenize_redir(cmd, splited[i], splited[i + 1]);
			i++;
		}
		else
			cmd->cmd = tokenize_cmd(cmd, splited[i]);
		i++;
	}
	cmd->av = ft_split(cmd->cmd, ' ');
	free(cmd->cmd);
	cmd->cmd = ft_strdup(cmd->av[0]);
	return (cmd);
}