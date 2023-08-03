/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_ioe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:00:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/02 18:42:06 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	std_ioe_backup(void)
{
	dup2(STDIN_FILENO, STDIN_BACK);
	dup2(STDOUT_FILENO, STDOUT_BACK);
	dup2(STDERR_FILENO, STDERR_BACK);
}

void	std_ioe_back(void)
{
	dup2(STDIN_BACK, STDIN_FILENO);
	dup2(STDOUT_BACK, STDOUT_FILENO);
	dup2(STDERR_BACK, STDERR_FILENO);
}
