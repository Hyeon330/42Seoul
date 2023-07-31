#include "minishell.h"

int	error_parse(int error, t_vars *vars)
{
	if (error == 258)
		write(2, "syntax error\n", 14);
	vars->exit_code = error;
	return (0);
}

void	error(char *msg)
{
	perror(msg);
	exit(1);
}