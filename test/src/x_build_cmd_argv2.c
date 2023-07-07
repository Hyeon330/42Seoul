/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_build_cmd_argv2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:43:19 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:43:19 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_tokcnt(char **tok)
{
	int	i;

	i = 0;
	while (tok[i])
		i++;
	return (i);
}

char	*get_cmd_from_av(char *av0)
{
	if (av0)
		return (ft_strdup(av0));
	else
		return (ft_strdup(""));
}
