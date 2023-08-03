/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:22:39 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 14:22:51 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_av(char **splited_token)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (splited_token[i])
	{
		if (check_redirection(splited_token[i]) == -1)
			cnt++;
		else
			i++;
		i++;
	}
	return (cnt);
}

int	count_rd(char **splited_token)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (splited_token[i])
	{
		if (check_redirection(splited_token[i]) != -1)
		{
			cnt += 2;
			i++;
		}
		i++;
	}
	return (cnt);
}
