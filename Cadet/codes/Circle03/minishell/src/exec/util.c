/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 03:07:08 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/31 20:39:49 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isdir(char *path)
{
	struct stat	file_stat;

	if (!stat(path, &file_stat))
	{
		if (file_stat.st_mode & S_IFDIR)
			return (EXEC_ISDIR);
		return (0);
	}
	return (EXEC_OPEN);
}

static int	key_val(char *str, char ***pair, int key_val, int size)
{
	int	i;

	(*pair)[key_val] = (char *)malloc(sizeof(char) * (size + 1));
	if (!(*pair)[key_val])
	{
		free((*pair)[0]);
		free(*pair);
		return (0);
	}
	(*pair)[key_val][size] = 0;
	i = -1;
	while (++i < size)
		(*pair)[key_val][i] = str[i];
	return (1);
}

char	**get_pair(char *str)
{
	char	**pair;
	int		key_size;
	int		val_size;

	pair = (char **)malloc(sizeof(char *) * 2);
	if (!pair)
		return (NULL);
	ft_memset(pair, 0, sizeof(char *) * 2);
	key_size = 0;
	while (str[key_size] && str[key_size] != '=')
		key_size++;
	if (!key_val(str, &pair, 0, key_size))
		return (NULL);
	if (!str[key_size])
		return (pair);
	val_size = 0;
	while (str[key_size + 1 + val_size])
		val_size++;
	if (!key_val(str + key_size + 1, &pair, 1, val_size))
		return (NULL);
	return (pair);
}

int	chk_pair(char *str1, char *str2)
{
	if (!str1 || !str2)
	{
		free(str1);
		return (1);
	}
	return (0);
}

char	*strjoin_between_char(char *str1, char *str2, char c)
{
	char	*ret;
	int		s_str1;
	int		s_tot;
	int		i;

	s_str1 = ft_strlen(str1);
	s_tot = s_str1 + ft_strlen(str2) + 1;
	ret = (char *)malloc(sizeof(char) * (s_tot + 1));
	if (!ret)
		return (NULL);
	ret[s_str1] = c;
	ret[s_tot] = 0;
	i = -1;
	while (++i < s_str1)
		ret[i] = *str1++;
	while (++i < s_tot)
		ret[i] = *str2++;
	return (ret);
}
