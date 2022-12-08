/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:31:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/08 21:00:35 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define FREE(ptr) if (ptr) { free(ptr); ptr = NULL; }

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buf {
	ssize_t	buf_i;
	ssize_t	read_size;
	char	*buf;
}	t_buf;

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
void	ft_strjoin(char **dst, char *src, ssize_t dst_len, ssize_t src_len);

#endif
