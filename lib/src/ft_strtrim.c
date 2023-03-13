/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:04:55 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 17:52:34 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ck_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	str_count(char const *s1, char const *set)
{
	size_t	i;
	size_t	last_i;

	last_i = ft_strlen(s1);
	i = -1;
	while (s1[++i] && ck_set(s1[i], set))
		;
	if (i == last_i)
		return (0);
	while (s1[--last_i] && ck_set(s1[last_i], set))
		;
	return (last_i - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pc;
	size_t	pc_len;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	pc_len = str_count(s1, set);
	pc = (char *)malloc(sizeof(char) * (pc_len + 1));
	if (!pc)
		return (NULL);
	i = 0;
	while (ck_set(s1[i], set))
		i++;
	j = 0;
	while (j < pc_len)
		pc[j++] = s1[i++];
	pc[j] = 0;
	return (pc);
}
