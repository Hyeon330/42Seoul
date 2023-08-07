/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:03:08 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 17:06:53 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_character(char *str, int i)
{
	if (is_white_space(str[i]) != 1 && (str[i + 1] == '\0' \
		|| is_redir(str, i + 1) != 0 || is_white_space(str[i + 1]) == 1))
		return (1);
	return (0);
}

int	count_token(char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			i = replace_index_quote(str, i);
		if (is_redir(str, i) != 0)
		{
			if (is_redir(str, i) == 3 || is_redir(str, i) == 4)
				i++;
			cnt++;
		}
		else if (is_white_space(str[i]) != 1 && (str[i + 1] == '\0' \
		|| is_redir(str, i + 1) != 0 || is_white_space(str[i + 1]) == 1))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**do_split_token(char *str, int cnt)
{
	char	**splited_token;
	int		i;
	int		j;
	int		start;

	splited_token = init_two_dimension(cnt);
	i = -1;
	j = 0;
	start = -1;
	while (str[++i])
	{
		if (start == -1 && is_white_space(str[i]) != 1)
			start = i;
		if (str[i] == 34 || str[i] == 39)
			i = replace_index_quote(str, i);
		if (is_redir(str, i) != 0 || is_character(str, i) == 1)
		{
			if (is_redir(str, i) == 3 || is_redir(str, i) == 4)
				i++;
				splited_token[j] = ft_substr(str, start, i - start + 1);
			j++;
			start = -1;
		}
	}
	return (splited_token);
}

char	**split_token_main(char *splited_pipe, t_vars *vars)
{
	int		cnt;
	char	**splited_token;

	(void)vars;
	cnt = count_token(splited_pipe);
	splited_token = do_split_token(splited_pipe, cnt);
	replace_new(splited_token, vars);
	return (splited_token);
}
