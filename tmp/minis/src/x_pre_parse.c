#include "minishell.h"
void	syntax_error_exit(char *errmsg)
{
	ft_putendl_fd(errmsg, STDERR_FILENO);
	exit(2);
}

bool	check_syntax_quotes(char *str)
{
	bool	sq_open;
	bool	dq_open;

	sq_open = false;
	dq_open = false;
	while (*str)
	{
		if (*str == '\'' && dq_open == false)
			sq_open = !sq_open;
		if (*str == '"' && sq_open == false)
			dq_open = !dq_open;
		str++;
	}
	if (sq_open)
		syntax_error_exit("Syntax Error: single quote not closed.");
	else if (dq_open)
		syntax_error_exit("Syntax Error: double quote not closed.");
	return (true);
}

char *pre_parse(char *inln, t_tree env)
{
	char	*new;
	bool	ok;

	ok = false; 
	new = ms_strtrim_free(inln, " \t\v\n\r\f");
	ok = check_syntax_quotes(inln);
	if (ok)
	{
		new = check_input_env_home(new, env);
	}
	return (new);
}

