/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:30:06 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 17:52:46 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	fill_pc_substr(char *pc, char const *s, unsigned int pc_size)
{
	unsigned int	i;

	i = -1;
	while (++i < pc_size)
		pc[i] = s[i];
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pc;
	unsigned int	pc_size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	pc_size = 0;
	while (s[start + pc_size] && (size_t)pc_size < len)
		pc_size++;
	pc = (char *)malloc(sizeof(char) * (pc_size + 1));
	if (!pc)
		return (NULL);
	pc[pc_size] = 0;
	fill_pc_substr(pc, s + start, pc_size);
	return (pc);
}
