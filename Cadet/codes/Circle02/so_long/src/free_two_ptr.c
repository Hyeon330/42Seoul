/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_two_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:07:02 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/05 21:44:42 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	free_two_ptr_int(int **ptr, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		free(ptr[i]);
	free(ptr);
}

void	free_two_ptr_char(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[i])
		free(ptr[i]);
	free(ptr);
}
