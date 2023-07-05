/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:37:41 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/05 21:43:32 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_err(int e_no, char *str)
{
	write(2, "minish: ", 8);
	if (e_no == EXEC_OPEN)
		perror(str);
	return (1);
}