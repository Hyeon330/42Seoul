#include "minishell.h"

void	error(char *msg)
{
	perror(msg);
	exit(errno);
}