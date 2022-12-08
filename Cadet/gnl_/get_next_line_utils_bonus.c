/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:37:47 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/08 23:37:57 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	isbuflst(t_buflst **buflst, int fd)
{
	while (*buflst)
	{
		if (*buflst->fd == fd)
			return (1);
		*buflst = (*buflst)->next;
	}
	return (0);
}

void	lst_free(t_buflst **buflst)
{
	
}
