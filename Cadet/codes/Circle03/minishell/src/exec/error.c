/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:37:41 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/04 18:36:38 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_detail(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, ": ", 2);
}

int	ft_exec_err(int e_no, char *cmd, char *str)
{
	write(2, "minish: ", 8);
	if (cmd)
		print_detail(cmd);
	if (e_no < E_CRITICAL)
	{
		if (str)
			print_detail(str);
		if (e_no == EXEC_DYNAMIC)
			write(2, "Dynamic allocation failed\n", 26);
		if (e_no == EXEC_CNF)
			write(2, "command not found\n", 18);
		if (e_no == EXEC_ISDIR)
			write(2, "is a directory\n", 15);
		if (e_no == EXEC_PERM_DNI)
			write(2, "Permission denied\n", 18);
	}
	else
		perror(str);
	if (e_no >= E_FILE && e_no < E_CRITICAL)
		return (126);
	return (1);
}
