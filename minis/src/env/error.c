/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:13:43 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/05 18:10:56 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_error(int e_no)
{
	write(2, "minish: ", 8);
	if (e_no == ENV_DYNAMIC)
		write(2, "Dynamic allocation failed\n", 26);
	return (1);
}
