#include "minishell.h"

void	init_vars(t_vars *vars)
{
	vars->token.cmd = NULL;
	vars->token.cmd->red = NULL;
}//포인터는 null로 초기화해 줌