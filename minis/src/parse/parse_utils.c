/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:36:58 by eoh               #+#    #+#             */
/*   Updated: 2023/08/07 20:43:10 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_character2(char c)
{
	int	result;

	result = -1;
	if (c == '?' || (c >= 48 && c <= 57) || \
	(c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		result = 1;
	return (result);
}

int	check_redirection(char *str)
{
	int	len;
	int	flag;

	len = ft_strlen(str);
	flag = -1;
	if (len == 1 && str[0] == '<')
		flag = IN_REDIR;
	if (len == 1 && str[0] == '>')
		flag = OUT_REDIR;
	if (len == 2 && str[0] == '>' && str[1] == '>')
		flag = APPEND;
	if (len == 2 && str[0] == '<' && str[1] == '<')
		flag = HEREDOC;
	return (flag);
}

int	check_only_whitespace(char *str)
{
	int	len;
	int	cnt;
	int	i;

	len = ft_strlen(str);
	cnt = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			cnt++;
		i++;
	}
	if (cnt == len)
		return (1);
	return (-1);
}

int	is_redir(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] != '<')
		return (1);
	if (str[i] == '>' && str[i + 1] != '>')
		return (2);
	if (str[i] == '>' && str[i + 1] == '>')
		return (3);
	if (str[i] == '<' && str[i + 1] == '<')
		return (4);
	return (0);
}

char	*heredoc_join_path(char *file_name)
{
	char	*result;

	result = ft_strjoin("/tmp/", file_name);
	free(file_name);
	return (result);
}
