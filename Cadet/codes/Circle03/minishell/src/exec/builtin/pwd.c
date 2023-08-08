/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:32:46 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/08 18:03:32 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char	path[5120];
	char	*chk;

	chk = getcwd(path, 5120);
	ft_putstr_fd(chk, STDOUT_FILENO);
	write(1, "\n", 1);
	return (0);
}
