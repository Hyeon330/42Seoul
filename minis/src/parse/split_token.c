/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:16:37 by eoh               #+#    #+#             */
/*   Updated: 2023/07/24 14:36:53 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_splited_token(char **s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		free((s[j]));
		j++;
	}
	free(s);
}

char	*split_quote(char *s)
{
	char	*result;
	char	quote;
	int		end;

	quote = s[0];
	end = 1;
	while (s[end] != quote)
	{
		end++;
	}
	result = ft_substr(s, 1, end - 1);
	return (result);
}

char	**do_split_token(char *s, char **splited, char c, t_vars vars)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 34)
		{
			splited[i] = when_quote(&s);
			if (count_env(splited[i]) != 0)
				splited[i] = \
				replace_character(splited[i], vars, count_env(splited[i]));
			i++;
		}
		else if (*s == 39)
			splited[i++] = when_quote(&s);
		else if (*s == '>' || *s == '<')
			splited[i++] = when_redir(&s);
		else if (*s != c)
			splited[i++] = when_charset(&s, c, vars);
		else
			s++;
	}
	return (splited);
}

char	**split_token_main(char *str, t_vars *vars)
{
	int		cnt;
	char	**splited;

	cnt = count_token(str, ' ', vars);
	if (cnt == -1)
		return (0);
	splited = (char **)malloc(sizeof(char *) * cnt + 1);
	if (!splited)
		error("malloc error");
	splited[cnt] = NULL;
	splited = do_split_token(str, splited, ' ', *vars);
	return (splited);
}
