/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_split_pipe2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:41:53 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:41:53 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_pipe_wordcnt_pass_qt(char **s)
{
	if (**s == '\'')
		while (*(++(*s)) && **s != '\'')
			;
	else if (**s == '"')
		while (*(++(*s)) && **s != '"')
			;
}
