#include "minishell.h"

t_redir	*init_redir(void)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir) * 1);
	if (!redir)
		error("malloc error");
	redir->file = NULL;
	redir->next = NULL;
	redir->type = -1;
	return (redir);
}

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (!cmd)
		error("malloc error");
	cmd->next = NULL;
	cmd->ac = 0;
	cmd->av = NULL;
	cmd->red = NULL;
	return (cmd);
}