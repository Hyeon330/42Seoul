/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:49:44 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 17:04:55 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_split_pipe(char *s)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			i = replace_index_quote(s, i);
		if (s[i] != '|' && (s[i + 1] == '|' || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

int	find_pipe_end(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			i = replace_index_quote(str, i) + 1;
			continue ;
		}
		if (str[i] == '|')
			break ;
		i++;
	}
	return (i);
}

int	find_pipe_start(int end)
{
	int	start;

	if (end == 0)
		start = 0;
	else
		start = end + 1;
	return (start);
}

char	**split_pipe(char *str)
{
	char	**splited_pipe;
	int		start;
	int		end;
	int		j;
	int		cnt;

	start = 0;
	end = 0;
	j = 0;
	cnt = count_split_pipe(str);
	splited_pipe = init_two_dimension(cnt);
	while (j < cnt)
	{
		start = find_pipe_start(end);
		end = find_pipe_end(str, start);
		splited_pipe[j] = ft_substr(str, start, end - start);
		j++;
	}
	return (splited_pipe);
}
