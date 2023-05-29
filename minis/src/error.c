/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:22:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/29 21:44:44 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(int e_no)
{
	char	*msg;

	write(2, "minish: ", 8);
	if (e_no < SYSTEM)
	{
		if (e_no == DYNAMIC)
			msg = "Dynamic allocation error\n";
		if (e_no == OLDPWD)
			msg = "cd: OLDPWD not set\n";
		while (*msg)
			write(2, msg++, 1);
	}
	else
		perror("minish");
	return (1);
}
