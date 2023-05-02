/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:50:19 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 20:50:37 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf;
	unsigned char	*_dst;
	size_t			i;

	buf = (unsigned char *)src;
	_dst = (unsigned char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		while (i < len)
		{
			_dst[i] = buf[i];
			i++;
		}
	}
	else
	{
		while (len--)
			_dst[len] = buf[len];
	}
	return (dst);
}
