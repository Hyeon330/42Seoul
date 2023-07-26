/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:08:53 by eoh               #+#    #+#             */
/*   Updated: 2023/07/26 22:52:31 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_redir(char *s, int i)
{
	char	redir;

	redir = s[i];
	if (s[i + 1] == '<' || s[i + 1] == '>')
	{
		if (s[i + 1] != redir)
			error("no words after redirection");
		else
			return (i + 1);
	}
	return (i);
}

int	count_quote(char *s, int i, t_vars *vars)
{
	char	quote;
	int		end;

	quote = s[i];
	end = -1;
	i++;
	while (s[i])
	{
		if (s[i] == quote)
		{
			end = i;
			break ;
		}
		i++;
	}
	if (end == -1)
	{
		error_parse(258, vars);
		return (-2);
	}
	else
		return (end);
}

int	count_env(char *s)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == '$' && (s[i + 1] == '?' || \
		s[i + 1] != '\0' || \
		s[i + 1] < 9 || s[i + 1] > 13 || s[i + 1] != 32))
			cnt++;
		i++;
	}
	return (cnt);
}

int	count_token(char *s, char c, t_vars *vars)
{
	int	cnt;
	int	i;

	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] == 34 || s[i] == 39 || s[i] == '<' || s[i] == '>')
		{
			if (s[i] == 34 || s[i] == 39)
			{
				i = count_quote(s, i, vars);
				if (i == -1)
					return (-1);
			}
			else
				i = count_redir(s, i);
			cnt++;
			continue ;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0' || s[i + 1] == '>' \
		|| s[i + 1] == '<' || s[i + 1] == 34 || s[i + 1] == 39))
			cnt++;
	}
	return (cnt);
}
