/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:36:32 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 17:01:19 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_two_dimen(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_replace_env(char *front, char *back, char *env)
{
	if (front)
		free(front);
	if (back)
		free(back);
	if (env)
		free(env);
	front = NULL;
	back = NULL;
	env = NULL;
}
