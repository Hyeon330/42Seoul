/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:37:35 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/12 18:37:57 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	app_size(ssize_t buf_i, t_buflst *buflst)
{
	ssize_t	cnt;

	cnt = 0;
	while (buf_i < buflst->read_size && (buflst->buf)[buf_i] != '\n')
	{
		buf_i++;
		cnt++;
	}
	if (buf_i != buflst->read_size && (buflst->buf)[buf_i] == '\n')
	{
		buf_i++;
		cnt++;
	}
	return (cnt);
}

int	app_buf(t_buflst **buflst_f, t_buflst *buflst, \
		char **line, ssize_t *line_size)
{
	ssize_t		app_tmp;

	app_tmp = app_size(buflst->buf_i, buflst);
	ft_strjoin(line, buflst->buf + buflst->buf_i, *line_size, app_tmp);
	if (!(*line))
	{
		lstdelone(buflst_f, *buflst_f, buflst->fd);
		return (1);
	}
	buflst->buf_i += app_tmp;
	*line_size += app_tmp;
	if (buflst->buf[buflst->buf_i - 1] == '\n')
	{
		if (buflst->buf_i == buflst->read_size)
			lstdelone(buflst_f, *buflst_f, buflst->fd);
		return (1);
	}
	return (0);
}

int	isloop(t_buflst *buflst, char **line, int fd)
{
	buflst->read_size = read(fd, buflst->buf, BUFFER_SIZE);
	if (buflst->read_size < 0)
	{
		FREE(*line);
		return (0);
	}
	return (buflst->read_size);
}

char	*read_line(t_buflst **buflst_f, t_buflst **buflst, int fd)
{
	ssize_t	line_size;
	char	*line;

	line_size = 0;
	line = NULL;
	if (*buflst)
	{
		if (app_buf(buflst_f, *buflst, &line, &line_size))
			return (line);
	}
	else
	{
		*buflst = lstnew(fd);
		if (!(*buflst))
			return (0);
		lstadd_back(buflst_f, *buflst);
	}
	while (isloop(*buflst, &line, fd))
	{
		(*buflst)->buf_i = 0;
		if (app_buf(buflst_f, *buflst, &line, &line_size))
			return (line);
	}
	lstdelone(buflst_f, *buflst_f, fd);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buflst	*buflst;
	t_buflst		*eq_fd;

	eq_fd = isfd(buflst, fd);
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
	{
		if (eq_fd)
			lstdelone(&buflst, buflst, fd);
		return (NULL);
	}
	return (read_line(&buflst, &eq_fd, fd));
}
