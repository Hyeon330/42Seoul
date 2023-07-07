/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:10:54 by eoh               #+#    #+#             */
/*   Updated: 2023/07/06 18:04:09 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quote(char *str)
{
	char	quote;

	quote = *str;
	while (*str)
	{
		if (*str == quote)
			return (1);
		str++;
	}
	error("wrong quote");
	return (-1);
}

int	count_redirection(char *str)
{
	char	redir;

	redir = *str;
	if (*(str + 1) == '<' || *(str + 1) == '>')
	{
		if (*(str + 1) != redir)
			error("no words after redirection");
		str++;
		return (1);
	}
	else if(*(str + 1) == '|')
		error("no words aftr redirection");
	else
	{
		str++;
		return (1);
	}
}

int	count_token(char *str)
{
	char	*temp;
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;

	while (*temp)
	{
		if (*temp == 34 || *temp == 39)
			cnt += count_quote(temp);
		if (*temp != ' ' && (*(temp + 1) == ' ' || *(temp + 1) == '\0'))//*temp + 1맞는 방법인지 확인하기
			cnt++;
		if (*temp == '<' || *temp == '>')
			cnt += count_redirection(temp);
		temp++;
	}
	return (cnt);
}

char	*split_quote(char *s)
{
	char	*result;
	int		end;

	end = 1;
	while (s[end] != s[0])
	{
		end++;
	}
	result = ft_substr(s, 1, end - 1);
	s += end +1;
	return (result);
}//맞는지 확인하기

char	*split_redirection(char *s)
{
	char	*result;

	if (*(s + 1) == *s)
	{
		result = ft_substr(s, 0, 1);
		s += 2;
	}
	else
	{
		result[0] = *s;
		result[1] = '\0';
		s++;
	}
	return (result);
}

char	*split_blank(char *s)
{
	char	*tmp;
	char	*result;

	tmp = *s;
	while (*s && *s != ' ')
		*s += 1;
	result = (char *)malloc(sizeof(char) * (s - tmp + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, tmp, s - tmp + 1);
	return (result);
}

void	split_token(char **splited, char *s, int cnt)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
			splited[i++] = split_quote(s);
		else if (*s == '<' || *s == '>')
			splited[i++] = split_redirection(s);
		else if (*s != ' ')
			splited[i++] = split_blank(s);
		else
			s++;
	}
}

char	**split_token_main(char *str)
{
	int		cnt;
	char	**splited;

	cnt = count_token(str);
	splited = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!splited)
		error("malloc error");
	splited[cnt] = NULL;
	split_token(splited, str, cnt);
	return (splited);
}