/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:11:48 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 16:51:41 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid_redir(char *s, int cnt, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == 34 || s[i] == 39)
			i = replace_index_quote(s, i) + 1;
		if (s[i] == '<' || s[i] == '>')
		{
			if (cnt == 2 || (c != 0 && c != s[i]))
				return (-1);
			cnt++;
			c = s[i];
		}
		else if ((s[i] < 9 || s[i] > 13) && s[i] != 32)
		{
			cnt = 0;
			c = 0;
		}
	}
	if (cnt != 0 || c != 0)
		return (-1);
	return (1);
}

int	check_valid_pipe(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] == 34 || str[i] == 39)
		{
			i = replace_index_quote(str, i) + 1;
			continue ;
		}
		if (str[i] == '|' && cnt != 0)
			return (-1);
		if (str[i] == '|' && cnt == 0)
			cnt++;
		else
			cnt = 0;
		i++;
	}
	if (cnt != 0)
		return (-1);
	return (1);
}

int	check_valid_quote(char *str)
{
	int		i;
	char	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			if (q == 0)
				q = str[i];
			else if (q == str[i])
				q = 0;
		}
		i++;
	}
	if (q != 0)
		return (-1);
	return (1);
}

int	check_splited_pipe(char **splited_pipe)
{
	int	i;

	i = 0;
	while (splited_pipe[i])
	{
		if (check_only_whitespace(splited_pipe[i]) == 1 || \
		check_valid_redir(splited_pipe[i], 0, 0) == -1)
		{
			free_two_dimen(splited_pipe);
			error_parse(258);
			return (-1);
		}
		i++;
	}
	return (1);
}

char	**check_readline(char *str)
{
	char	**splited_pipe;

	if (check_only_whitespace(str) == 1)
		return (NULL);
	if (str[0] == '|' || \
	check_valid_quote(str) == -1 || check_valid_pipe(str) == -1)
	{
		error_parse(258);
		return (NULL);
	}
	splited_pipe = split_pipe(str);
	if (check_splited_pipe(splited_pipe) == -1)
		return (NULL);
	return (splited_pipe);
}
