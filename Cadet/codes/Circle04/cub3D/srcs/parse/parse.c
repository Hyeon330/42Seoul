/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:37 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/10/05 23:03:20 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse(t_ray *data, char *file)
{
	char	*line;
	int		fd;

	chk_extension(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		prs_err(PRS_OPEN);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == ' ' || line[0] == '1')
		{
			set_map(data, fd, line);
			break ;
		}
		if (line[0] != '\n')
			set_id(data, line);
		free(line);
	}
	free(line);
	chk_id(data);
	chk_map(data);
}
