/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:09:18 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/10 00:26:03 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*copy;

	copy = NULL;
	while (*s)
	{
		if (*s == (char) c)
			copy = (char *) s;
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (copy);
}
