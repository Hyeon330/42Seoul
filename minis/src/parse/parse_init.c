#include "minishell.h"

t_cmd	*init_cmd()
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (!cmd)
		error("malloc error");
	cmd->next = NULL;
	cmd->red = NULL;
	cmd->av = NULL;
	cmd->ac = 0;//ac도 초기화 해줘야하나?
	return (cmd);
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
	return (redir);	//타입초기화 비어있는걸 표시하려고 해뒀지만 필요없을 수도?
}

/*t_token	init_token(char *str)
{
	t_token	token;

	token = (t_token *)malloc(sizeof(t_token) * 1);
	if (!token)
		error("malloc error");//에러 처리 물어보기
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
}*/
//메인에서 하기로 함