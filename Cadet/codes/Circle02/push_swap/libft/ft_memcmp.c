/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:28:11 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/10 02:43:34 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*_s1;
	unsigned char		*_s2;
	size_t				i;

	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (_s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
		i++;
	}
	return (0);
}
