/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:37:41 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/07 20:26:40 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_err(int e_no, char *cmd, char *str)
{
	write(2, "minish: ", 8);
	if (cmd)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": ", 2);
	}
	if (e_no < 32)
	{
		if (str)
			write(2, str, ft_strlen(str));
		if (e_no == EXEC_DYNAMIC)
			write(2, "Dynamic allocation failed\n", 26);
	}
	else
		perror(str);
	return (1);
}