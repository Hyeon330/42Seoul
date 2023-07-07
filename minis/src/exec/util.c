/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 03:07:08 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/08 03:52:47 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isdir(char	*path)
{
	struct stat	file_stat;

	// S_IFREG
	return (!stat(path, &file_stat) && (file_stat.st_mode & S_IFDIR));
}

static int key_val(char *str, char **pair, int key_val, int size)
{
	int	i;

	pair[key_val] = (char *)malloc(sizeof(char) * (size + 1));
	if (!pair[key_val])
	{
		free(pair[0]);
		free(pair);
		return (0);
	}
	pair[key_val][size] = 0;
	i = -1;
	while (++i < size)
		pair[key_val][i] = str[i];
    return (1);
}

int	get_pair(char **pair, char *str)
{
	int	key_size;
	int	val_size;

	ft_memset(pair, 0, sizeof(char *) * 2);
	key_size = 0;
	while (str[key_size] && str[key_size] != '=')
		key_size++;
	if (!key_val(str, pair, 0, key_size))
        return (0);
	if (!str[key_size])
		return (pair);
	val_size = 0;
	while (str[key_size + 1 + val_size])
		val_size++;
	if (!key_val(str + key_size + 1, pair, 1, val_size))
        return (0);
	return (1);
}
