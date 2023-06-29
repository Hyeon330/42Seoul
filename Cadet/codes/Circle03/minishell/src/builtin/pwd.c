/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:32:46 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 17:59:10 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(t_env *root)
{
	ft_putstr_fd(search(root, "PWD"), STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
