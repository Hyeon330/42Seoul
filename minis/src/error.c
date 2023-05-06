/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:22:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/06 03:53:23 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(int e_no)
{
	char	*msg;

	msg = NULL;
	if (e_no == DYNAMIC)
		msg = "Dynamic allocation error\n";
	while (*msg)
		write(2, msg++, 1);
	exit(EXIT_FAILURE);
}