/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:59:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/24 16:15:31 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	size_t			i;

	if (ft_strlen(s2) == 0)
		return (1);
	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (!_s1[i] || !_s2[i] || _s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
	}
	return (0);
}
