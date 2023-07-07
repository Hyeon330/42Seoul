/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_split_tok2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:41:40 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:41:40 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_tok_get_wordcnt_qt(char **s, int *wordcnt, char c)
{
	(*wordcnt)++;
	(*s)++;
	while (**s && **s != c)
		(*s)++;
	while (*(++(*s)) && **s != ' ' && **s != '<' && **s != '>')
	{
		if (**s == '\'')
			while (*(++(*s)) && **s != '\'')
				;
		else if (**s == '"')
			while (*(++(*s)) && **s != '"')
				;
	}
}

void	split_tok_get_wordcnt_rdr(char **s, int *wordcnt, char c)
{
	(*wordcnt)++;
	while (**s && **s == c)
		(*s)++;
}

void	split_tok_get_wordcnt_qt2(char ***s, char c)
{
	(**s)++;
	while (***s && ***s != c)
		(**s)++;
	while (*(++(**s)) && ***s != ' ' && ***s != '<' && ***s != '>')
	{
		if (***s == '\'')
		{
			(**s)++;
			while (***s && ***s != '\'')
				(**s)++;
		}
		else if (***s == '"')
		{
			(**s)++;
			while (***s && ***s != '"')
				(**s)++;
		}
	}
}

void	split_tok_get_wordcnt2_det(char **s)
{
	while (**s && **s != ' ' && **s != '<' && **s != '>')
	{
		if (**s == '\'')
			split_tok_get_wordcnt_qt2(&s, '\'');
		else if (**s == '"')
			split_tok_get_wordcnt_qt2(&s, '"');
		else
			(*s)++;
	}
}
