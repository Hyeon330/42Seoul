#include "minishell.h"

void	lstcmd_del_node(t_cmd* node)
{
	if (!node)
		return;
	free_ptr(node->cmd);
	free_str_array(node->av);
	free_ptr(node);
}

void	lstcmd_clear(t_cmd** list)
{
	t_cmd	*next_node;
	t_cmd	*node;
	int		i;

	i = 0;
	if (!list)
		return;
	while (list[i])
	{
		node = list[i];
		while (node)
		{
			next_node = node->next;
			lstcmd_del_node(node);
			node = next_node;
		}
		i++;
	}
}
