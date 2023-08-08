/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:36:16 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 13:36:18 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_parse(int error)
{
	if (error == 258)
		write(2, "syntax error\n", 14);
	g_exit_code = error;
	return (0);
}

void	error(char *msg)
{
	perror(msg);
	exit(1);
}
