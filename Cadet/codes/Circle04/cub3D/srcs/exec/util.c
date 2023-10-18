/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:52:56 by hoseoson          #+#    #+#             */
/*   Updated: 2023/10/05 23:03:27 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	close_win(void)
{
	exit(EXIT_SUCCESS);
}
