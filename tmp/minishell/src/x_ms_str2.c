/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ms_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:42:57 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/03 11:42:57 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strjoinchar(char const *str, char c)
{
	char	*newstr;
	int		i;
	int		len;

	if (!str || !c)
		return (NULL);
	len = ft_strlen(str);
	newstr = ft_calloc(len + 2, 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = c;
	return (newstr);
}

char	*strjoinchar_free(char *str, char c)
{
	char	*newstr;

	newstr = strjoinchar(str, c);
	if (!newstr)
		return (NULL);
	free_ptr(str);
	return (newstr);
}

char	*strjoin_free(char *s1, char *s2, bool free_both)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = ft_strjoin(s1, s2);
	free(s1);
	s1 = NULL;
	if (free_both)
	{
		free(s2);
		s2 = NULL;
	}
	if (!new)
		return (NULL);
	return (new);
}
