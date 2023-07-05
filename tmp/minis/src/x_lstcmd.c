#include "minishell.h"

t_cmd	*lstcmd_new()
{
	t_cmd	*new_node;

	new_node = (t_cmd*)malloc(sizeof(t_cmd));
	if (!(new_node))
		return (NULL);
	ft_memset(new_node, 0, sizeof(t_cmd));
	return (new_node);
}

void	lstcmd_add_back(t_cmd** list, t_cmd* new_node)
{
	t_cmd	*start_node;
	t_cmd	*node;

	if (!list || !new_node)
		return;
	start_node = *list;
	if (start_node == NULL)
	{
		*list = new_node;
		return;
	}
	if (list && *list && new_node)
	{
		node = lstcmd_last(*list);
		node->next = new_node;
	}
}

void	lstcmd_add_front(t_cmd** list, t_cmd* new_node)
{
	if (!list || !new_node)
		return;
	new_node->next = *list;
	*list = new_node;
}

t_cmd	*lstcmd_last(t_cmd* list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int		lstcmd_size(t_cmd** list)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (list[i])
	{
		cnt++;
		i++;
	}
	return (cnt);
}
