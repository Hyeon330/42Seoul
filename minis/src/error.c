/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:22:49 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/11 05:24:13 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// "minish: "
char	*set_err_msg(t_cmd *cmd)
{
	char	*str;
	int		path_len;
	int		av_len;
	int		str_len;
	int		i;

	path_len = ft_strlen(cmd->path);
	av_len = ft_strlen(cmd->av[1]);
	str_len = 8 + path_len + ((av_len && 1) * 2) + av_len + 1;
	str = (char *)malloc(sizeof(char) * str_len);
	if (!str)
		ft_error(DYNAMIC);
	str[str_len] = 0;

	return (NULL);
}

void	ft_error(int e_no)
{
	char		*msg;

	msg = NULL;
	if (e_no == DYNAMIC)
		msg = "Dynamic allocation error.\n";
	if (e_no == OPEN)
		
	while (*msg)
		write(2, msg++, 1);
	exit(EXIT_FAILURE);
}

// cd fdsa
// path = cd
// argv[0] = cd, argv[1] = fdsa

// < fdsa
// path fdsa