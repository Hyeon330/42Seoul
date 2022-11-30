/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:27:01 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/09 20:45:11 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
