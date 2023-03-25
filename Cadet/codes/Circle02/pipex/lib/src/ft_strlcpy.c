/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:27:01 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 17:51:12 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (dstsize)
	{
		if (i == dstsize)
			*(dest + dstsize - 1) = 0;
		else
			*(dest + i) = 0;
	}
	return (ft_strlen(src));
}
