/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:38:25 by eoh               #+#    #+#             */
/*   Updated: 2023/08/02 13:43:16 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote(char	*str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			cnt++;
			i = replace_index_quote(str, i);
		}
		i++;
	}
	return (cnt * 2);
}

char	*remove_quote(char *s, int len)
{
	int		i;
	int		j;
	char	*removed;
	char	q;

	i = 0;
	j = 0;
	q = 0;
	removed = init_char(len);
	while (s[i])
	{
		if ((s[i] == 34 || s[i] == 39) && (q == 0 || s[i] == q))
		{
			if (q == 0)
				q = s[i];
			else if (s[i] == q)
				q = 0;
			i++;
			continue ;
		}
		removed[j] = s[i];
		j++;
		i++;
	}
	return (removed);
}

void	remove_quote_main(char **splited_token)
{
	int		i;
	int		len;
	char	*old;

	i = 0;
	while (splited_token[i])
	{
		if (check_quote(splited_token[i]) != 0)
		{
			old = splited_token[i];
			len = ft_strlen(splited_token[i]) - check_quote(splited_token[i]);
			splited_token[i] = remove_quote(splited_token[i], len);
			free(old);
		}
		i++;
	}
}
