/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:37:47 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 17:53:45 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

void	ft_strjoin(char **dst, char *src, ssize_t dst_len, ssize_t src_len)
{
	char	*pc;
	ssize_t	pc_i;
	ssize_t	i;

	pc = (char *)malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!pc)
	{
		free(*dst);
		*dst = NULL;
		return ;
	}
	pc[dst_len + src_len] = 0;
	pc_i = 0;
	i = 0;
	while (i < dst_len)
		pc[pc_i++] = (*dst)[i++];
	i = 0;
	while (i < src_len)
		pc[pc_i++] = src[i++];
	free(*dst);
	*dst = pc;
}

t_buflst	*isfd(t_buflst *buflst, int fd)
{
	while (buflst)
	{
		if (buflst->fd == fd)
			return (buflst);
		buflst = buflst->next;
	}
	return (NULL);
}

t_buflst	*lstnew(int fd)
{
	t_buflst	*lst;

	lst = (t_buflst *)malloc(sizeof(t_buflst));
	if (!lst)
		return (NULL);
	lst->buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!lst->buf)
	{
		free(lst);
		return (NULL);
	}
	lst->next = NULL;
	lst->read_size = 0;
	lst->buf_i = 0;
	lst->fd = fd;
	return (lst);
}

void	lstadd_back(t_buflst **lst, t_buflst *new)
{
	t_buflst	*tmp;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	lstdelone(t_buflst **lst, t_buflst *lst_copy, int fd)
{
	t_buflst	*tmp;

	if (!lst || !(*lst))
		return ;
	if ((*lst)->fd == fd)
	{
		tmp = (*lst)->next;
		free((*lst)->buf);
		free(*lst);
		*lst = tmp;
		return ;
	}
	while (lst_copy->next)
	{
		if (lst_copy->next->fd == fd)
		{
			tmp = lst_copy->next->next;
			free(lst_copy->next->buf);
			free(lst_copy->next);
			lst_copy->next = tmp;
			break ;
		}
		lst_copy = lst_copy->next;
	}
}
