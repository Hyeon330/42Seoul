/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:49:08 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/20 12:13:17 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_real_info_file(t_info *tif, char *file, int *index)
{
	int	fd;
	int	size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	size = 3000;
	tif -> buf = (char *)malloc(sizeof(char) * size);
	read(fd, tif -> buf, size);
	tif -> row = max_y_len(tif, index);
	tif -> col = max_x_len(tif, ++(*index));
	free(tif -> buf);
	close(fd);
	size = tif -> row * (tif -> col + 1) + *index;
	tif -> buf = (char *)malloc(sizeof(char) * (size + 1));
	fd = open(file, O_RDONLY);
	read(fd, tif -> buf, size);
	close(fd);
	return (1);
}

void	get_real_info_input(t_info *tif, int *index)
{
	tif -> row = max_y_len(tif, index);
	tif -> col = max_x_len(tif, ++(*index));
}
