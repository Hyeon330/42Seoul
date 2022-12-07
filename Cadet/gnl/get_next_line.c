/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:37:35 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/07 20:44:21 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *dst, char *src, int dst_len, int src_len)
{
	char	*pc;
	int	pc_i;
	int	i;

	pc = (char *)malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!pc)
		return (NULL);
	pc[dst_len + src_len] = 0;
	pc_i = 0;

	i = 0;
	while (i < dst_len)
		pc[pc_i++] = dst[i++];

	i = 0;
	while (i < src_len)
		pc[pc_i++] = src[i++];
	free(dst);
	return (pc);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	static int		buf_i;
	static int		read_size;
	int				buf_start;
	int				line_size;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	line_size = 0;
	line = NULL;
	if (buf)
	{
		buf_start = buf_i;
		while (buf_i < read_size && buf[buf_i] != '\n')
			buf_i++;
		if (buf_i != read_size && buf[buf_i] == '\n')
			buf_i++;
		line = ft_strjoin(line, buf + buf_start, line_size, buf_i - buf_start);
		if (!line)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		line_size = buf_i - buf_start;
		if (buf[buf_i - 1] == '\n')
		{
			if (buf_i == read_size)
			{
				free(buf);
				buf = NULL;
			}
			return (line);
		}
	}
	else
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf)
			return (NULL);
	}
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (!read_size)
		{
			free(buf);
			buf = NULL;
			break ;
		}
		if (read_size < 0)
		{
			free(buf);
			buf = NULL;
			free(line);
			return (NULL);
		}

		buf_i = 0;
		while (buf_i < read_size && buf[buf_i] != '\n')
			buf_i++;
		if (buf_i != read_size && buf[buf_i] == '\n')
			buf_i++;
		
		line = ft_strjoin(line, buf, line_size, buf_i);
		if (!line)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		line_size += buf_i;

		if (buf[buf_i - 1] == '\n')
		{
			if (buf_i == read_size)
			{
				free(buf);
				buf = NULL;
			}
			return (line);
		}
	}
	return (line);
}
