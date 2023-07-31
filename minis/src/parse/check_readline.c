/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:11:48 by eoh               #+#    #+#             */
/*   Updated: 2023/07/31 17:11:49 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid_redir(char *s)
{
	int	i;
	int	c;
	int	cnt;

	cnt = 0;
	c = 0;
	i = -1;
	while (s[++i])
	{
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
	int	len;
	
	i = 0;
	cnt = 0;
	len = ft_strlen(str);
	while (str[i])
	{
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
	int	i;
	int	double_quote;
	int	single_quote;
	char	q;

	i = 0;
	double_quote = 0;
	single_quote = 0;
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
		return(-1);
	return (1);
}

char	**check_readline(char *str)
{
	char	**splited_pipe;
	int		i;

	i = 0;
	if (check_only_whitespace(str) == 1)
		return (NULL);
	if (check_valid_quote(str) == -1)
		return (NULL);
	if (check_valid_pipe(str) == -1)
		return (NULL);
	splited_pipe = ft_split(str, '|');
	while (splited_pipe[i])
	{
		if (check_only_whitespace(splited_pipe[i]) == 1 || check_valid_redir(splited_pipe[i]) == -1)
		{
			free_two_dimen(splited_pipe);
			return (NULL);
		}
		i++;
	}
	return (splited_pipe);
}