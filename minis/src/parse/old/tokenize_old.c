#include "minishell.h"

void	tokenize_redir(t_cmd *cmd, char *redir, char *file)
{
	t_redir	*temp;

	temp = cmd->red;
	while (temp != NULL)
	{
		temp = temp->next;
	}
	temp = init_redir();
	temp->type = check_redirection(redir);
	temp->file = file;
}

/*void	tokenize_file(t_cmd *cmd, char *str)
{
	t_redir	*temp;

	temp = cmd->red;
	while (temp->file != NULL)
	{
		temp = temp->next;
	}
	temp->file = str;
}*///tokenize_redir와 합침

void	tokenize_cmd(t_cmd *cmd, char *str, char *option)
{
	char	*blank_add_str;
	char	*joined_str;
	char	**argv;

	if (cmd == NULL)
		cmd = init_cmd();
	if (option != NULL)
	{
		blank_add_str = ft_strjoin(cmd->cmd, ' ');
		joined_str = ft_strjoin(blank_add_str, str);
		free(blank_add_str);
		free(str);
		argv = ft_split(joined_str, ' ');
		cmd->av = argv;
		cmd->ac = 2;
	}
	else
	{
		argv = (char *)malloc(sizeof(argv) * 2);
		if (!argv)
			error("malloc error");
		argv[1] = NULL;
		ft_strcpy(argv[0], str);
		cmd->ac = 1;
	}
}

void	tokenize(t_cmd *cmd, char **splited, int i)
{
	while (splited[i])
	{
		if (check_redirection(splited[i]) == 1)
		{
			tokenize_redir(cmd, splited[i], splited[i + 1]);
			i += 2;
		}
		else
		{
			if (splited[i + 1] && check_redirection(splited[i + 1]) == -1)
			{
				tokenize_cmd(cmd, splited[i], splited[i + 1]);
				i++;
			}
			else
				tokenize_cmd(cmd, splited[i], NULL);
			i++;//굳이 else가 필요한가?
		}
	}
}