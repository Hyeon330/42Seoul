/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:37:41 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/12 18:45:25 by hyeonsul         ###   ########.fr       */
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
	if (e_no < E_CRITICAL)
	{
		if (str)
			write(2, str, ft_strlen(str));
		if (e_no == EXEC_DYNAMIC)
			write(2, "Dynamic allocation failed\n", 26);
		if (e_no == EXEC_CNF)
			write(2, "command not found\n", 18);
		if (e_no == EXEC_ISDIR)
			write(2, "is a directory\n", 15);
		if (e_no >= E_FILE)
			exit(126);
	}
	else
		perror(str);
	return (1);
}