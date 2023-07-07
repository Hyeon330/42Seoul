/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_free_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:43:12 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:43:12 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str_array(char **str_array)
{
	int	i;

	i = -1;
	while (str_array[++i])
		free(str_array[i]);
	free(str_array);
}

void	free_ptr1(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
