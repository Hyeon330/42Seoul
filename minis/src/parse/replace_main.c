/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:55:20 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 17:44:17 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_character(char *str, t_vars *vars)
{
	char	*new;
	char	*result;

	new = NULL;
	result = NULL;
	if (count_env(str) != 0)
		new = replace_env_main(str, vars, NULL, NULL);
	if (count_wave(str) != 0)
	{
		if (new != NULL)
		{
			result = replace_wave_main(new, vars);
			free(new);
		}
		else
			result = replace_wave_main(str, vars);
	}
	if (result == NULL)
		return (new);
	return (result);
}

char	*replace_character_main(char *str, t_vars *vars)
{
	char	*new;
	char	*result;

	new = NULL;
	result = NULL;
	if (count_env(str) + count_wave(str) + count_env_quote(str) == 0)
		return (NULL);
	if (count_env(str) + count_wave(str) != 0)
		new = replace_character(str, vars);
	if (count_env_quote(str) != 0)
	{
		if (new != NULL)
		{
			result = replace_character_quote(new, vars);
			free(new);
		}
		else
			result = replace_character_quote(str, vars);
	}
	if (result == NULL)
		result = new;
	return (result);
}
