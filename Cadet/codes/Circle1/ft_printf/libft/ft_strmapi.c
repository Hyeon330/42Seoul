/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:32:10 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/11 22:47:17 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pc;
	int		s_size;
	int		i;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	pc = (char *)malloc(sizeof(char) * s_size + 1);
	if (!pc)
		return (NULL);
	pc[s_size] = 0;
	i = -1;
	while (s[++i])
		pc[i] = f(i, s[i]);
	return (pc);
}
