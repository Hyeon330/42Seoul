/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:17:02 by eoh               #+#    #+#             */
/*   Updated: 2023/07/24 20:04:20 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**check_parse_str(char *str, t_vars *vars)
{
	char	**splited_pipe;
	int		i;

	i = 0;
	if (check_only_whitespace(str) == 1)
		return (NULL);
	splited_pipe = ft_split(str, '|');
	if (!splited_pipe)
		error("malloc error");
	while (splited_pipe[i])
	{
		if (check_only_whitespace(splited_pipe[i]) == 1)
		{
			error_parse(258, vars);
			return (NULL);
		}
		i++;
	}
	return (splited_pipe);
}

t_cmd	*do_parse(t_vars *vars, char **splited_pipe)
{
	t_cmd	*cmd;
	t_cmd	*temp;
	char	**splited_cmd;
	int		i;

	i = -1;
	cmd = init_cmd();
	temp = cmd;
	while (splited_pipe[++i])
	{
		splited_cmd = split_token_main(splited_pipe[i], vars);
		if (!splited_cmd)
			return (0);
		if (syntax_check(splited_cmd, i, vars) == 0)
			return (0);
		cmd = tokenize(cmd, splited_cmd);
		if (!splited_pipe[i + 1])
			break ;
		cmd->next = init_cmd();
		cmd = cmd->next;
	}
	free_two_dimen(splited_cmd);
	vars->token.size = i + 1;
	return (temp);
}

int	parse(t_vars *vars, char *str)
{
	t_cmd	*temp;
	char	**splited_pipe;

	splited_pipe = check_parse_str(str, vars);
	if (splited_pipe == NULL)
		return (0);
	temp = do_parse(vars, splited_pipe);
	free_two_dimen(splited_pipe);
	vars->token.cmd = temp;
	return (1);
}
