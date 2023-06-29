/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:22:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 11:13:05 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(int e_no, char *str)
{
	write(2, "minish: ", 8);
	if (e_no < 32)
	{
		if (str)
			write(2, str, ft_strlen(str));
		if (e_no == DYNAMIC)
			write(2, "Dynamic allocation failed\n", 26);
		if (e_no == ISADIR)
		{
			write(2, ": is a directory\n", 17);
			exit(126);
		}
		if (e_no == CNF)
			write(2, ": command not found\n", 20);
	}
	else
		perror(str);
	return (1);
}

int	cd_error(int e_no, char *str)
{
	write(2, "minish: cd: ", 12);
	write(2, str, ft_strlen(str));
	if (e_no == HOME_NOT_SET)
		write(2, ": HOME not set\n", 15);
	if (e_no == OLDPWD_NOT_SET)
		write(2, ": OLDPWD not set\n", 17);
	if (e_no == CD_NADIR)
		write(2, ": Not a directory\n", 18);
	return (1);
}

int	exit_error(int e_no, char *str)
{
	write(2, "minish: exit: ", 14);
	write(2, str, ft_strlen(str));
	if (e_no == EXIT_TOO_MANY)
		write(2, ": too many arguments\n", 21);
	if (e_no == EXIT_NUM)
		write(2, ": numeric argument required\n", 28);
	return (1);
}
