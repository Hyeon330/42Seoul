/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:37:39 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 20:53:48 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	des_len;
	size_t	src_len;
	size_t	max_len;

	if (!dest && !dstsize)
		return (ft_strlen(src));
	des_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	max_len = des_len + src_len;
	if (des_len >= dstsize)
		return (src_len + dstsize);
	while (*dest)
		dest++;
	i = 0;
	while (dstsize > des_len + 1 + i && *src)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = 0;
	return (max_len);
}
