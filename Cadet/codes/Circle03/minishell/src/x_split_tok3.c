/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_split_tok3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:41:40 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:41:40 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	split_tok_get_wordlen2_det2(char *s, int **i, char c)
{
	while (s[++(**i)] && s[**i] != c)
		;
	while (s[++(**i)] && s[**i] != ' ' && s[**i] != '<' && s[**i] != '>')
	{
		if (s[**i] == '\'')
		{
			while (s[++(**i)] && s[**i] != '\'')
				;
		}
		else if (s[**i] == '"')
			while (s[++(**i)] && s[**i] != '"')
				;
	}
	return ((**i)--);
}

int	split_tok_get_wordlen2_det(char *s, int *i)
{
	while (s[*i] && s[*i] != ' ' && s[*i] != '<' && s[*i] != '>')
	{
		if (s[*i] == '\'')
			split_tok_get_wordlen2_det2(s, &i, '\'');
		else if (s[*i] == '"')
			split_tok_get_wordlen2_det2(s, &i, '"');
		else
			(*i)++;
	}
	return (*i);
}

int	split_tok_get_wordlen_qt(char *s, int *i, char c)
{
	while (s[++(*i)] && s[*i] != c)
		;
	while (s[++(*i)] && s[*i] != ' ' && s[*i] != '<' && s[*i] != '>')
	{
		if (s[*i] == '\'')
			while (s[++(*i)] && s[*i] != '\'')
				;
		else if (s[*i] == '"')
			while (s[++(*i)] && s[*i] != '"')
				;
	}
	return (*i);
}

int	split_tok_get_wordlen_rdr(char *s, int *i, char c)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
	return (*i);
}
