/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:19:35 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 17:50:25 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strdup(const char *src)
{
	char	*pc;
	int		i;

	i = 0;
	while (src[i])
		i++;
	pc = (char *)malloc(sizeof(char) * (i + 1));
	if (pc == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		pc[i] = src[i];
		i++;
	}
	pc[i] = 0;
	return (pc);
}
