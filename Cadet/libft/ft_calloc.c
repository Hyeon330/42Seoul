/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:52:19 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/11 15:32:34 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pv;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	pv = malloc(count * size);
	if (pv == NULL)
		return (NULL);
	return (ft_memset(pv, 0, count * size));
}
