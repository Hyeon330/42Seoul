/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:01:55 by eoh               #+#    #+#             */
/*   Updated: 2023/07/15 22:05:32 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_redirection(char **splited, int i)
{
	if (splited[i] != NULL && check_redirection(splited[i]) == -1)
		syntax_word(splited, ++i);
	else
		error("no word after redirection");
}

void	syntax_word(char **splited, int i)
{
	if (splited[i] == NULL)
		return ;
	else if (check_redirection(splited[i]) != -1)
		syntax_redirection(splited, ++i);
	else
		syntax_word(splited, ++i);
}

void	syntax_check(char **splited, int order)
{
	int	i;

	i = 0;
	if (order != 0 && check_redirection(splited[0]) != -1)
			error("redirection after pipe");//pipe 뒤에 redirection이 오는 것 방지
	if (check_redirection(splited[i]) != -1)
		syntax_redirection(splited, ++i);
	else
		syntax_word(splited, ++i);
}