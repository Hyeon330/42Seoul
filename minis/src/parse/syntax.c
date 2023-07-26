/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:01:55 by eoh               #+#    #+#             */
/*   Updated: 2023/07/24 00:25:35 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_redirection(char **splited, int i, t_vars *vars)
{
	if (splited[i] == NULL)
		return (error_parse(258, vars));
	if (splited[i] != NULL && check_redirection(splited[i]) == -1)
	{
		if (syntax_word(splited, ++i, vars) == 0)
			return (0);
	}
	else
		return (error_parse(258, vars));
	return (1);
}

int	syntax_word(char **splited, int i, t_vars *vars)
{
	if (splited[i] == NULL)
		return (1);
	else if (check_redirection(splited[i]) != -1)
	{
		if (syntax_redirection(splited, ++i, vars) == 0)
			return (0);
	}
	else
	{
		if (syntax_word(splited, ++i, vars) == 0)
			return (0);
	}
	return (1);
}

int	syntax_check(char **splited, int order, t_vars *vars)
{
	int	i;

	i = 0;
	if (order == -1)
		return (1);
	if (check_redirection(splited[i]) != -1)
	{
		if (syntax_redirection(splited, ++i, vars) == 0)
			return (0);
	}
	else
		if (syntax_word(splited, ++i, vars) == 0)
			return (0);
	return (1);
}
