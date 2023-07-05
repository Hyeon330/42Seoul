#include "minishell.h"

void	get_pipe_wordcnt_pass_qt(char **s)
{
	if (**s == '\'')
		while (*(++(*s)) && **s != '\'')
			;
	else if (**s == '"')
		while (*(++(*s)) && **s != '"')
			;
}
