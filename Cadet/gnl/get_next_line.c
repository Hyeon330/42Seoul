/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:37:35 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/12 18:36:40 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	app_size(ssize_t buf_i, ssize_t read_size, char *buf)
{
	ssize_t	cnt;

	cnt = 0;
	while (buf_i < read_size && buf[buf_i] != '\n')
	{
		buf_i++;
		cnt++;
	}
	if (buf_i != read_size && buf[buf_i] == '\n')
	{
		buf_i++;
		cnt++;
	}
	return (cnt);
}

int	app_buf(t_buf *buf, char **line, ssize_t *line_size)
{
	ssize_t	app_tmp;

	app_tmp = app_size(buf->buf_i, buf->read_size, buf->buf);
	ft_strjoin(line, buf->buf + buf->buf_i, *line_size, app_tmp);
	if (!(*line))
	{
		FREE(buf->buf);
		return (1);
	}
	buf->buf_i += app_tmp;
	*line_size += app_tmp;
	if (buf->buf[buf->buf_i - 1] == '\n')
	{
		if (buf->buf_i == buf->read_size)
			FREE(buf->buf);
		return (1);
	}
	return (0);
}

int	isloop(t_buf *buf, char **line, int fd)
{
	buf->read_size = read(fd, buf->buf, BUFFER_SIZE);
	if (buf->read_size < 0)
	{
		FREE(*line);
		return (0);
	}
	return (buf->read_size);
}

char	*read_line(t_buf *buf, int fd)
{
	ssize_t			line_size;
	char			*line;

	line_size = 0;
	line = NULL;
	if (buf->buf)
	{
		if (app_buf(buf, &line, &line_size))
			return (line);
	}
	else
	{
		buf->buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf->buf)
			return (NULL);
	}
	while (isloop(buf, &line, fd))
	{
		buf->buf_i = 0;
		if (app_buf(buf, &line, &line_size))
			return (line);
	}
	FREE(buf->buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buf	buf;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
	{
		FREE(buf.buf);
		return (NULL);
	}
	return (read_line(&buf, fd));
}
