t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list->content = content;
	list->next = NULL;
	return (list);
}
