/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ms_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:42:54 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:49:12 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ms_calloc(size_t count, size_t size)
{
	void	*pv;

	if (count == (size_t)-1 || size == (size_t)-1)
		return (NULL);
	pv = malloc(count * size);
	if (pv == NULL)
	{
		write(2, "Error : Dynamic Memory Allocation Failed!", 41);
		return (NULL);
	}
	return (ft_memset(pv, 0, count * size));
}
