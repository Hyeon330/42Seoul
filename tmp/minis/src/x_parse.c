#include "minishell.h"

int	is_redir(char *str)
{
	if (!str)
		return (0);
	if (!ms_strcmp(str, "<"))
		return(IN_REDIR);
	if (!ms_strcmp(str, ">"))
		return(OUT_REDIR);
	if (!ms_strcmp(str, "<<"))
		return(HERE_DOC);
	if (!ms_strcmp(str, ">>"))
		return(APPEND);
	return (0);
}

int parse(t_cmd ***cmds, int *cmds_cnt, char *strln)
{
	char	**cmdlns;
	char	**cmdln_tokens;
	int		i;
	t_cmd	**root;

	cmdlns = NULL;
	cmdln_tokens = NULL;
	cmdlns = split_pipe(strln, cmds_cnt);
	*cmds = ft_calloc(*cmds_cnt + 1, sizeof(**cmds));
	i = -1;
	while (++i < *cmds_cnt && cmdlns[i])
	{
		cmdln_tokens = split_tok(cmdlns[i]);
		root = &((*cmds)[i]);
		build_nodes(root, cmdln_tokens, get_tokcnt(cmdln_tokens));
	}
	free_str_array(cmdlns);
	free_str_array(cmdln_tokens);
	return (0);
}
