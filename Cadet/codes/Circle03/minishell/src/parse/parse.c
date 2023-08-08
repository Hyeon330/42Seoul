/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:37:17 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 20:51:47 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_parse(t_vars *vars, char **splited_pipe)
{
	int		i;
	char	**splited_token;
	t_cmd	*tmp;

	i = 0;
	while (splited_pipe[i])
	{
		splited_token = split_token_main(splited_pipe[i], vars);
		if (i == 0)
		{
			vars->token.cmd = tokenize(splited_token);
			tmp = vars->token.cmd;
		}
		else
		{
			tmp->next = tokenize(splited_token);
			tmp = tmp->next;
		}
		i++;
		clear_ppc(splited_token);
		if (!tmp)
			return (-1);
	}
	vars->token.size = i;
	return (1);
}

int	parse(t_vars *vars, char *str)
{
	char	**splited_pipe;

	splited_pipe = check_readline(str);
	if (!splited_pipe)
		return (0);
	if (do_parse(vars, splited_pipe) == -1)
	{
		free_two_dimen(splited_pipe);
		clear_token(&vars->token);
		return (0);
	}	
	free_two_dimen(splited_pipe);
	return (1);
}
