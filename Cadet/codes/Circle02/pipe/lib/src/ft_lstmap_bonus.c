/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:49:43 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 17:45:50 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_list	*make_new_lst(char *content, void (*del)(void *))
{
	t_list	*tmp;

	if (!content)
		return (NULL);
	tmp = ft_lstnew(content);
	if (!tmp)
	{
		del(content);
		return (NULL);
	}
	return (tmp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = make_new_lst(f(lst->content), del);
	if (!new_lst)
		return (NULL);
	lst = lst->next;
	tmp = new_lst;
	while (lst)
	{
		tmp->next = make_new_lst(f(lst->content), del);
		if (!tmp->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_lst);
}
