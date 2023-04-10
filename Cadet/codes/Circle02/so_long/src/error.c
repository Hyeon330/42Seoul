/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:32:05 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/10 21:44:08 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_error(int errno)
{
	char	*msg;

	if (errno < 32)
	{
		if (errno == ARGUMENT)
			msg = "Argument Error\n";
		if (errno == DYNAMIC)
			msg = "Dynamic allocation error\n";
		if (errno == FORMAT)
			msg = "Incorrectly formatted map\n";
		if (errno == EXTENTION)
			msg = "Invalid extension file\n";
		while (*msg)
			write(2, msg++, 1);
	}
	else
	{
		if (errno == OPEN)
			msg = "Failed to open map";
		perror(msg);
	}
	exit(EXIT_FAILURE);
}
