/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:37:47 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/12 18:26:58 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strjoin(char **dst, char *src, ssize_t dst_len, ssize_t src_len)
{
	char	*pc;
	ssize_t	pc_i;
	ssize_t	i;

	pc = (char *)malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!pc)
	{
		FREE(*dst);
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
	FREE(*dst);
	*dst = pc;
}
