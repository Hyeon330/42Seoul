#include "minishell.h"

int	get_tokcnt(char **tok)
{
	int	i;

	i = 0;
	while (tok[i])
		i++;
	return (i);
}

char	*get_cmd_from_av(char *av0)
{
	if (av0)
		return(ft_strdup(av0));
	return (ft_strdup(""));
}