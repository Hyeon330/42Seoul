/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:09:18 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 20:54:33 by hyeonsul         ###   ########.fr       */
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
