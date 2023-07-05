/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_inout_ctrl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:51:12 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/05 21:52:46 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

std_inout_backup()
{
	dup2(STDIN_FILENO, STDIN_BACK);
	dup2(STDOUT_FILENO, STDOUT_BACK);
	dup2(STDERR_FILENO, STDERR_BACK);
}

std_inout_back()
{
	
}